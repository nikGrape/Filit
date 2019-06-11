/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:40:33 by dbubnov           #+#    #+#             */
/*   Updated: 2019/06/10 17:56:27 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	move_next(char f[4][5], int size_field)
{
	unsigned int i;
	unsigned int j;
	unsigned int move;
	unsigned int flag;

	move = 0;
	i = size_field;
	j = size_field;
	while (i > 0 || j > 0)
	{
		move = 0;
		if (f[j][i] == '#')
		{
			ft_swap(&f[j][i], &f[j][move]);
			move++;
		}
		if (move && i != 0)
			move++;
		if (i == 0)
		{
			j--;
			i = size_field;
		}
		i--;
	}
}

int main(void)// compile with swap.c
{
    int i;
    int j;
    char arr[4][5] =    {"##..",
                         ".##.",
                         "....",
                         "...."};
    // move_up(arr);
    // move_left(arr);
	move_next(arr, 4);
    while (i < 4)
    	printf("%s\n", arr[i++]);
	return (0);
}
