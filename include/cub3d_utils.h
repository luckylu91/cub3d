/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:54:25 by lzins             #+#    #+#             */
/*   Updated: 2021/03/04 17:23:14 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_UTILS_H
# define CUB3D_UTILS_H

# include "types.h"

void		swap(t_pack *p);
void		reset_clock(t_pack *p);
void		tick(t_pack *p);
t_img		img_from_ptr(void *img, int width, int height);
t_sprite	*sprite_at(t_list *sprite_list);
t_img		*buff_img(t_pack *p);
void		color_pix(t_img *im, int x, int y, unsigned int color);
int			color_pix_transparency(t_img *im, int x, int y, unsigned int color);
int			*get_pix_address(t_img *im, int x, int y);
int			get_pix_color(t_img *im, int x, int y);
t_rect		rect(int x1, int y1, int x2, int y2);
t_rect		rect_from_dims(int x_ul, int y_ul, int w, int h);
void		rect_fill(t_img *im, t_rect rect, int color);
void		rect_fill_offset(t_img *im, t_rect rect, t_ipt2d offset, int color);
void		col_fill(t_pack *p, t_wall *hit, int x, int visible_height);
void		rays_updown(t_pack *p, t_pt2d *ray_dir, int x, int visible_height);
void		sprite_fill(t_pack *p, t_sprite *sprite, t_ipt2d start_size,
							double dist);
int			in_bounds(int val, int max);
int			in_bounds2d(int x, int y, t_map *map);
int			is_tpblock(t_ipt2d block, t_map *map);
int			is_outside_or_wall(char block);
int			is_blocking(int x, int y, t_map *map);
double		sqnorm(double x, double y);
double		sqnorm3d(double x, double y, double z);
double		norm(double x, double y);
int			is_wall(t_map *map, int x, int y);
t_pt2d		pt2d(double x, double y);
t_ipt2d		ipt2d(int x, int y);
t_ipt2d		round_pt2d(t_pt2d pt);
int			ipt2d_equal(t_ipt2d v1, t_ipt2d v2);
t_ipt2d		add_ipt2d(t_ipt2d a, t_ipt2d b);
t_ipt2d		sub_ipt2d(t_ipt2d a, t_ipt2d b);
t_pt2d		add_pt2d(t_pt2d a, t_pt2d b);
void		add_pt2d_ptr(t_pt2d *a, t_pt2d b);
t_pt2d		mult_pt2d(t_pt2d a, double b);
int			nothing_hook(void *nothing);
char		block_at(t_map *map, t_ipt2d coord);
int			iter_four_neighbors(void *data_struct, t_ipt2d coord, void *obj,
								int (*fun)(void*, t_ipt2d, t_ipt2d, void*));
void		rotate3d_packdir(t_pack *p, double dth, double dth_v);
void		rotate(t_pt2d *v, double theta);
void		sub_pt2d_ptr(t_pt2d *a, t_pt2d b);
void		do_nothing(void *content);
void		swap_int(int *a, int *b);
void		draw_rect_image(t_img *win_im, t_img *im, t_ipt2d origin,
								int width);
void		draw_menu_image(t_pack *p, t_img *menu_im);
t_sprite	*sprite_at(t_list *sprite_list);
t_ipt2d		*ipt2d_at(t_list *elem);
t_ipt2d		*path_destination(t_list *path);
void		pop_first(t_list **alst, t_ipt2d *res);
int			addback_ipt2d_once(t_list **alst, t_ipt2d val);

#endif
