/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:46:47 by lzins             #+#    #+#             */
/*   Updated: 2021/03/03 14:42:43 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minimap.h"

t_ipt2d		mini_offsets_in_win(t_pack *p, t_pt2d pos)
{
	return (ipt2d(
		(int)pos.x * p->mini.block_size + p->mini.ulx,
		(int)pos.y * p->mini.block_size + p->mini.uly));
}

static void	minimap_border(t_pack *p)
{
	rect_fill(buff_img(p), p->mini.rect_border_up, 0X00FFFFFF);
	rect_fill(buff_img(p), p->mini.rect_border_down, 0X00FFFFFF);
	rect_fill(buff_img(p), p->mini.rect_border_left, 0X00FFFFFF);
	rect_fill(buff_img(p), p->mini.rect_border_right, 0X00FFFFFF);
}

void		render_minimap(t_pack *p)
{
	t_ipt2d	coord;

	rect_fill(buff_img(p),
		rect(p->mini.ulx, p->mini.uly, p->mini.lrx, p->mini.lry),
		0X00000000);
	coord.x = -1;
	while (++coord.x < p->map.width)
	{
		coord.y = -1;
		while (++coord.y < p->map.height)
		{
			if (p->map.grid[coord.x][coord.y] == WALL
					|| p->map.grid[coord.x][coord.y] == TELEP)
				draw_mini_wall(p, coord);
			else if (p->map.pea_sprites_grid[coord.x][coord.y])
				draw_mini_pea(p, coord);
		}
	}
	draw_enemies(p);
	draw_pacu(p, p->theta, 0X00F5C352);
	minimap_border(p);
}
