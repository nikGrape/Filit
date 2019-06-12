/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikgrape <nikgrape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 01:06:44 by nikgrape          #+#    #+#             */
/*   Updated: 2019/06/12 12:34:44 by nikgrape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_size(int size)
{
	int b_sz;

	b_sz = 4;
	size *= 4;
	while (size > (b_sz * b_sz))
		b_sz++;
	return (b_sz);
}

int			board_size(t_figure *start)
{
	int count;

	count = 0;
	while (start != NULL)
	{
		start = start->next;
		count++;
	}
	return (ft_size(count));
}

char		**get_board(int size)
{
	int		i;
	char	**board;

	i = 0;
	if (!(board = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	while (i < size)
		if (!(board[i++] = ft_strnew(size)))
			return (NULL);
	return (board);
}

void	fill_letters(t_figure *list)
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

void	fill_letters_all(t_figure *start)
{
	while (start)
	{
		fill_letters(start);
		start = start->next;
	}
}