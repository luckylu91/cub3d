/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:54:26 by lzins             #+#    #+#             */
/*   Updated: 2021/03/02 13:52:32 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	parse_params(t_list *lines, t_list *map_begin, t_pack *p)
{
	t_list	*po_lst;
	int		ret;

	if (!(po_lst = create_po_list()))
		return (-1);
	while ((lines != map_begin) && lines)
	{
		if (parse_line(po_lst, p, lines->content) == -1)
		{
			ft_lstclear(&po_lst, &free_parse_option);
			return (-1);
		}
		lines = lines->next;
	}
	ret = recap_po_errors(po_lst);
	ft_lstclear(&po_lst, &free_parse_option);
	return (ret);
}

int			parse_all(t_list *lines, t_pack *p, t_list **map_begin)
{
	if (textual_check(lines, map_begin) == -1
			|| parse_params(lines, *map_begin, p) == -1)
		return (-1);
	return (0);
}
