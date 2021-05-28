/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:23:29 by lzins             #+#    #+#             */
/*   Updated: 2021/03/03 14:39:25 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "engine.h"

static void	render_column(t_pack *p, int x, t_pt2d *ray_dir, double screen_x)
{
	double	dist;
	t_wall	hit;
	double	dist_ortho;
	int		visible_height;
	int		y;

	if ((dist = ray_march(&p->pos, ray_dir, &p->map, &hit)) >= 0.)
	{
		y = -1;
		while (++y < p->height)
			p->dist_array[x][y] = dist;
		dist_ortho = SCREEN_DIST * dist / norm(SCREEN_DIST, fabs(screen_x));
		visible_height = WALL_SIZE * SCREEN_DIST / dist_ortho * p->width \
			/ SCREEN_WIDTH_SIZE;
		rays_updown(p, ray_dir, x, visible_height);
		col_fill(p, &hit, x, visible_height);
	}
}

void		render_walls(t_pack *p)
{
	int		i;
	t_pt2d	ray_dir;
	double	screen_x;

	i = -p->width / 2 - 1;
	while (++i < (p->width + 1) / 2)
	{
		screen_x = (double)i / (double)p->width * SCREEN_WIDTH_SIZE;
		ray_dir.x = p->dir.x * SCREEN_DIST + screen_x * (-p->dir.y);
		ray_dir.y = p->dir.y * SCREEN_DIST + screen_x * p->dir.x;
		render_column(p, i + p->width / 2, &ray_dir, screen_x);
	}
}
