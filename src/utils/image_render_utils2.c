/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_render_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:19:16 by lzins             #+#    #+#             */
/*   Updated: 2021/03/02 10:30:21 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	sprite_size_offsets(t_sprite *sprite, int size_screen, t_pt2d *size,
	t_ipt2d *start)
{
	t_pt2d	offsets;

	size->x = size_screen * sprite->simg->img_ratio.x;
	size->y = size_screen * sprite->simg->img_ratio.y;
	offsets.x = sprite->simg->img_offset.x * \
		(double)(size_screen / sprite->simg->im.width);
	offsets.y = sprite->simg->img_offset.x * \
		(double)(size_screen / sprite->simg->im.height);
	start->x += (size_screen - size->x) / 2 + offsets.x;
	start->y += offsets.y;
}

static void	sprite_ratio(t_sprite *sprite, t_pt2d size, t_pt2d *im_screen_ratio)
{
	im_screen_ratio->x = sprite->simg->im.width / size.x;
	im_screen_ratio->y = sprite->simg->im.height / size.y;
}

void		sprite_fill(t_pack *p, t_sprite *sprite, t_ipt2d start_size,
	double dist)
{
	t_ipt2d	coord;
	t_ipt2d	img_coord;
	t_ipt2d	start;
	t_pt2d	size;
	t_pt2d	im_screen_ratio;

	start = ipt2d(start_size.x, 0);
	sprite_size_offsets(sprite, start_size.y, &size, &start);
	start.y += (p->height - size.y) / 2;
	sprite_ratio(sprite, size, &im_screen_ratio);
	coord.x = max(start.x, 0) - 1;
	while (++coord.x < start.x + size.x && coord.x < p->width)
	{
		img_coord.x = (coord.x - start.x) * im_screen_ratio.x;
		coord.y = max(start.y, 0) - 1;
		while (++coord.y < start.y + size.y && coord.y < p->height)
		{
			if (dist >= p->dist_array[coord.x][coord.y])
				continue;
			img_coord.y = (coord.y - start.y) * im_screen_ratio.y;
			if (color_pix_transparency(buff_img(p), coord.x, coord.y,
					get_pix_color(&sprite->simg->im, img_coord.x, img_coord.y)))
				p->dist_array[coord.x][coord.y] = dist;
		}
	}
}
