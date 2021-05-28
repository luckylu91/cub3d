/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:54:53 by lzins             #+#    #+#             */
/*   Updated: 2021/03/04 17:27:24 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "libft.h"

typedef struct			s_img
{
	void				*img;
	char				*data;
	int					bpp;
	int					lsize;
	int					endian;
	int					width;
	int					height;
}						t_img;

typedef struct			s_pt2d
{
	double				x;
	double				y;
}						t_pt2d;

typedef struct			s_pt3d
{
	double				x;
	double				y;
	double				z;
}						t_pt3d;

typedef struct			s_ipt2d
{
	int					x;
	int					y;
}						t_ipt2d;

typedef struct			s_rect
{
	t_ipt2d				ul;
	t_ipt2d				lr;
	int					w;
	int					h;
}						t_rect;

typedef struct			s_minidims
{
	int					ulx;
	int					uly;
	int					lrx;
	int					lry;
	int					width;
	int					height;
	int					border;
	t_rect				rect_border_up;
	t_rect				rect_border_down;
	t_rect				rect_border_left;
	t_rect				rect_border_right;
	int					block_size;
}						t_minidims;

typedef struct			s_wall
{
	int					cardinal;
	double				left_right_coef;
	double				up_down_coef;
	t_pt2d				pos;
}						t_wall;

typedef struct			s_sprite_img
{
	t_img				im;
	t_pt2d				img_ratio;
	t_pt2d				img_offset;
}						t_sprite_img;

typedef struct			s_sprite
{
	char				type;
	t_pt2d				pos;
	t_sprite_img		*simg;
	t_list				*path;
	t_ipt2d				previous_block;
}						t_sprite;

typedef struct			s_path
{
	t_list				*steps;
	int					dist;
	int					visited;
}						t_path;

typedef struct			s_tpblock
{
	int					x;
	int					y;
	int					n_exits;
	int					exits[4];
}						t_tpblock;

typedef struct			s_special_blocks_counter
{
	int					n_telep;
	int					n_player_start;
}						t_special_blocks_counter;

typedef struct			s_wrange
{
	int					win_start;
	int					win_stop;
	double				img_f;
}						t_wrange;

typedef struct			s_map
{
	char				**grid;
	t_sprite			***pea_sprites_grid;
	t_list				***neighbors;
	int					width;
	int					height;
	int					peas_count;
	t_tpblock			*tpblocks;
	int					n_tpblocks;
}						t_map;

typedef struct			s_pack
{
	void				*mlx;
	void				*win;
	t_img				win_img[2];
	t_img				start_screen;
	t_img				victory_screen;
	t_img				lose_screen;
	int					game_on;
	int					mouse_on;
	t_minidims			mini;
	int					win_buffered;
	int					width;
	int					height;
	int					key_pressed;
	double				theta;
	double				theta_v;
	t_pt2d				pos;
	t_pt2d				dir;
	t_pt2d				dir_ortho;
	t_pt3d				pos3d;
	t_pt3d				dir3d;
	int					lives;
	int					lives_max;
	double				time_invul;
	int					touched_by_enemy;
	t_map				map;
	double				**dist_array;
	char				*cube_faces_fnames[6];
	int					floor_ceil_are_sprites;
	int					floor_color;
	int					ceil_color;
	t_img				cube_faces[6];
	t_img				portal_img;
	t_img				heart_img;
	t_img				heart_empty_img;
	char				*sprite_fname;
	t_list				*sprites;
	t_list				*enemies;
	t_sprite_img		*sprite_images;
	unsigned long long	nanosec;
	double				time_total;
	double				time_loop;
	double				time_restart;
	int					you_won;
	void				(*redraw_fun)(struct s_pack *p);
}						t_pack;

#endif
