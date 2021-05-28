/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:27:53 by lzins             #+#    #+#             */
/*   Updated: 2021/03/08 16:56:55 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parse.h"

static int	handle_parameters(int argc, char **argv)
{
	int scene_fd;

	if ((argc != 2 && argc != 3)
		|| (argc == 3 && ft_strcmp(argv[2], "--save")))
	{
		message_error("Usage : ./pacu path_to_scene.cub [--save]");
		exit(-1);
	}
	if (check_extension(argv[1], "cub") == -1)
	{
		message_error("Given file name doesn't have a .cub extension");
		exit(-1);
	}
	if ((scene_fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_printf("Error\n");
		perror(argv[1]);
		exit(-1);
	}
	return (scene_fd);
}

static void	setup_hooks(t_pack *p)
{
	mlx_expose_hook(p->win, &expose_hook, p);
	mlx_hook(p->win, 17, 0, &free_pack_and_quit, p);
	start_game(p);
}

int			main(int argc, char **argv)
{
	void	*mlx;
	t_pack	p;
	int		scene_fd;

	scene_fd = handle_parameters(argc, argv);
	srand((unsigned int)time(NULL));
	if (!(mlx = mlx_init()))
	{
		message_error("While loading mlx");
		exit(-1);
	}
	if (pack_init(&p, mlx, scene_fd) == -1)
		exit(-1);
	if (argc == 3)
	{
		generate_bmp("result.bmp", &p);
		free_pack_and_quit(&p);
	}
	setup_hooks(&p);
	mlx_loop(p.mlx);
	return (0);
}
