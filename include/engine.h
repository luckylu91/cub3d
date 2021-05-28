/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:35:21 by lzins             #+#    #+#             */
/*   Updated: 2021/03/03 14:35:26 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "cub3d.h"

void	render_walls(t_pack *p);
void	render_sprites(t_pack *p);
void	render_lives(t_pack *p);
void	correct_collision(t_pack *p);
void	teleport(t_pack *p, t_pt2d movement, t_ipt2d tp_in_coord,
					t_wall hit);

#endif
