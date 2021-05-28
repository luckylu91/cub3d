/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia_algo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:41:33 by lzins             #+#    #+#             */
/*   Updated: 2021/03/03 14:45:07 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ia.h"

int	init_paths(t_map *map, t_sprite *sprite, t_path ***pathgrid_addr,
	t_list **avisit_fifo)
{
	t_ipt2d start;

	if (sprite->path)
		start = *ipt2d_at(sprite->path);
	else
		start = ipt2d((int)sprite->pos.x, (int)sprite->pos.y);
	if (!(*pathgrid_addr =
				(t_path**)ft_array(map->width, map->height, sizeof(t_path)))
			|| !addback_ipt2d_once(avisit_fifo, start)
			|| !addback_ipt2d_once(steps_at(*pathgrid_addr, start), start))
		return (-1);
	*visited_at(*pathgrid_addr, start) = 1;
	return (1);
}

int	explore_paths(t_map *map, t_path **pathgrid,
	t_list **avisit_fifo, t_ipt2d goal)
{
	t_ipt2d	curr;

	while (*avisit_fifo)
	{
		pop_first(avisit_fifo, &curr);
		if (!select_closest_visited_neighbor(curr, map, pathgrid)
				|| !add_unvisited_neighbors(curr, map, pathgrid, avisit_fifo))
			return (-1);
		*visited_at(pathgrid, curr) = 1;
		if (curr.x == goal.x && curr.y == goal.y)
			break ;
	}
	return (1);
}

int	copy_shortest_path(t_sprite *sprite, t_path **pathgrid, t_ipt2d goal)
{
	t_list *copy;

	if (!*steps_at(pathgrid, goal))
		ft_lstclear(&sprite->path, free);
	else
	{
		if (!ft_lstcpy((*steps_at(pathgrid, goal))->next, &copy,
				sizeof(t_ipt2d)))
			return (-1);
		if (sprite->path)
		{
			ft_lstclear(&sprite->path->next, free);
			sprite->path->next = copy;
		}
		else
			sprite->path = copy;
	}
	return (1);
}
