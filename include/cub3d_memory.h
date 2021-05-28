/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_memory.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:04:48 by lzins             #+#    #+#             */
/*   Updated: 2021/03/04 11:29:42 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MEMORY_H
# define CUB3D_MEMORY_H

# include "types.h"

void		free_img(void *mlx, t_img *im);
void		free_sprite(void *sprite_ptr);
void		free_map(t_map *map);
int			free_pack(t_pack *p);
int			free_pack_and_quit(t_pack *p);
void		clear_image(t_img *im);

#endif
