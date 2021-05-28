/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:24:49 by lzins             #+#    #+#             */
/*   Updated: 2021/03/03 14:39:22 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "engine.h"

static int	sprite_dist(t_pack *p, t_list **sprite_lst, double *dist)
{
	t_sprite *sprite;

	sprite = sprite_at(*sprite_lst);
	*dist = (sprite->pos.x - p->pos.x) * p->dir.x \
		+ (sprite->pos.y - p->pos.y) * p->dir.y;
	if (*dist < SCREEN_DIST)
	{
		*sprite_lst = (*sprite_lst)->next;
		return (0);
	}
	return (1);
}

static int	sprite_screen_offset(t_pack *p, t_list **sprite_lst, double dist,
	int *x_start)
{
	t_sprite	*sprite;
	double		dist_ortho;
	double		left;
	double		left_screen;

	sprite = sprite_at(*sprite_lst);
	dist_ortho = (sprite->pos.x - p->pos.x) * -p->dir.y \
		+ (sprite->pos.y - p->pos.y) * p->dir.x;
	if (fabs(dist_ortho / dist) >
		(SCREEN_WIDTH_SIZE + WALL_SIZE) / (2 * SCREEN_DIST))
	{
		*sprite_lst = (*sprite_lst)->next;
		return (0);
	}
	left = WALL_SIZE / 2 - dist_ortho;
	left_screen = left / dist * SCREEN_DIST * p->width;
	*x_start = p->width / 2 - left_screen;
	return (1);
}

void		render_sprites(t_pack *p)
{
	double		dist;
	int			x_start;
	int			size_screen;
	t_list		*sprite_lst;

	sprite_lst = p->sprites;
	while (sprite_lst)
	{
		if (!sprite_dist(p, &sprite_lst, &dist))
			continue;
		if (!sprite_screen_offset(p, &sprite_lst, dist, &x_start))
			continue;
		size_screen = WALL_SIZE / dist * SCREEN_DIST * p->width;
		sprite_fill(p, sprite_at(sprite_lst), ipt2d(x_start, size_screen),
			dist);
		sprite_lst = sprite_lst->next;
	}
}
