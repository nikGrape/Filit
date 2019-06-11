/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 01:06:44 by nikgrape          #+#    #+#             */
/*   Updated: 2019/06/10 23:26:18 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**get_board(int size)
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
