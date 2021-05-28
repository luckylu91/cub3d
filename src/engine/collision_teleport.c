/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_teleport.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:53:57 by lzins             #+#    #+#             */
/*   Updated: 2021/03/03 14:39:12 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "engine.h"

static int		card_ord(int cardinal)
{
	if (cardinal == WEST)
		return (0);
	else if (cardinal == NORTH)
		return (1);
	else if (cardinal == EAST)
		return (2);
	else
		return (3);
}

static t_pt2d	exit_point(t_ipt2d coord, int cardinal, double lr_coef,
	double eject_dist)
{
	eject_dist = fmin(eject_dist, TP_EJECT_DIST_MAX);
	if (cardinal == WEST)
		return (pt2d(coord.x - eject_dist, coord.y + lr_coef));
	else if (cardinal == NORTH)
		return (pt2d(coord.x + 1 - lr_coef, coord.y - eject_dist));
	else if (cardinal == EAST)
		return (pt2d(coord.x + 1. + eject_dist, coord.y + 1 - lr_coef));
	else
		return (pt2d(coord.x + lr_coef, coord.y + 1. + eject_dist));
}

static void		change_direction(t_pack *p, int card_in, int card_out)
{
	int			delta_card;
	double		theta;

	delta_card = (card_ord(card_out) - card_ord(card_in) + 6) % 4;
	theta = M_PI / 2 * delta_card;
	rotate3d_packdir(p, theta, 0);
}

void			teleport(t_pack *p, t_pt2d movement, t_ipt2d tp_in_coord,
	t_wall hit)
{
	t_tpblock	*tp;
	int			i_dest;
	int			i;
	int			i_exit;
	int			cardinal_out;

	i_dest = rand() % (p->map.n_tpblocks - 1);
	i = -1;
	while (++i < p->map.n_tpblocks)
	{
		tp = p->map.tpblocks + i;
		if (tp->x == tp_in_coord.x && tp->y == tp_in_coord.y)
			i_dest++;
		if (i == i_dest)
			break ;
	}
	i_exit = rand() % tp->n_exits;
	cardinal_out = tp->exits[i_exit];
	p->pos = exit_point(ipt2d(tp->x, tp->y),
		cardinal_out, 1 - hit.left_right_coef,
		norm(movement.x, movement.y));
	change_direction(p, hit.cardinal, cardinal_out);
}
