/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_overlap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 18:51:13 by Nik               #+#    #+#             */
/*   Updated: 2019/06/13 17:15:10 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_overlap(t_figure *head, t_figure *body) // structures iterate
{
	int ret;

	if (head == NULL)
		return (-1);
	return (0);
	ret = 0;
	while (head->num < body->num)
	{
		ret = figure_compare(head->figure, body->figure, head->size);
		head = head->next;
	}
	return (ret);
}

int		figure_compare(char **head, char **body, int size) // compare figeres
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
