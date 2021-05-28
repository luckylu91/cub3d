/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_parse_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 19:40:21 by lzins             #+#    #+#             */
/*   Updated: 2021/03/04 17:15:58 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_PARSE_UTILS_H
# define PARAMS_PARSE_UTILS_H

# include "parse.h"

int	parse_resolution(char *line, int *w, int *h);
int	parse_path_load(char *line, t_pack *p, t_img *im);
int	parse_color(char *line, int *color);
int	color_or_text(char *line, int *color, char **text);
int	parse_fc(t_pack *p, char *line, t_img *im);

#endif
