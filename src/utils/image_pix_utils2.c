/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_pix_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:06:56 by lzins             #+#    #+#             */
/*   Updated: 2021/03/01 16:07:14 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_rect	rect(int x1, int y1, int x2, int y2)
{
	t_rect	rect;

	rect.ul.x = x1;
	rect.ul.y = y1;
	rect.lr.x = x2;
	rect.lr.y = y2;
	rect.w = x2 - x1;
	rect.h = y2 - y1;
	return (rect);
}

t_rect	rect_from_dims(int x_ul, int y_ul, int w, int h)
{
	t_rect	rect;

	rect.ul.x = x_ul;
	rect.ul.y = y_ul;
	rect.lr.x = x_ul + w;
	rect.lr.y = y_ul + h;
	rect.w = w;
	rect.h = h;
	return (rect);
}

void	rect_fill(t_img *im, t_rect rect, int color)
{
	int i;
	int j;

	i = rect.ul.x - 1;
	while (++i < rect.lr.x)
	{
		j = rect.ul.y - 1;
		while (++j < rect.lr.y)
			color_pix(im, i, j, color);
	}
}

void	rect_fill_offset(t_img *im, t_rect rect, t_ipt2d offset, int color)
{
	int i;
	int j;

	i = rect.ul.x - 1;
	while (++i < rect.lr.x)
	{
		j = rect.ul.y - 1;
		while (++j < rect.lr.y)
			color_pix(im, i + offset.x, j + offset.y, color);
	}
}
