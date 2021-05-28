/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_pt_ipt_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:17:12 by lzins             #+#    #+#             */
/*   Updated: 2021/03/01 16:39:19 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ipt2d	round_pt2d(t_pt2d pt)
{
	return (ipt2d((int)pt.x, (int)pt.y));
}

t_pt2d	pt2d_from_ipt2d(t_ipt2d ipt)
{
	return (pt2d(ipt.x, ipt.y));
}
