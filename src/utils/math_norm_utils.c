/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_norm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:12:28 by lzins             #+#    #+#             */
/*   Updated: 2021/03/01 16:37:46 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	sqnorm(double x, double y)
{
	return (x * x + y * y);
}

double	sqnorm3d(double x, double y, double z)
{
	return (x * x + y * y + z * z);
}

double	norm(double x, double y)
{
	return (sqrt(x * x + y * y));
}
