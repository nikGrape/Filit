/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikgrape <nikgrape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:54:35 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/10 00:38:44 by nikgrape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_figure	*figure_reader(int fd)
{
	t_figure *start;
	char	*line;
	int		index;
	int		num;
	
	start = new_figure('A');
	index = 0;
	num = 1;
	while (get_next_line(fd, &line))
	{
		if (index == 4)
		{
			start->next = new_figure('A' + num);
			start = start->next;
			index = 0;
			num++;
			continue ;
		}
		(start->figure)[index] = line;
		index++;
	}
}