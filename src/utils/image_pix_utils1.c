/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_pix_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:05:08 by lzins             #+#    #+#             */
/*   Updated: 2021/03/02 13:57:08 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		*get_pix_address(t_img *im, int x, int y)
{
	return ((int*)(im->data + x * im->bpp / 8 + y * im->lsize));
}

int		get_pix_color(t_img *im, int x, int y)
{
	return (*(int*)(im->data + x * im->bpp / 8 + y * im->lsize));
}

void	color_pix(t_img *im, int x, int y, unsigned int color)
{
	if (in_bounds(x, im->width) && in_bounds(y, im->height))
		*get_pix_address(im, x, y) = color;
}

int		color_pix_transparency(t_img *im, int x, int y, unsigned int color)
{
	if (!in_bounds(x, im->width) || !in_bounds(y, im->height))
		return (0);
	if (color >> 24 < 30)
	{
		*get_pix_address(im, x, y) = color;
		return (1);
	}
	return (0);
}

void	clear_image(t_img *im)
{
	int x;
	int y;

	x = 0;
	while (x < im->width)
	{
		y = 0;
		while (y < im->height)
		{
			color_pix(im, x, y, 0);
			y++;
		}
		x++;
	}
}
