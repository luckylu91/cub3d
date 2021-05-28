/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_enemies.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:04:00 by lzins             #+#    #+#             */
/*   Updated: 2021/03/03 14:42:33 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minimap.h"

static void	draw_one_enemy(t_pack *p, t_sprite *sprite)
{
	t_img	sprite_im;
	t_ipt2d	offsets;
	t_ipt2d sprite_coord;
	t_ipt2d	delta;

	sprite_im = sprite->simg->im;
	offsets = mini_offsets_in_win(p, sprite->pos);
	delta.x = -1;
	while (++delta.x < p->mini.block_size)
	{
		delta.y = -1;
		while (++delta.y < p->mini.block_size)
		{
			sprite_coord.x = (delta.x * (double)sprite_im.width
				/ p->mini.block_size);
			sprite_coord.y = (delta.y * (double)sprite_im.height
				/ p->mini.block_size);
			color_pix_transparency(
				buff_img(p),
				offsets.x + delta.x,
				offsets.y + delta.y,
				get_pix_color(&sprite_im, sprite_coord.x, sprite_coord.y));
		}
	}
}

void		draw_enemies(t_pack *p)
{
	t_list		*enemy_lst;
	t_sprite	*enemy;

	enemy_lst = p->enemies;
	while (enemy_lst)
	{
		enemy = (t_sprite*)(enemy_lst->content);
		draw_one_enemy(p, enemy);
		enemy_lst = enemy_lst->next;
	}
}
