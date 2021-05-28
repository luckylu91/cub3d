/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_lives.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:24:40 by lzins             #+#    #+#             */
/*   Updated: 2021/03/03 14:39:19 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "engine.h"

static t_img	*heart_img_from_i(t_pack *p, int i)
{
	t_img *im;

	if (i < p->lives)
		im = &p->heart_img;
	else if (i == p->lives)
	{
		if (fmod(p->time_invul, TIME_BEEP_LIFE) > TIME_BEEP_LIFE / 2)
			im = &p->heart_img;
		else
			im = &p->heart_empty_img;
	}
	else
		im = &p->heart_empty_img;
	return (im);
}

void			render_lives(t_pack *p)
{
	t_ipt2d	lives_origin;
	int		life_width;
	int		i;
	t_img	*im;

	life_width = p->width * .1;
	lives_origin = ipt2d(
		p->width - (1 + p->lives_max) * life_width,
		.1 * p->height);
	i = -1;
	while (++i < p->lives_max)
	{
		im = heart_img_from_i(p, i);
		lives_origin.x += life_width;
		draw_rect_image(buff_img(p), im, lives_origin, life_width);
	}
}
