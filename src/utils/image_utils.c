/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:07:57 by lzins             #+#    #+#             */
/*   Updated: 2021/03/01 16:10:00 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*buff_img(t_pack *p)
{
	return (&p->win_img[p->win_buffered]);
}

void	draw_img(t_img *dest, t_img *src, t_ipt2d ul_corner)
{
	int dx;
	int dy;

	dx = -1;
	while (++dx < src->width)
	{
		dy = -1;
		while (++dy < src->height)
			color_pix(
				dest,
				ul_corner.x + dx,
				ul_corner.y + dy,
				get_pix_color(src, dx, dy));
	}
}
