/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:40:14 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/11 14:59:26 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			dot_filler(char *str, int size)
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

static void		del_figure(t_figure *list)
{
	int i;

	i = 0;
	while (i < 4)
		ft_strdel(&(list->figure[i++]));
	free(list->figure);
	list->figure = NULL;
	list->next = NULL;
	free(list);
	list = NULL;
}

static t_figure	*refresh_figure(t_figure *list, int size)
{
	t_figure	*new;
	int			i;

	i = 0;
	new = new_figure(size);
	new->next = list->next;
	while (i < 4)
	{
		ft_linecpy(new->figure[i], list->figure[i], size);
		i++;
	}
	while (i < size)
		dot_filler(new->figure[i++], size);
	del_figure(list);
	return (new);
}

void		refresh(t_figure *list, int size)
{
	while (list != NULL)
	{
		list = refresh_figure(list, size);
		list = list->next;
	}
}