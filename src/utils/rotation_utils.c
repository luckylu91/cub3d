/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:25:17 by lzins             #+#    #+#             */
/*   Updated: 2021/03/01 16:36:42 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate3d_packdir(t_pack *p, double dth, double dth_v)
{
	p->theta += dth;
	p->theta_v += dth_v;
	p->dir.x = cos(p->theta);
	p->dir.y = -sin(p->theta);
	p->dir_ortho.x = sin(p->theta);
	p->dir_ortho.y = cos(p->theta);
	p->dir3d.x = cos(p->theta) * cos(p->theta_v);
	p->dir3d.y = -sin(p->theta) * cos(p->theta_v);
	p->dir3d.z = sin(p->theta_v);
}

void	rotate(t_pt2d *v, double theta)
{
	v->x = cos(theta) * v->x - sin(theta) * v->y;
	v->y = sin(theta) * v->x + cos(theta) * v->y;
}
