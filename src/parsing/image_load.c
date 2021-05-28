/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:09:57 by lzins             #+#    #+#             */
/*   Updated: 2021/03/02 11:47:47 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	create_dot_image(t_pack *p, t_sprite_img *res)
{
	void	*img;
	t_img	im;

	if (!(img = mlx_new_image(p->mlx, 400, 400)))
		return (malloc_error());
	im = img_from_ptr(img, 400, 400);
	pea_image(400, &im);
	res->im = im;
	res->img_ratio.x = .2;
	res->img_ratio.y = .2;
	res->img_offset.x = 0.;
	res->img_offset.y = 0.;
	return (1);
}

static int	load_ghost_image(t_pack *p, t_sprite_img *res)
{
	void	*img;
	t_img	im;
	int		w;
	int		h;

	if (!(img = mlx_xpm_file_to_image(p->mlx, p->sprite_fname, &w, &h)))
		return (file_not_found_error(p->sprite_fname));
	im = img_from_ptr(img, w, h);
	res->im = im;
	res->img_ratio.x = 1;
	res->img_ratio.y = 1;
	res->img_offset.x = 0.;
	res->img_offset.y = 0.;
	return (1);
}

int			load_sprite_image(t_pack *p, int type, t_sprite_img *res)
{
	if (type == PEA && create_dot_image(p, res) == -1)
		return (-1);
	if (type == GHOST && load_ghost_image(p, res) == -1)
		return (file_not_found_error(p->sprite_fname));
	return (1);
}
