/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikgrape <nikgrape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:40:14 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/12 12:28:36 by nikgrape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		dot_filler(char *str, int size)
{
	int i;

	i = 0;
	while (i < size)
		str[i++] = '.';
	str[size] = '\0';
}

static char		*ft_linecpy(char *dst, char *src, int size)
{
	int i;

	i = 0;
	dot_filler(dst, size);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

void		figure_clear(t_figure *list)
{
	int i;

	i = 0;
	while (i < list->size)
	{
		ft_strdel(&(list->figure[i++]));
	}
	ft_strdel(list->figure);
}

static void	refresh_figure(t_figure *list, int size)
{
	int		i;
	char	**new;

	new = (char**)malloc(sizeof(char*) * size);
	i = 0;
	while (i < size)
	{
		new[i] = ft_strnew(size);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		ft_linecpy(new[i], list->figure[i], size);
		i++;
	}
	while (i < size)
		dot_filler(new[i++], size);
	figure_clear(list);
	list->size = size;
	list->figure = new;
}

void		refresh(t_figure *list, int size)
{
	while (list)
	{
		refresh_figure(list, size);
		list = list->next;
	}
}
