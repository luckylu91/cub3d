/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_parse_utils3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:14:09 by lzins             #+#    #+#             */
/*   Updated: 2021/02/22 20:28:48 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "params_parse_utils.h"

static int	wrong_path_color_arg_error(char *line)
{
	ft_printf("Error\n");
	ft_printf("Expected : 'funky' || 'path/to/texture.xpm' || 'r,g,b'\n");
	ft_printf("Line : %s\n", line);
	return (-1);
}

static int	parse_fc_text(t_pack *p, char *line, t_img *im, char *fname)
{
	int		ret;
	char	*fname_lower;
	int		i;

	ret = 1;
	if (!(fname_lower = ft_strdup(fname)))
		ret = -1;
	else
	{
		i = -1;
		while (fname_lower[++i])
			fname_lower[i] = ft_tolower(fname_lower[i]);
		if (!ft_strcmp(fname_lower, "funky"))
			ret = funky_image(p, im);
		else
		{
			if (check_extension(fname, "xpm") == -1)
				ret = wrong_path_color_arg_error(line);
			else
				ret = load_image(p, fname, im);
		}
	}
	free(fname_lower);
	return (ret);
}

int			parse_fc(t_pack *p, char *line, t_img *im)
{
	int		color;
	char	*fname;
	int		ret;

	ret = -1;
	if (color_or_text(line, &color, &fname) != -1)
	{
		if (fname)
		{
			ret = parse_fc_text(p, line, im, fname);
			free(fname);
		}
		else
			ret = colored_image(p->mlx, color, im);
	}
	return (ret);
}
