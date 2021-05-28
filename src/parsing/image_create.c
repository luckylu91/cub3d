/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:04:35 by lzins             #+#    #+#             */
/*   Updated: 2021/02/23 14:41:51 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		colored_image(void *mlx, int color, t_img *res)
{
	void *img;

	if (!(img = mlx_new_image(mlx, 1, 1)))
		return (-1);
	*res = img_from_ptr(img, 1, 1);
	color_pix(res, 0, 0, color);
	return (1);
}

int		funky_image(t_pack *p, t_img *im)
{
	void	*img;
	int		x;
	int		y;

	if (!(img = mlx_new_image(p->mlx, 256, 256)))
		return (-1);
	*im = img_from_ptr(img, 256, 256);
	x = -1;
	while (++x < 256)
	{
		y = -1;
		while (++y < 256)
			color_pix(im, x, y, (x << 16) + y);
	}
	return (1);
}

void	pea_image(int size, t_img *im)
{
	t_pt2d	im_coord;

	im_coord.x = -1;
	while (++im_coord.x < size)
	{
		im_coord.y = -1;
		while (++im_coord.y < size)
		{
			if (sqnorm(im_coord.x - size / 2, im_coord.y - size / 2)
					<= size * size * .25)
				color_pix(im, im_coord.x, im_coord.y, 0X00F2F028);
			else
				color_pix(im, im_coord.x, im_coord.y, 0XFF000000);
		}
	}
}
