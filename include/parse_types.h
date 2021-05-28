/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:23:34 by lzins             #+#    #+#             */
/*   Updated: 2021/03/04 17:24:35 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_TYPES_H
# define PARSE_TYPES_H

# include "types.h"

typedef struct	s_parsed_line
{
	int			valid;
	char		*line;
}				t_parsed_line;

typedef int		(*t_parse_fun)(t_pack *p, char *line);

typedef struct	s_parse_option
{
	char		*prefix;
	int			mandatory;
	t_parse_fun	parser;
	t_list		*parsed_lines;
}				t_parse_option;

typedef struct	s_lst_parse_map
{
	t_list		*lst;
	int			map_begun;
	t_list		*first_empty;
	int			found_nonempty;
}				t_lst_parse_map;

#endif
