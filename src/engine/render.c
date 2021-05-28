/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:47:40 by lzins             #+#    #+#             */
/*   Updated: 2021/03/03 14:39:46 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "engine.h"

void	render(t_pack *p)
{
	clear_image(buff_img(p));
	render_walls(p);
	render_sprites(p);
	render_lives(p);
}
