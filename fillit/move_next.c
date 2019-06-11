/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:40:33 by dbubnov           #+#    #+#             */
/*   Updated: 2019/06/11 10:40:14 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	move_next(char f[4][5], int size_field)
{
	unsigned int i;
	unsigned int j;

	i = size_field;
	j = size_field;
	while (i > 0 || j > 0)
	{
		if (f[j][size_field] == '#')
			break;
		if (f[j][i] == '#' && i != size_field)
			ft_swap(&f[j][i], &f[j][i + 1]);
		if (i == 0)
		{
			j--;
			i = size_field;
		}
		else
			i--;
	}
	if (f[j][size_field] != '#')
		ft_swap(&f[j][i], &f[j][i + 1]);
}

static void	move_down(char f[4][5], int size_field)
{
	unsigned int i;
	unsigned int j;

	i = size_field;
	j = size_field;
	while (i > 0 || j > 0 )
	{
		if (f[j][i] == '#' && i != size_field)
			ft_swap(&f[j][i], &f[j + 1][i]);
		if (i == 0)
		{
			j--;
			i = size_field;
		}
		else
			i--;
	}
	ft_swap(&f[j][i], &f[j + 1][i]);
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


	// move_down(arr, 3);
	move_next(arr, 3);
    while (i < 4)
    	printf("%s\n", arr[i++]);
	return (0);
}
