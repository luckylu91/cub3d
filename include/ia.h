/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:44:43 by lzins             #+#    #+#             */
/*   Updated: 2021/03/03 14:50:38 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef IA_H
# define IA_H

# include "cub3d.h"

int		select_closest_visited_neighbor(t_ipt2d curr, t_map *map,
											t_path **pathgrid);
int		add_unvisited_neighbors(t_ipt2d curr, t_map *map, t_path **pathgrid,
									t_list **avisit_fifo);
int		init_paths(t_map *map, t_sprite *sprite, t_path ***pathgrid_addr,
	t_list **avisit_fifo);
int		explore_paths(t_map *map, t_path **pathgrid, t_list **avisit_fifo,
					t_ipt2d goal);
int		copy_shortest_path(t_sprite *sprite, t_path **pathgrid, t_ipt2d goal);
int		path_copy(t_path *src, t_path *res);
void	clear_path(t_path *path);
void	clear_path_grid(t_map *map, t_path **pathgrid);
int		free_all_error(t_map *map, t_path **pathgrid, t_list **visit_fifo);
int		*dist_at(t_path **pathgrid, t_ipt2d coord);
int		*visited_at(t_path **pathgrid, t_ipt2d coord);
t_list	**steps_at(t_path **pathgrid, t_ipt2d coord);
t_path	*path_at(t_path **pathgrid, t_ipt2d coord);

#endif
