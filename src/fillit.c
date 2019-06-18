/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 19:53:38 by Nik               #+#    #+#             */
/*   Updated: 2019/06/18 15:43:29 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	figfill(char **head, char **fig, int size)
{
	int i;
	int j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (fig[j][i] != '.')
				head[j][i] = fig[j][i];
			i++;
		}
		j++;
	}
	return (0);
}

void		fillit(t_figure *head)
{
	t_figure *tmp;

	tmp = head;
	while (tmp)
	{
		figfill(head->figure, tmp->figure, head->size);
		tmp = tmp->next;
	}
}

void		back_track(t_figure *head)
{
	t_figure	*tmp;

	tmp = head;
	while (tmp)
	{
		while (is_overlap(head, tmp))
			if (move_next(tmp))
			{
				while (move_next(tmp))
				{
					if (tmp == head)
					{
						refresh(head, head->size + 1);
						break ;
					}
					tmp = go_back(head, tmp->num);
				}
				move_top_all(tmp->next);
			}
		tmp = tmp->next;
	}
}
