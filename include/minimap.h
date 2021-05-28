/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:50:47 by lzins             #+#    #+#             */
/*   Updated: 2021/03/03 14:50:48 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3d.h"
# define COLOR_WALL 0X000E18A2
# define COLOR_PORTAL 0X005EE51B

t_ipt2d	mini_offsets_in_win(t_pack *p, t_pt2d pos);
void	draw_pacu(t_pack *p, double m_angle, unsigned int color);
void	draw_enemies(t_pack *p);
void	draw_mini_wall(t_pack *p, t_ipt2d coord);
void	draw_mini_pea(t_pack *p, t_ipt2d coord);

#endif
