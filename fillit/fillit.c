/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 19:53:38 by Nik               #+#    #+#             */
/*   Updated: 2019/06/12 21:08:35 by Nik              ###   ########.fr       */
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
