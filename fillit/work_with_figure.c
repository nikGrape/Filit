/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_figure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 00:41:42 by nikgrape          #+#    #+#             */
/*   Updated: 2019/06/13 21:01:44 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_size(int size)
{
	int b_sz;

	b_sz = 4;
	size *= 4;
	while (size > (b_sz * b_sz))
		b_sz++;
	return (b_sz);
}

static void		del_figure(t_figure *list)
{
	int i;

	i = 0;
	while (i < list->size)
		free(list->figure[i++]);
	free(list->figure);
	list->figure = NULL;
	list->size = 0;
	list->num = 0;
	list->next = NULL;
	//free(list);
	//list = NULL;
}

void			dell_all_figures(t_figure *head)
{
	t_figure *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		del_figure(tmp);
		free(tmp);
	}
}

t_figure		*go_back(t_figure *head, int num)
{
	while (head->num < (num - 1))
		head = head->next;
	return (head);
}

int				get_board_size(t_figure *start)
{
	int count;

	count = 0;
	while (start != NULL)
	{
		start = start->next;
		count++;
	}
	return (ft_size(count));
}
