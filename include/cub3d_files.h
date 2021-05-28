/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_files.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:04:51 by lzins             #+#    #+#             */
/*   Updated: 2021/03/03 15:13:35 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_FILES_H
# define CUB3D_FILES_H

# include "libft.h"
# include "types.h"

int	file_not_found_error(char *fname);
int	file_error(char *fname);
int	file_error_free_lines_pack(t_list *scene_lines, t_pack *p);
int	free_clear_and_error(t_list **alst, char *line);

#endif
