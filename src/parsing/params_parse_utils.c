/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_parse_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:56:31 by lzins             #+#    #+#             */
/*   Updated: 2021/03/04 17:15:53 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "params_parse_utils.h"

static int	check_valid_dimentions(char *line, int w, int h, t_ipt2d atoi_ret)
{
	if (atoi_ret.x == -1 || atoi_ret.y == -1)
	{
		ft_printf("Error\n");
		ft_printf("One resolution value has non-digit character.\n");
		ft_printf("Line : %s\n", line);
		return (-1);
	}
	if (w <= 200 || h <= 200)
	{
		ft_printf("Error\n");
		ft_printf("Unvalid width or height in resolution parsing\n");
		ft_printf("At least 200 pixels are expected for each value\n");
		ft_printf("Got w = %d and h = %d\n", w, h);
		ft_printf("Line : %s\n", line);
		return (-1);
	}
	return (1);
}

static void	caping_dimention(char *field_name, int cap_value, char *val_str)
{
	ft_printf("Caping %s - arbitrarily - to %d (%s was given): "
		"there is no mlx_screen_size in this minilibx "
		"implementation (openGL)\n", field_name, cap_value, val_str);
}

int			parse_resolution(char *line, int *w, int *h)
{
	char	**splitted;
	t_ipt2d	atoi_ret;

	if (!(splitted = split_and_check_len(line, " \t", 3,
			"During resolution-parameter parsing\n")))
		return (-1);
	if ((atoi_ret.x = ft_atoi_maxed(splitted[1], 1920, w)) == 0)
		caping_dimention("WIDTH", 1920, splitted[1]);
	if ((atoi_ret.y = ft_atoi_maxed(splitted[2], 1080, h)) == 0)
		caping_dimention("HEIGHT", 1080, splitted[2]);
	if (check_valid_dimentions(line, *w, *h, atoi_ret) == -1)
		return (free_split_error(splitted));
	free_split(splitted);
	return (0);
}

int			parse_path_load(char *line, t_pack *p, t_img *im)
{
	char	*fname;
	int		ret;

	fname = NULL;
	if (line_argument(line, &fname) == -1)
		ret = -1;
	else
		ret = load_image(p, fname, im);
	free(fname);
	return (ret);
}
