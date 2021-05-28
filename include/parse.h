/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:26:51 by lzins             #+#    #+#             */
/*   Updated: 2021/03/04 17:27:35 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub3d.h"
# include "parse_types.h"

t_list			*file_to_list(int fd);
void			free_split(char **splitted);
int				split_error(void);
int				free_split_error(char **splitted);
int				splitlen(char **splitted);
char			**split_and_check_len(char *str, char *delim, int n_fields,
					char *error_message);
int				map_error(void);
int				print_invalid_map_error(t_map *map, int i, int j,
					char *message);
int				new_map(t_list *map_lst, t_pack *p);
int				load_sprite_error(t_pack *p);
int				win_image_error(t_pack *p);
int				load_cubeface_error(t_pack *p, int i);
int				file_not_found_error(char *fname);
int				colored_image(void *mlx, int color, t_img *res);
int				load_sprite_image(t_pack *p, int type, t_sprite_img *res);
int				funky_image(t_pack *p, t_img *im);
void			pea_image(int size, t_img *im);
int				pack_init(t_pack *p, void *mlx, int scene_fd);
int				set_win_elements(t_pack *p);
int				load_image(t_pack *p, char *fname, t_img *res);
t_sprite_img	*sprite_img_from_type(t_pack *p, char type);
int				textual_check(t_list *lst, t_list **map_begin);
int				line_argument(char *line, char **argument);
int				ft_atoi_maxed(char *str, int max, int *res);
int				addback_parse_option(t_list **alst, char *prefix,
					int mandatory, t_parse_fun parser);
int				addback_parsed_line(t_list **alst, int valid, char *line);
void			free_parse_option(void *po_ptr);
t_list			*create_po_list(void);
int				recap_po_errors(t_list *po_lst);
int				parse_line(t_list *po_lst, t_pack *p, char *line);
int				map_check(t_map *map);
int				parse_all(t_list *lines, t_pack *p, t_list **map_begin);
int				init_sprites(t_pack *p);
int				set_win_elements(t_pack *p);
int				load_const_imgs(t_pack *p);

#endif
