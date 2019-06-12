/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:54:35 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/11 19:28:58 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_figure	*new_figure(int size)
{
	t_figure	*new;
	int			i;

	if (!(new = (t_figure*)malloc(sizeof(t_figure))))
		return (NULL);
	new->next = NULL;
	new->size = size;
	new->figure = (char**)malloc(sizeof(char*) * size);
	i = 0;
	while (i < size)
	{
		new->figure[i] = ft_strnew(size);
		i++;
	}
	return (new);
}

t_figure	*figure_reader(int fd)
{
	t_figure	*start;
	t_figure	*tmp;
	char		*line;
	int			index;
	char		name;

	name = 'A';
	start = new_figure(4);
	tmp = start;
	index = 0;
	while ((get_next_line(fd, &line)))
	{
		if (index == 4)
		{
			tmp->name = name++;
			tmp->next = new_figure(4);
			tmp = tmp->next;
			index = 0;
			continue ;
		}
		ft_strcpy(tmp->figure[index++], line);
		ft_strdel(&line);
	}
	tmp->name = name;
	return (start);
}
