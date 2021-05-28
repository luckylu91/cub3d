/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_coord_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:22:34 by lzins             #+#    #+#             */
/*   Updated: 2021/03/01 16:41:48 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	block_at(t_map *map, t_ipt2d coord)
{
	if (!in_bounds2d(coord.x, coord.y, map))
		return (OUTSIDE);
	else
		return (map->grid[coord.x][coord.y]);
}

int		iter_four_neighbors(void *data_struct, t_ipt2d coord, void *obj,
	int (*fun)(void*, t_ipt2d, t_ipt2d, void*))
{
	t_ipt2d	coord2;
	int		axis;
	int		delta;

	axis = -1;
	while (++axis <= 1)
	{
		delta = -1;
		while (delta < 2)
		{
			coord2.x = coord.x + ((axis == 0) ? delta : 0);
			coord2.y = coord.y + ((axis == 1) ? delta : 0);
			if ((*fun)(data_struct, coord, coord2, obj) == 0)
				return (0);
			delta += 2;
		}
	}
	return (1);
}
