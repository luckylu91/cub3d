/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_pt2d_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:13:30 by lzins             #+#    #+#             */
/*   Updated: 2021/03/01 16:38:12 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pt2d	pt2d(double x, double y)
{
	t_pt2d res;

	res.x = x;
	res.y = y;
	return (res);
}

t_pt2d	add_pt2d(t_pt2d a, t_pt2d b)
{
	return (pt2d(a.x + b.x, a.y + b.y));
}

void	add_pt2d_ptr(t_pt2d *a, t_pt2d b)
{
	a->x += b.x;
	a->y += b.y;
}

void	sub_pt2d_ptr(t_pt2d *a, t_pt2d b)
{
	a->x -= b.x;
	a->y -= b.y;
}

t_pt2d	mult_pt2d(t_pt2d a, double b)
{
	return (pt2d(a.x * b, a.y * b));
}
