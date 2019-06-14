/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 18:49:01 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/13 22:33:46 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	fill_letters(t_figure *list)
{
	int i;
	int j;

	i = 0;
	while (i < list->size)
	{
		j = 0;
		while (j < list->size)
		{
			if (list->figure[i][j] != '.')
				list->figure[i][j] = list->num + 'A';
			j++;
		}
		i++;
	}
}

void		fill_figure_with_letters(t_figure *start)
{
	while (start)
	{
		fill_letters(start);
		start = start->next;
	}
}

void		print(t_figure *head)
{
	int i;

	i = 0;
	while (i < head->size)
	{
		ft_putstr(head->figure[i]);
		ft_putstr("\n");
		i++;
	}
}
