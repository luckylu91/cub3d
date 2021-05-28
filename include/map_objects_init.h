/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_objects_init.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:43:05 by lzins             #+#    #+#             */
/*   Updated: 2021/03/01 16:29:15 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_OBJECTS_INIT_H
# define MAP_OBJECTS_INIT_H

# include "parse.h"

void		complete_dir_pos(t_pack *p);
int			count_tpblocks(t_map *map);
void		set_theta_pos(t_pack *p, int i, int j);
int			addback_sprite(t_list **asprites, t_sprite *new_val);
t_sprite	*add_sprite(t_pack *p, int i, int j, char type);
void		add_tpblock(t_map *map, t_ipt2d coord, int tp_count);

#endif
