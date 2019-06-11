/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:40:14 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/10 20:03:36 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		lineset(char *str, int start, int len)
{
	while (start < len)
		str[start++] = '.';
	str[start] = '\0';
}

char		*new_line(char *str, int size)
{
	char	*new;

	new = ft_strnew(size);
	ft_strcpy(new, str);
	lineset(new, 4, size);
	ft_strdel(&str);
	return (new);
}

void		make_size(t_figure *list, int size)
{
	int i;
	int j;

	while (list != NULL)
	{
		i = 0;
		while (i < 4)
		{
			(list->figure)[i] = new_line((list->figure)[i], size);
			i++;
		}
		while (i < size)
		{
			(list->figure)[i] = ft_strnew(size);
			lineset((list->figure)[i], 0, size);
		}
		list = list->next;
	}
}
