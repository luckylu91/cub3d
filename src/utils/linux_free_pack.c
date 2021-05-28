/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux_free_pack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:20:09 by lzins             #+#    #+#             */
/*   Updated: 2021/03/08 14:20:35 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clear_arrays(t_pack *p)
{
	size_t i;

	i = -1;
	while (++i < 6)
	{
		free_img(p->mlx, &p->cube_faces[i]);
		free(p->cube_faces_fnames[i]);
	}
	if (p->sprite_images)
	{
		i = -1;
		while (++i < ft_strlen(SPRITES))
			free_img(p->mlx, &p->sprite_images[i].im);
		free(p->sprite_images);
	}
}

static void	end_mlx(t_pack *p)
{
	if (p->mlx)
	{
		if (p->win)
		{
			if (p->mouse_on)
				mlx_mouse_show(p->mlx, p->win);
			mlx_destroy_window(p->mlx, p->win);
		}
		free(p->mlx);
	}
}

int			free_pack(t_pack *p)
{
	free_img(p->mlx, &p->win_img[0]);
	free_img(p->mlx, &p->win_img[1]);
	free_img(p->mlx, &p->start_screen);
	free_img(p->mlx, &p->victory_screen);
	free_img(p->mlx, &p->lose_screen);
	free_img(p->mlx, &p->heart_img);
	free_img(p->mlx, &p->heart_empty_img);
	free_img(p->mlx, &p->portal_img);
	clear_arrays(p);
	free(p->sprite_fname);
	ft_lstclear(&p->sprites, &free_sprite);
	ft_lstclear(&p->enemies, &do_nothing);
	ft_arrayclear((void**)p->dist_array, p->width);
	free_map(&p->map);
	end_mlx(p);
	return (-1);
}

int			free_pack_and_quit(t_pack *p)
{
	free_pack(p);
	exit(0);
	return (0);
}
