/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:59:52 by lzins             #+#    #+#             */
/*   Updated: 2021/03/03 14:42:52 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minimap.h"

static void		wall_neighbor_rect_xconst(t_pack *p, t_ipt2d coord, int delta,
	t_rect *rect)
{
	rect->ul.x = (coord.x + .4) * p->mini.block_size;
	rect->lr.x = (coord.x + .6) * p->mini.block_size;
	if (delta == 1)
	{
		rect->ul.y = (coord.y + .6) * p->mini.block_size;
		rect->lr.y = (coord.y + 1.) * p->mini.block_size;
	}
	else
	{
		rect->ul.y = coord.y * p->mini.block_size;
		rect->lr.y = (coord.y + .4) * p->mini.block_size;
	}
	rect->w = rect->lr.x - rect->ul.x;
	rect->h = rect->lr.y - rect->ul.y;
}

static void		wall_neighbor_rect_yconst(t_pack *p, t_ipt2d coord, int delta,
	t_rect *rect)
{
	rect->ul.y = (coord.y + .4) * p->mini.block_size;
	rect->lr.y = (coord.y + .6) * p->mini.block_size;
	if (delta == 1)
	{
		rect->ul.x = (coord.x + .6) * p->mini.block_size;
		rect->lr.x = (coord.x + 1.) * p->mini.block_size;
	}
	else
	{
		rect->ul.x = coord.x * p->mini.block_size;
		rect->lr.x = (coord.x + .4) * p->mini.block_size;
	}
	rect->w = rect->lr.x - rect->ul.x;
	rect->h = rect->lr.y - rect->ul.y;
}

static int		draw_neighbor_fun(void *pack_ptr, t_ipt2d coord,
	t_ipt2d coord2, void *obj)
{
	int		wall_color;
	t_pack	*p;
	t_rect	rect;

	(void)obj;
	p = (t_pack*)pack_ptr;
	if (!in_bounds2d(coord2.x, coord2.y, &p->map)
			|| !is_blocking(coord2.x, coord2.y, &p->map))
		return (1);
	if (block_at(&p->map, coord) == WALL)
		wall_color = COLOR_WALL;
	else
		wall_color = COLOR_PORTAL;
	coord2 = sub_ipt2d(coord2, coord);
	if (coord2.x == 0)
		wall_neighbor_rect_xconst(p, coord, coord2.y, &rect);
	else
		wall_neighbor_rect_yconst(p, coord, coord2.x, &rect);
	rect_fill_offset(buff_img(p), rect, ipt2d(p->mini.ulx, p->mini.uly),
		wall_color);
	return (1);
}

void			draw_mini_wall(t_pack *p, t_ipt2d coord)
{
	int	wall_color;

	iter_four_neighbors(p, coord, NULL, &draw_neighbor_fun);
	wall_color = (p->map.grid[coord.x][coord.y] == WALL) ?
		COLOR_WALL : COLOR_PORTAL;
	rect_fill(
		buff_img(p),
		rect(p->mini.ulx + (coord.x + .4) * p->mini.block_size,
			p->mini.uly + (coord.y + .4) * p->mini.block_size,
			p->mini.ulx + (coord.x + .6) * p->mini.block_size,
			p->mini.uly + (coord.y + .6) * p->mini.block_size),
		wall_color);
}
