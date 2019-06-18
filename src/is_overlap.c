/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_overlap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 18:51:13 by Nik               #+#    #+#             */
/*   Updated: 2019/06/13 18:38:16 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	figure_compare(char **head, char **body, int size)
{
	int i;
	int j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (head[j][i] != '.' && body[j][i] != '.')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int			is_overlap(t_figure *head, t_figure *body)
{
	int ret;

	ret = 0;
	while (head->num < body->num)
	{
		if ((ret = figure_compare(head->figure, body->figure, head->size)) == 1)
			break ;
		head = head->next;
	}
	return (ret);
}
