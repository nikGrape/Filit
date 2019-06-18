/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 19:39:51 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/17 17:29:05 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(int err)
{
	if (err == 0)
		ft_putstr("usage: fillit source_file\n");
	else if (err == -1)
		ft_putstr("file not found!\n");
	else if (err == 1)
		ft_putstr("error\n");
	exit(1);
}

void	figure_checker(char f[4][5])
{
	int i;
	int j;
	int triger;

	i = 0;
	j = 0;
	while (j < 4)
	{
		while (i < 3)
		{
			triger = 0;
			if ((i + 1) < 4)
				if (f[j][i] == f[j][i + 1])
					triger++;
			if ((j + 1) < 4)
				if (f[j][i] == f[j + 1][i])
					triger++;
			if ((j - 1) > 0)
				if (f[j][i] != f[j - 1][i])
					triger++;
			if ((i - 1) > 0)
				if (f[j][i] != f[j][i - 1])
					triger++;
			if (triger == 0)
				ft_error(1);
			i++;
		}
		j++;
	}
}

int		main(void)
{
	int i;

	i = 0;
	char arr[4][5] =   {"##..",
						"....",
						".##.",
						"...."};

	figure_checker(arr);
	// while (i < 4)
	// 	printf("%s\n", arr[i++]);
	return (0);
}
