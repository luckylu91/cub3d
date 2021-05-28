/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_coord_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:11:56 by lzins             #+#    #+#             */
/*   Updated: 2021/03/01 16:41:48 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		in_bounds(int val, int max)
{
	return ((0 <= val) && (val < max));
}

int		in_bounds2d(int x, int y, t_map *map)
{
	return ((0 <= x) && (x < map->width) && (0 <= y) && (y < map->height));
}

int		is_tpblock(t_ipt2d block, t_map *map)
{
	return (map->grid[block.x][block.y] == TELEP);
}

int		is_outside_or_wall(char block)
{
	return (block == OUTSIDE || block == WALL);
}

int		is_blocking(int x, int y, t_map *map)
{
	return (map->grid[x][y] == WALL || map->grid[x][y] == TELEP);
}
