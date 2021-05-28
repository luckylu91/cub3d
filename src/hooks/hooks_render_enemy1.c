/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_render_enemy1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:31:45 by lzins             #+#    #+#             */
/*   Updated: 2021/03/03 14:40:00 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "hooks.h"

static void	get_next_block_dist(t_sprite *enemy, t_ipt2d *next_block,
	double *dist_to_block)
{
	*next_block = *ipt2d_at(enemy->path);
	if (next_block->x == enemy->previous_block.x)
		*dist_to_block = fabs(next_block->y + .5 - enemy->pos.y);
	else if (next_block->y == enemy->previous_block.y)
		*dist_to_block = fabs(next_block->x + .5 - enemy->pos.x);
}

static void	move_toward_block(t_sprite *enemy, double dist, t_ipt2d next_block)
{
	if (next_block.x == enemy->previous_block.x)
		enemy->pos.y += dist * ((enemy->pos.y < next_block.y + .5) ? 1 : -1);
	else
		enemy->pos.x += dist * ((enemy->pos.x < next_block.x + .5) ? 1 : -1);
}

static void	move_to_block(t_pack *p, t_sprite *enemy, t_ipt2d next_block)
{
	t_ipt2d block_tp_dest;

	if (is_tpblock(next_block, &p->map)
			&& enemy->path->next
			&& is_tpblock(*ipt2d_at(enemy->path->next), &p->map))
	{
		pop_first(&enemy->path, NULL);
		pop_first(&enemy->path, &block_tp_dest);
		enemy->previous_block = block_tp_dest;
		enemy->pos = pt2d(block_tp_dest.x + .5, block_tp_dest.y + .5);
	}
	else
	{
		pop_first(&enemy->path, NULL);
		enemy->pos = pt2d(next_block.x + .5, next_block.y + .5);
		enemy->previous_block = next_block;
	}
}

static int	move_enemy(t_pack *p, t_sprite *enemy, t_list **enemy_elem)
{
	double	dist;
	double	dist_to_block;
	t_ipt2d	next_block;

	if (ipt2d_equal(round_pt2d(p->pos), round_pt2d(enemy->pos)))
		p->touched_by_enemy = 1;
	else if (update_path(p, enemy, enemy_elem) == -1)
		return (-1);
	dist = p->time_loop * ENEMY_SPEED;
	while (dist > 0. && enemy->path)
	{
		get_next_block_dist(enemy, &next_block, &dist_to_block);
		if (dist < dist_to_block)
		{
			move_toward_block(enemy, dist, next_block);
			dist = 0.;
		}
		else
		{
			move_to_block(p, enemy, next_block);
			dist -= dist_to_block;
		}
	}
	return (1);
}

int			move_all_enemies(t_pack *p)
{
	t_list		*enemy_elem;
	t_sprite	*enemy;
	int			ret_move;

	enemy_elem = p->enemies;
	while (enemy_elem)
	{
		enemy = sprite_at(enemy_elem);
		if ((ret_move = move_enemy(p, enemy, &enemy_elem)) == -1)
			return (-1);
		if (!enemy_elem)
			break ;
		enemy_elem = enemy_elem->next;
	}
	return (1);
}
