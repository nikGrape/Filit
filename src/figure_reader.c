/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:54:35 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/17 17:02:16 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_figure	*new_figure(int size)
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

static int		check_line(t_figure *tmp, char **line, int num, int key)
{
	int len;

	len = ft_strlen(*line);
	if (len != key)
		ft_error(1);
	if (key == 0)
	{
		if (num > 24)
			ft_error(2);
		tmp->num = num;
		tmp->next = new_figure(4);
	}
	ft_strdel(line);
	return (0);
}

t_figure		*figure_reader(int fd)
{
	t_figure	*start;
	t_figure	*tmp;
	char		*line;
	int			index;
	int			num;

	start = new_figure(4);
	tmp = start;
	index = 0;
	num = 0;
	while ((get_next_line(fd, &line)))
	{
		if (index == 4)
		{
			index = check_line(tmp, &line, num++, 0);
			tmp = tmp->next;
			continue ;
		}
		ft_strcpy(tmp->figure[index++], line);
		check_line(tmp, &line, num, 4);
	}
	free(line);
	tmp->num = num;
	return (start);
}
