/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_overlap_tmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 19:06:53 by Nik               #+#    #+#             */
/*   Updated: 2019/06/12 21:44:43 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	figcmp(char **head, char **fig, int size)
{
	int i;
	int j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (head[j][i] != '.' && fig[j][i] != '.')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int			is_overlap_tmp(t_figure *head, t_figure *fig)
{
	int ret;
	
	ret = 0;
	while (head->num < fig->num)
	{
		if((ret = figcmp(head->figure, fig->figure, fig->size)) == 1)
			break ;
		head = head->next;
	}
	return (ret);
}