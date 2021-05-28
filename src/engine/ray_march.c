/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_march.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:46:10 by lzins             #+#    #+#             */
/*   Updated: 2021/03/03 14:39:17 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "engine.h"

static double	ray_march_x(t_pt2d *pos, t_pt2d *dir, t_map *map, t_wall *hit)
{
	int		x_index;
	int		x_incr;
	double	y;

	x_incr = dir->x > 0. ? 1 : -1;
	x_index = dir->x > 0. ? (int)ceil(pos->x) : (int)floor(pos->x);
	hit->cardinal = dir->x > 0. ? WEST : EAST;
	if (dir->x != 0.)
	{
		y = pos->y + ((double)x_index - pos->x) * dir->y / dir->x;
		while (in_bounds2d(x_index + (x_incr - 1) / 2, (int)floor(y), map))
		{
			if (is_blocking(x_index + (x_incr - 1) / 2, (int)floor(y), map))
			{
				hit->left_right_coef = y - floor(y);
				if (dir->x < 0.)
					hit->left_right_coef = 1 - hit->left_right_coef;
				hit->pos = pt2d(x_index + (x_incr - 1) / 2, y);
				return (norm(x_index - pos->x, y - pos->y));
			}
			y += x_incr * dir->y / dir->x;
			x_index += x_incr;
		}
	}
	return (-1.);
}

static double	ray_march_y(t_pt2d *pos, t_pt2d *dir, t_map *map, t_wall *hit)
{
	double	x;
	int		y_index;
	int		y_incr;

	y_incr = dir->y > 0. ? 1 : -1;
	y_index = dir->y > 0. ? (int)ceil(pos->y) : (int)floor(pos->y);
	hit->cardinal = dir->y > 0. ? NORTH : SOUTH;
	if (dir->y != 0.)
	{
		x = pos->x + ((double)y_index - pos->y) * dir->x / dir->y;
		while (in_bounds2d((int)floor(x), y_index + (y_incr - 1) / 2, map))
		{
			if (is_blocking((int)floor(x), y_index + (y_incr - 1) / 2, map))
			{
				hit->left_right_coef = 1 - (x - floor(x));
				if (dir->y < 0.)
					hit->left_right_coef = 1 - hit->left_right_coef;
				hit->pos = pt2d(x, y_index + (y_incr - 1) / 2);
				return (norm(x - pos->x, y_index - pos->y));
			}
			x += y_incr * dir->x / dir->y;
			y_index += y_incr;
		}
	}
	return (-1.);
}

double			ray_march(t_pt2d *pos, t_pt2d *dir, t_map *map, t_wall *hit)
{
	t_wall	hitx;
	t_wall	hity;
	double	distx;
	double	disty;

	distx = ray_march_x(pos, dir, map, &hitx);
	disty = ray_march_y(pos, dir, map, &hity);
	if ((distx >= 0.) && ((distx <= disty) || (disty < 0.)))
	{
		*hit = hitx;
		return (distx);
	}
	if ((disty >= 0.) && ((disty <= distx) || (distx < 0.)))
	{
		*hit = hity;
		return (disty);
	}
	return (-1.);
}

double			ray_march3d_z(t_pt3d *pos, t_pt3d *dir, t_wall *hit)
{
	double	x;
	double	y;
	int		z_index;

	if (dir->z == 0)
		return (-1.);
	z_index = dir->z > 0. ? 1 : 0;
	hit->cardinal = dir->z > 0. ? CEIL : FLOOR;
	x = pos->x + (z_index - pos->z) * dir->x / dir->z;
	y = pos->y + (z_index - pos->z) * dir->y / dir->z;
	hit->left_right_coef = x - floor(x);
	hit->up_down_coef = y - floor(y);
	return (sqnorm3d(x - pos->x, y - pos->y, z_index - pos->z));
}
