/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:54:35 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/10 23:19:41 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_figure		*new_figure(char num)
{
	t_figure	*new;
	int			i;

	if (!(new = (t_figure*)malloc(sizeof(t_figure*))))
		return (NULL);
	new->next = NULL;
	//new->num = num;
	new->figure = (char**)malloc(sizeof(char*) * 4);
	i = 0;
	while (i < 4)
	{
		(new->figure)[i] = ft_strnew(4);
		i++;
	}
	return (new);
}

t_figure			*figure_reader(int fd)
{
	t_figure	*start;
	t_figure	*tmp;
	char		*line;
	int			index;
	int			num;

	start = new_figure('A');
	tmp = start;
	index = 0;
	num = 1;
	while ((get_next_line(fd, &line)))
	{
		if (index == 4)
		{
			tmp->next = new_figure('A' + num);
			tmp = tmp->next;
			index = 0;
			num++;
			continue ;
		}
		ft_strcpy((tmp->figure)[index], line);
		ft_strdel(&line);
		index++;
	}
	return (start);
}
