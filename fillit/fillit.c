/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 19:53:38 by Nik               #+#    #+#             */
/*   Updated: 2019/06/17 10:44:16 by Nik              ###   ########.fr       */
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

int			check_borders(t_figure *fig)
{
	if (check_boarder_down(fig->figure, fig->size - 1) &&\
			check_boarder_right(fig->figure, fig->size - 1))
		return (1);
	return (0);
}

void		back_track(t_figure *head)
{
	t_figure	*tmp;
	int			flag;
	int			end;
	
	end = 1;
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
				{	
					tmp = go_back(head, tmp->num);
					if (tmp == head && check_borders(head))
					{
						refresh(head, head->size + 1);
						break ;
					}
				}
				flag = 0;
			}
		tmp = tmp->next;
	}
}
