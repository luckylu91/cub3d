/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_objects_init_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:27:02 by lzins             #+#    #+#             */
/*   Updated: 2021/03/02 11:49:34 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "map_objects_init.h"

int			addback_sprite(t_list **asprites, t_sprite *new_val)
{
	t_list		*new_elem;

	if (!(new_elem = ft_lstnew(new_val)))
		return (-1);
	ft_lstadd_back(asprites, new_elem);
	return (1);
}

void		set_theta_pos(t_pack *p, int i, int j)
{
	p->pos.x = i + .5;
	p->pos.y = j + .5;
	if (p->map.grid[i][j] == 'N')
		p->theta = M_PI / 2;
	else if (p->map.grid[i][j] == 'S')
		p->theta = -M_PI / 2;
	if (p->map.grid[i][j] == 'W')
		p->theta = M_PI;
	else if (p->map.grid[i][j] == 'E')
		p->theta = 0;
	p->theta_v = 0;
}

void		complete_dir_pos(t_pack *p)
{
	p->dir.x = cos(p->theta);
	p->dir.y = -sin(p->theta);
	p->dir3d.x = cos(p->theta);
	p->dir3d.y = -sin(p->theta);
	p->dir3d.z = 0.;
	p->pos3d.x = p->pos.x;
	p->pos3d.y = p->pos.y;
	p->pos3d.z = 0.5;
	p->dir_ortho.x = sin(p->theta);
	p->dir_ortho.y = cos(p->theta);
}

int			count_tpblocks(t_map *map)
{
	int	i;
	int	j;
	int	n_tpblocks;

	n_tpblocks = 0;
	i = -1;
	while (++i < map->width)
	{
		j = -1;
		while (++j < map->height)
		{
			if (map->grid[i][j] == TELEP)
				n_tpblocks++;
		}
	}
	return (n_tpblocks);
}
