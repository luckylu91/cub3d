/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_render_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:09:19 by lzins             #+#    #+#             */
/*   Updated: 2021/03/02 13:56:23 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_yrange(t_pack *p, int visible_height, int img_height,
	t_wrange *yrange)
{
	if (visible_height < p->height)
	{
		yrange->win_start = (p->height - visible_height) / 2;
		yrange->win_stop = p->height - 1 - yrange->win_start;
		yrange->img_f = 0.;
	}
	else
	{
		yrange->win_start = 0;
		yrange->win_stop = p->height - 1;
		yrange->img_f = (double)((visible_height - p->height) / 2) \
			* img_height / visible_height;
	}
}

void		col_fill(t_pack *p, t_wall *hit, int x, int visible_height)
{
	t_img		im;
	int			img_x;
	t_wrange	yrange;
	int			y;
	double		dy;

	if (is_tpblock(round_pt2d(hit->pos), &p->map))
		im = p->portal_img;
	else
		im = p->cube_faces[hit->cardinal];
	img_x = hit->left_right_coef * im.width;
	dy = (double)im.height / (visible_height + 1);
	set_yrange(p, visible_height, im.height, &yrange);
	y = yrange.win_start;
	while (y <= yrange.win_stop)
	{
		color_pix(buff_img(p), x, y, get_pix_color(&im, img_x, yrange.img_f));
		yrange.img_f += dy;
		y++;
	}
}

static void	color_fc_from_hit(t_pack *p, t_ipt2d *win, t_wall *hit)
{
	t_img *imc;
	t_img *imf;

	imc = &p->cube_faces[CEIL];
	imf = &p->cube_faces[FLOOR];
	color_pix(buff_img(p), win->x, win->y,
		get_pix_color(imc,
			hit->left_right_coef * imc->width,
			hit->up_down_coef * imc->height));
	color_pix(buff_img(p), win->x, p->height - 1 - win->y,
		get_pix_color(imf,
			hit->left_right_coef * imf->width,
			hit->up_down_coef * imf->height));
}

void		rays_updown(t_pack *p, t_pt2d *ray_dir, int x, int visible_height)
{
	t_wall	hit;
	t_pt3d	ray_dir3d;
	t_ipt2d	win;

	if (visible_height >= p->height)
		return ;
	ray_dir3d.x = ray_dir->x;
	ray_dir3d.y = ray_dir->y;
	win.x = x;
	win.y = -1;
	while (++win.y <= (p->height - visible_height) / 2)
	{
		ray_dir3d.z = SCREEN_WIDTH_SIZE / p->width * (p->height / 2 - win.y);
		ray_march3d_z(&p->pos3d, &ray_dir3d, &hit);
		color_fc_from_hit(p, &win, &hit);
	}
}
