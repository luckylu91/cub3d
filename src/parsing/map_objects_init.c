/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_objects_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:45:51 by lzins             #+#    #+#             */
/*   Updated: 2021/03/02 13:53:53 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "map_objects_init.h"

int			set_pack_map_properties_re_one(t_pack *p, int i, int j)
{
	t_sprite	*pea_sprite;

	if (ft_strchr("NSWE", p->map.grid[i][j]))
		set_theta_pos(p, i, j);
	else
	{
		if (p->map.grid[i][j] == GHOST && !add_sprite(p, i, j, GHOST))
			return (load_sprite_error(p));
		if (!is_blocking(i, j, &p->map) && p->map.grid[i][j] != OUTSIDE)
		{
			if (!(pea_sprite = add_sprite(p, i, j, PEA)))
				return (load_sprite_error(p));
			p->map.pea_sprites_grid[i][j] = pea_sprite;
			p->map.peas_count++;
		}
	}
	return (1);
}

int			set_pack_map_properties_re(t_pack *p)
{
	int			i;
	int			j;

	p->map.peas_count = 0;
	i = -1;
	while (++i < p->map.width)
	{
		j = -1;
		while (++j < p->map.height)
			if (set_pack_map_properties_re_one(p, i, j) == -1)
				return (-1);
	}
	complete_dir_pos(p);
	return (1);
}

int			set_pack_map_properties_first(t_pack *p)
{
	t_ipt2d		coord;
	int			tp_count;

	p->map.n_tpblocks = count_tpblocks(&p->map);
	if (!(p->map.tpblocks = ft_calloc(p->map.n_tpblocks, sizeof(t_tpblock))))
		return (map_error());
	tp_count = 0;
	coord.x = -1;
	while (++coord.x < p->map.width)
	{
		coord.y = -1;
		while (++coord.y < p->map.height)
		{
			if (block_at(&p->map, coord) == TELEP)
				add_tpblock(&p->map, coord, tp_count++);
		}
	}
	if (set_pack_map_properties_re(p) == -1)
		return (-1);
	return (1);
}
