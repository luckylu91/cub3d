/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:23:10 by lzins             #+#    #+#             */
/*   Updated: 2021/03/02 11:48:45 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_img			img_from_ptr(void *img, int width, int height)
{
	t_img	res;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
	char	*img_addr;

	img_addr = mlx_get_data_addr(img, &bits_per_pixel, &line_size, &endian);
	res.img = img;
	res.data = img_addr;
	res.bpp = bits_per_pixel;
	res.lsize = line_size;
	res.endian = endian;
	res.width = width;
	res.height = height;
	return (res);
}

int				load_image(t_pack *p, char *fname, t_img *res)
{
	void	*img;
	int		w;
	int		h;

	if (!(img = mlx_xpm_file_to_image(
			p->mlx,
			fname,
			&w, &h)))
	{
		ft_printf("Error\n");
		ft_printf("While loading image %s\n", fname);
		perror(NULL);
		return (-1);
	}
	*res = img_from_ptr(img, w, h);
	return (1);
}

t_sprite_img	*sprite_img_from_type(t_pack *p, char type)
{
	char		*sprites_str;

	sprites_str = SPRITES;
	return (p->sprite_images + (ft_strchr(sprites_str, type) - sprites_str));
}
