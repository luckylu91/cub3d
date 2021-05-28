/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:20:36 by lzins             #+#    #+#             */
/*   Updated: 2021/03/05 16:05:06 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	swap(t_pack *p)
{
	mlx_put_image_to_window(p->mlx, p->win, buff_img(p)->img, 0, 0);
	p->win_buffered = (p->win_buffered + 1) % 2;
}

void	reset_clock(t_pack *p)
{
	p->nanosec = clock_gettime_nsec_np(CLOCK_REALTIME);
}

void	tick(t_pack *p)
{
	p->time_loop = (double)(clock_gettime_nsec_np(CLOCK_REALTIME) - p->nanosec)\
		/ 1000000000L;
	p->time_total += p->time_loop;
	p->time_invul = fmax(p->time_invul - p->time_loop, 0);
	reset_clock(p);
}
