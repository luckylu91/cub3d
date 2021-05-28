/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_render_enemy2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:24:29 by lzins             #+#    #+#             */
/*   Updated: 2021/03/03 14:40:02 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "hooks.h"

int	first_path_update(t_pack *p, t_sprite *enemy, t_list **enemy_elem)
{
	t_list		*dead_ghost;

	if (update_shortest_path(&p->map, enemy, ipt2d(p->pos.x, p->pos.y)) == -1)
		return (-1);
	if (!enemy->path)
	{
		printf("A lonely ghost commited suicide... again.\n");
		dead_ghost = ft_lstremove(&p->enemies, enemy, sizeof(t_sprite));
		*enemy_elem = dead_ghost->next;
		free(dead_ghost);
		dead_ghost = ft_lstremove(&p->sprites, enemy, sizeof(t_sprite));
		free(dead_ghost);
		free_sprite(enemy);
		return (0);
	}
	return (1);
}

int	later_path_update(t_pack *p, t_sprite *enemy)
{
	t_ipt2d	*dest;

	dest = path_destination(enemy->path);
	if (dest->x != (int)p->pos.x || dest->y != (int)p->pos.y)
	{
		if (update_shortest_path(
				&p->map, enemy,
				ipt2d(p->pos.x, p->pos.y)) == -1)
			return (-1);
	}
	return (1);
}

int	update_path(t_pack *p, t_sprite *enemy, t_list **enemy_elem)
{
	if (!enemy->path)
		return (first_path_update(p, enemy, enemy_elem));
	else
		return (later_path_update(p, enemy));
}
