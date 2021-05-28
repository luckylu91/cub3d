/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:49:58 by lzins             #+#    #+#             */
/*   Updated: 2021/03/03 14:50:21 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "cub3d.h"

int		key_press_hook(int kc, t_pack *p);
int		key_release_hook(int kc, t_pack *p);
int		motion_hook(int x, int y, t_pack *p);
int		loop_hook(t_pack *p);
void	handle_movement(t_pack *p);
void	delete_pea(t_pack *p, int x, int y);
void	collect_pea(t_pack *p);
void	assess_victory(t_pack *p);
void	assess_life(t_pack *p);
void	draw(t_pack *p);
int		first_path_update(t_pack *p, t_sprite *enemy, t_list **enemy_elem);
int		later_path_update(t_pack *p, t_sprite *enemy);
int		update_path(t_pack *p, t_sprite *enemy, t_list **enemy_elem);
int		move_all_enemies(t_pack *p);
void	put_start_screen(t_pack *p);
int		key_press_hook_menu(int kc, t_pack *p);
int		loop_hook_menu(t_pack *p);
void	put_end_screen(t_pack *p);
int		key_press_hook_end(int kc, t_pack *p);
int		loop_hook_end(t_pack *p);

#endif
