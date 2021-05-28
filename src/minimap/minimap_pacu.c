/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_pacu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:57:24 by lzins             #+#    #+#             */
/*   Updated: 2021/03/03 14:42:35 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minimap.h"

static void		to_pacu_coord(t_pack *p, t_ipt2d delta, double m_angle,
	t_pt2d *pacu_coord)
{
	pacu_coord->x = (delta.x - p->mini.block_size / 2.) * cos(m_angle)
		- (delta.y - p->mini.block_size / 2.) * sin(m_angle);
	pacu_coord->y = (delta.x - p->mini.block_size / 2.) * sin(m_angle)
		+ (delta.y - p->mini.block_size / 2.) * cos(m_angle);
}

static int		in_pacu_area(t_pack *p, t_pt2d pacu_coord, double m_open)
{
	double	rayon;
	double	rayon_block;
	int		not_in_cone;

	rayon = sqnorm(pacu_coord.x, pacu_coord.y);
	rayon_block = pow(p->mini.block_size, 2) / 4;
	not_in_cone = (pacu_coord.x < 0)
		|| fabs(pacu_coord.y) >= sin(m_open) * pacu_coord.x;
	return (rayon <= rayon_block && not_in_cone);
}

void			draw_pacu(t_pack *p, double m_angle, unsigned int color)
{
	t_ipt2d	delta;
	t_pt2d	pacu_coord;
	t_ipt2d	offsets;
	double	m_open;

	m_open = M_PI / 4 * pow(cos(5 * p->time_total), 2);
	offsets = mini_offsets_in_win(p, p->pos);
	delta.x = -1;
	while (++delta.x < p->mini.block_size)
	{
		delta.y = -1;
		while (++delta.y < p->mini.block_size)
		{
			to_pacu_coord(p, delta, m_angle, &pacu_coord);
			if (in_pacu_area(p, pacu_coord, m_open))
				color_pix(buff_img(p), delta.x + offsets.x,
					delta.y + offsets.y, color);
		}
	}
}
