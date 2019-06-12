/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_figure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikgrape <nikgrape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 00:41:42 by nikgrape          #+#    #+#             */
/*   Updated: 2019/06/12 00:43:19 by nikgrape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			del_figure(t_figure *list)
{
	int i;

	i = 0;
	while (i < list->size)
		ft_strdel(&(list->figure[i++]));
	free(list->figure);
	list->figure = NULL;
	//list->next = NULL;
	free(list);
	list = NULL;
}
