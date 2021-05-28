/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 19:21:07 by lzins             #+#    #+#             */
/*   Updated: 2021/02/22 20:21:44 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		extension_error(char *path, char *ext)
{
	ft_printf("Error\n");
	ft_printf("File '%s' doesn't have a .%s extension\n", path, ext);
	return (-1);
}

int		check_extension(char *path, char *ext)
{
	char	*last_dot;

	last_dot = ft_strrchr(path, '.');
	if (!last_dot)
		return (-1);
	else if (ft_strcmp(last_dot + 1, ext))
		return (-1);
	return (1);
}
