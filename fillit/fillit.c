/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 19:53:38 by Nik               #+#    #+#             */
/*   Updated: 2019/06/13 19:49:04 by vinograd         ###   ########.fr       */
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
	int			flag;

	tmp = head;
	while (tmp)
	{
		flag = 1;
		while (is_overlap(head, tmp))
			if (move_next(tmp))
			{
				move_top_all(tmp);
				tmp = go_back(head, tmp->num);
				while (move_next(tmp))
					tmp = go_back(head, tmp->num);
				//if (check_borders(head))
				//	return (1);
				flag = 0;
			}
		if (flag)
			tmp = tmp->next;
	}
}
