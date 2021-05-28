/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:29:17 by lzins             #+#    #+#             */
/*   Updated: 2021/03/03 14:39:15 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "engine.h"

void			move_and_correct(t_pack *p, t_pt2d movement)
{
	t_wall	hit;
	double	hit_dist;
	double	movement_dist;
	t_ipt2d	hit_coord;

	hit_dist = ray_march(&p->pos, &movement, &p->map, &hit);
	hit_coord = round_pt2d(hit.pos);
	movement_dist = norm(movement.x, movement.y);
	if (movement_dist < hit_dist - EPSILON)
		add_pt2d_ptr(&p->pos, movement);
	else if (block_at(&p->map, hit_coord) != TELEP)
		add_pt2d_ptr(
			&p->pos,
			mult_pt2d(movement, (hit_dist - EPSILON) / movement_dist));
	else
	{
		add_pt2d_ptr(&p->pos, mult_pt2d(movement, hit_dist / movement_dist));
		movement = mult_pt2d(movement,
			(movement_dist - hit_dist) / movement_dist);
		teleport(p, movement, hit_coord, hit);
	}
	correct_collision(p);
}
