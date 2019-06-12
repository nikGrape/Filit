/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikgrape <nikgrape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:40:33 by dbubnov           #+#    #+#             */
/*   Updated: 2019/06/12 11:34:29 by nikgrape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_boarder_right(char **f, int size_field)
{
	unsigned int	i;
	unsigned int	j;

	i = size_field;
	j = 0;
	while (j <= size_field)
	{
		if (f[j][size_field] != '.')
			return (1);
		j++;
	}
	return (0);
}

static int	check_boarder_down(char **f, int size_field)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = size_field;
	while (i <= size_field)
	{
		if (f[size_field][i] != '.')
			return (1);
		i++;
	}
	return (0);
}

static void	move_right(char **f, int size_field)
{
	unsigned int	i;
	unsigned int	j;
	int				triger;

	i = size_field;
	j = size_field;
	triger = 0;
	if (check_boarder_right(f, size_field) == 1)
		triger++;
	while (i > 0 || j > 0)
	{
		if (triger == 1)
		{
			i = 0;
			j = 0;
			break ;
		}
		if (f[j][i] != '.' && i != size_field)
			ft_swap(&f[j][i], &f[j][i + 1]);
		if (i == 0)
		{
			j--;
			i = size_field;
		}
		else
			i--;
	}
	if (triger == 0)
		ft_swap(&f[j][i], &f[j][i + 1]);
}

static void	move_down(char **f, int size_field)
{
	unsigned int	i;
	unsigned int	j;
	int				triger;

	i = size_field;
	j = size_field;
	triger = 0;
	if (check_boarder_down(f, size_field) == 1)
		triger++;
	while (i > 0 || j > 0)
	{
		if (triger == 1)
		{
			i = 0;
			j = 0;
			break ;
		}
		if (f[j][i] != '.' && j != size_field)
			ft_swap(&f[j][i], &f[j + 1][i]);
		if (i == 0)
		{
			j--;
			i = size_field;
		}
		else
			i--;
	}
	if (triger == 0)
		ft_swap(&f[j][i], &f[j + 1][i]);
}

int			move_next(t_figure *list)
{
	if (check_boarder_down(list->figure, list->size - 1)
		&& check_boarder_right(list->figure, list->size - 1))
		return (1);
	if (check_boarder_right(list->figure, list->size - 1))
	{
		move_left(list->figure, list->size);
		move_down(list->figure, list->size - 1);
	}
	else
		move_right(list->figure, list->size - 1);
	return (0);
}
