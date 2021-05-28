/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:28:40 by lzins             #+#    #+#             */
/*   Updated: 2021/03/08 14:56:17 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include <math.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <stdint.h>
# include <unistd.h>
# include <fcntl.h>
# include "types.h"
# ifdef USE_LINUX
#  include "keycodes_linux.h"
# else
#  include "keycodes.h"
# endif
# include "symbols_const.h"
# include "values_const.h"
# include "cub3d_utils.h"
# include "cub3d_files.h"
# include "cub3d_memory.h"

void		start_menu(t_pack *p);
void		start_game(t_pack *p);
void		end_game(t_pack *p);
void		restart_game(t_pack *p);
int			expose_hook(t_pack *p);
int			malloc_error(void);
int			parse_error(void);
int			message_error(char *message);
void		move_and_correct(t_pack *p, t_pt2d movement);
double		ray_march(t_pt2d *pos, t_pt2d *dir, t_map *map, t_wall *hit);
double		ray_march3d_z(t_pt3d *pos, t_pt3d *dir, t_wall *hit);
void		render(t_pack *p);
void		render_minimap(t_pack *p);
int			update_shortest_path(t_map *map, t_sprite *sprite, t_ipt2d goal);
int			set_pack_map_properties_re(t_pack *p);
int			set_pack_map_properties_first(t_pack *p);
int			generate_bmp(char *fname, t_pack *p);
int			check_extension(char *path, char *ext);
int			extension_error(char *path, char *ext);

#endif
