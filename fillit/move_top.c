/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikgrape <nikgrape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 22:41:40 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/12 12:33:14 by nikgrape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		move_left(char **f, int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int top;
	unsigned int flag;

	top = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		flag = 0;
		while (j < size)
		{
			if (f[j][i] != '.')
			{
				ft_swap(&f[j][i], &f[j][top]);
				flag++;
			}
			j++;
		}
		if (flag)
			top++;
		i++;
	}
}

static void	move_up(char **f, int size)
{
	unsigned int	i;
	unsigned int	j;
	int				top;
	int				flag;

	top = 0;
	j = 0;
	while (j < size)
	{
		i = 0;
		flag = 0;
		while (i < size)
		{
			if (f[j][i] != '.')
			{
				ft_swap(&f[j][i], &f[top][i]);
				flag++;
			}
			i++;
		}
		if (flag)
			top++;
		j++;
	}
}

void		move_top(t_figure *list)
{
	move_up(list->figure, list->size);
	move_left(list->figure, list->size);
}

void		move_top_all(t_figure *start)
{
	while (start != NULL)
	{
		move_top(start);
		start = start->next;
	}
}
