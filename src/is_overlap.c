/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_overlap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 18:51:13 by Nik               #+#    #+#             */
/*   Updated: 2019/06/18 17:39:34 by vinograd         ###   ########.fr       */
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

int			check_figure_size(t_figure *head)
{
	int j;
	int i;

	while (head)
	{
		j = 3;
		i = 0;
		while (i < 4)
			if (head->figure[j][i++] == '#')
				return (4);
		j = 0;
		i = 3;
		while (j < 4)
			if (head->figure[j++][i] == '#')
				return (4);
		head = head->next;
	}
	return (3);
}
