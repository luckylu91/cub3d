/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_objects_init_utils2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:44:06 by lzins             #+#    #+#             */
/*   Updated: 2021/03/02 13:54:11 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "map_objects_init.h"

t_sprite	*add_sprite(t_pack *p, int i, int j, char type)
{
	t_sprite	*sprite;

	if (!(sprite = ft_calloc(1, sizeof(t_sprite))))
		return (NULL);
	sprite->type = type;
	sprite->pos.x = i + .5;
	sprite->pos.y = j + .5;
	sprite->path = NULL;
	sprite->previous_block.x = i;
	sprite->previous_block.y = j;
	sprite->simg = sprite_img_from_type(p, type);
	if (addback_sprite(&p->sprites, sprite) == -1)
	{
		free(sprite);
		return (NULL);
	}
	if (ft_strchr(ENEMIES, type)
		&& addback_sprite(&p->enemies, sprite) == -1)
	{
		free(sprite);
		return (NULL);
	}
	return (sprite);
}

static int	cardinal_from_ipt2d(t_ipt2d delta)
{
	if (delta.x > 0)
		return (EAST);
	else if (delta.x < 0)
		return (WEST);
	else if (delta.y > 0)
		return (SOUTH);
	else
		return (NORTH);
}

static int	add_one_tpblock_exit(void *map_ptr, t_ipt2d coord, t_ipt2d coord2,
	void *tp_ptr)
{
	t_map		*map;
	t_tpblock	*tp;

	(void)coord;
	map = (t_map*)map_ptr;
	tp = (t_tpblock*)tp_ptr;
	if (!is_outside_or_wall(block_at(map, coord2))
			&& block_at(map, coord2) != TELEP)
	{
		tp->exits[tp->n_exits] = cardinal_from_ipt2d(
				ipt2d(coord2.x - tp->x, coord2.y - tp->y));
		tp->n_exits++;
	}
	return (1);
}

void		add_tpblock(t_map *map, t_ipt2d coord, int tp_count)
{
	t_tpblock *tp;

	tp = map->tpblocks + tp_count;
	tp->x = coord.x;
	tp->y = coord.y;
	tp->n_exits = 0;
	iter_four_neighbors(map, coord, tp, &add_one_tpblock_exit);
}
