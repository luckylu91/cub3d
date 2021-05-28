/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia_add_neighbors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:39:02 by lzins             #+#    #+#             */
/*   Updated: 2021/03/03 14:45:03 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ia.h"

static void	reevaluate_closest(t_path **pathgrid, t_ipt2d neighbor,
	t_ipt2d *neighbor_min, int *min)
{
	if (*visited_at(pathgrid, neighbor)
			&& (*min == -1 || *dist_at(pathgrid, neighbor) < *min))
	{
		*neighbor_min = neighbor;
		*min = *dist_at(pathgrid, neighbor);
	}
}

int			select_closest_visited_neighbor(t_ipt2d curr, t_map *map,
	t_path **pathgrid)
{
	t_list	*neighbor_lst;
	t_ipt2d	neighbor;
	t_ipt2d	neighbor_min;
	int		min;

	min = -1;
	neighbor_lst = map->neighbors[curr.x][curr.y];
	while (neighbor_lst)
	{
		neighbor = *(t_ipt2d*)(neighbor_lst->content);
		reevaluate_closest(pathgrid, neighbor, &neighbor_min, &min);
		neighbor_lst = neighbor_lst->next;
	}
	if (min == -1)
		return (1);
	if (!path_copy(path_at(pathgrid, neighbor_min), path_at(pathgrid, curr))
			|| !addback_ipt2d_once(steps_at(pathgrid, curr), curr))
		return (0);
	*dist_at(pathgrid, curr) = *dist_at(pathgrid, neighbor_min) + 1;
	return (1);
}

int			add_unvisited_neighbors(t_ipt2d curr, t_map *map, t_path **pathgrid,
	t_list **avisit_fifo)
{
	t_list	*neighbor_lst;
	t_ipt2d	neighbor;
	int		min;

	min = -1;
	neighbor_lst = map->neighbors[curr.x][curr.y];
	while (neighbor_lst)
	{
		neighbor = *(t_ipt2d*)(neighbor_lst->content);
		if (!*visited_at(pathgrid, neighbor)
				&& !addback_ipt2d_once(avisit_fifo, neighbor))
			return (0);
		neighbor_lst = neighbor_lst->next;
	}
	return (1);
}
