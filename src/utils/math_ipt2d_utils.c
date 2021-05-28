/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_ipt2d_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:13:06 by lzins             #+#    #+#             */
/*   Updated: 2021/03/01 16:36:21 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ipt2d	ipt2d(int x, int y)
{
	t_ipt2d res;

	res.x = x;
	res.y = y;
	return (res);
}

int		ipt2d_equal(t_ipt2d v1, t_ipt2d v2)
{
	return (v1.x == v2.x && v1.y == v2.y);
}

t_ipt2d	add_ipt2d(t_ipt2d a, t_ipt2d b)
{
	return (ipt2d(a.x + b.x, a.y + b.y));
}

t_ipt2d	sub_ipt2d(t_ipt2d a, t_ipt2d b)
{
	return (ipt2d(a.x - b.x, a.y - b.y));
}
