/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_peas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:59:36 by lzins             #+#    #+#             */
/*   Updated: 2021/03/03 14:42:37 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minimap.h"

void	draw_mini_pea(t_pack *p, t_ipt2d coord)
{
	t_ipt2d	offsets;
	t_pt2d	im_coord;
	int		size;

	offsets.x = p->mini.ulx + coord.x * p->mini.block_size;
	offsets.y = p->mini.uly + coord.y * p->mini.block_size;
	size = p->mini.block_size;
	im_coord.x = -1;
	while (++im_coord.x < size)
	{
		im_coord.y = -1;
		while (++im_coord.y < size)
		{
			if (sqnorm(im_coord.x - size / 2, im_coord.y - size / 2)
					<= size * size * .25 / 4.)
				color_pix(
					buff_img(p),
					im_coord.x + offsets.x,
					im_coord.y + offsets.y,
					0X00FFE132);
		}
	}
}
