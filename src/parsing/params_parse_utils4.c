/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_parse_utils4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 19:14:07 by lzins             #+#    #+#             */
/*   Updated: 2021/03/02 15:24:08 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "params_parse_utils.h"

int	line_argument(char *line, char **argument)
{
	char	*line_trimmed;
	char	*args_begin;
	int		ret;

	if (!(line_trimmed = ft_strtrim(line, " \t")))
		return (malloc_error());
	args_begin = ft_strskip(line_trimmed, " \t", 0, NULL);
	args_begin = ft_strskip(args_begin, " \t", 1, NULL);
	ret = 1;
	if (!(*argument = ft_strdup(args_begin)))
		ret = -1;
	free(line_trimmed);
	return (ret);
}

int	ft_atoi_maxed(char *str, int max, int *res)
{
	int maxed_out;

	maxed_out = 0;
	*res = 0;
	while (ft_isdigit(*str))
	{
		*res = *res * 10 + (*str - '0');
		str++;
		if (*res > max)
			maxed_out = 1;
	}
	if (*str)
		return (-1);
	if (maxed_out)
	{
		*res = max;
		return (0);
	}
	return (1);
}
