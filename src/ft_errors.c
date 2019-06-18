/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 19:39:51 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/18 13:11:35 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_error(int err)
{
	if (err == 0)
		ft_putstr("usage: fillit source_file\n");
	else if (err == -1)
		ft_putstr("file not found!\n");
	else if (err == 1)
		ft_putstr("error\n");
	else if (err == 2)
		ft_putstr("too many tetriminos\n");
	exit(1);
}

static int	check(char **f, int j, int i)
{
	int touch;

	touch = 0;
	if ((i + 1) < 4)
		if (f[j][i + 1] == '#')
			touch++;
	if ((j + 1) < 4)
		if (f[j + 1][i] == '#')
			touch++;
	if ((j - 1) >= 0)
		if (f[j - 1][i] == '#')
			touch++;
	if ((i - 1) >= 0)
		if (f[j][i - 1] == '#')
			touch++;
	return (touch);
}

static void	figure_checker(char **f)
{
	int i;
	int j;
	int touch;

	j = 0;
	touch = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (f[j][i] == '#')
				touch += check(f, j, i);
			i++;
		}
		j++;
	}
	if (touch != 8 && touch != 6)
		ft_error(1);
}

static void	figure_valid(char **f)
{
	int		i;
	int		j;
	int		count;

	j = 0;
	count = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (f[j][i] == '#')
				count++;
			if (f[j][i] != '.' && f[j][i] != '#')
				ft_error(1);
			i++;
		}
		j++;
	}
	if (count != 4)
		ft_error(1);
}

void		check_oll_figures(t_figure *head)
{
	while (head)
	{
		figure_valid(head->figure);
		figure_checker(head->figure);
		head = head->next;
	}
}
