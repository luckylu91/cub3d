/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_parse_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:05:49 by lzins             #+#    #+#             */
/*   Updated: 2021/03/02 11:48:09 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "params_parse_utils.h"

static int	trim_split(char **splitted, char ***res)
{
	int	i;

	if (!(*res = ft_calloc(splitlen(splitted) + 1, sizeof(char*))))
		return (-1);
	(*res)[splitlen(splitted)] = NULL;
	i = -1;
	while (splitted[++i])
	{
		if (!((*res)[i] = ft_strtrim(splitted[i], " \t")))
		{
			while (--i >= 0)
				free((*res)[i]);
			free(*res);
			return (-1);
		}
	}
	return (1);
}

static int	all_numbers(char **strs)
{
	int	i;
	int	j;

	i = -1;
	while (strs[++i])
	{
		j = -1;
		while (strs[i][++j])
		{
			if (!ft_isdigit(strs[i][j]))
				return (-1);
		}
	}
	return (1);
}

static int	color_from_split(char *line, char **splitted_color, int *color)
{
	int		rgb[3];
	char	**trimmed_colors;
	int		ret;

	ret = 1;
	if (trim_split(splitted_color, &trimmed_colors) == -1)
		return (malloc_error());
	if (all_numbers(trimmed_colors) == -1)
	{
		message_error("One r/g/b value is invalid");
		ft_printf("Line : %s\n", line);
		ret = -1;
	}
	rgb[0] = ft_atoi(trimmed_colors[0]);
	rgb[1] = ft_atoi(trimmed_colors[1]);
	rgb[2] = ft_atoi(trimmed_colors[2]);
	if (ret == 1 && (rgb[0] > 255 || rgb[1] > 255 || rgb[2] > 255))
	{
		message_error("One r/g/b value is not in 0-255 range");
		ft_printf("Line : %s\n", line);
		ret = -1;
	}
	*color = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
	free_split(trimmed_colors);
	return (ret);
}

int			parse_color(char *line, int *color)
{
	char	**splitted_line;
	char	**splitted_color;
	int		ret;

	if (!(splitted_line = split_and_check_len(line, " ", 2,
			"During color parsing (separating the line)\n")))
		return (-1);
	if (!(splitted_color = split_and_check_len(splitted_line[1], ",", 3,
			"During color parsing (separating the colors)\n")))
		return (free_split_error(splitted_line));
	ret = color_from_split(line, splitted_color, color);
	free_split(splitted_line);
	free_split(splitted_color);
	return (ret);
}

int			color_or_text(char *line, int *color, char **text)
{
	char	**splitted_arg;
	char	*argument;
	int		arg_splitlen;
	int		ret;

	*text = NULL;
	ret = 1;
	if (line_argument(line, &argument) == -1)
		return (-1);
	if (!(splitted_arg = ft_split(argument, ",")))
		ret = split_error();
	else
	{
		arg_splitlen = splitlen(splitted_arg);
		if (arg_splitlen == 1 && !(*text = ft_strdup(argument)))
			ret = malloc_error();
		else if (arg_splitlen == 3)
			ret = color_from_split(line, splitted_arg, color);
	}
	free(argument);
	free_split(splitted_arg);
	return (ret);
}
