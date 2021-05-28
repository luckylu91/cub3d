/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:57:45 by lzins             #+#    #+#             */
/*   Updated: 2021/03/03 14:58:51 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ia.h"

int		update_shortest_path(t_map *map, t_sprite *sprite, t_ipt2d goal)
{
	t_list	*visit_fifo;
	t_path	**pathgrid;

	if (sprite->path && ipt2d_equal(*ipt2d_at(sprite->path), goal))
		return (1);
	visit_fifo = NULL;
	if (init_paths(map, sprite, &pathgrid, &visit_fifo) == -1
			|| explore_paths(map, pathgrid, &visit_fifo, goal) == -1
			|| copy_shortest_path(sprite, pathgrid, goal) == -1)
		return (free_all_error(map, pathgrid, &visit_fifo));
	clear_path_grid(map, pathgrid);
	ft_lstclear(&visit_fifo, free);
	return (1);
}
