/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_by_step.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:43:13 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/18 15:44:01 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		tmp_print(t_figure *tmp, int num)
{
	char	arr[tmp->size][tmp->size + 1];
	int		i;
	int		j;

	j = 0;
	while (j < tmp->size)
	{
		i = 0;
		while (i < tmp->size)
		{
			arr[j][i] = '.';
			i++;
		}
		arr[j][i] = '\0';
		j++;
	}
	while (tmp->num <= num)
	{
		j = 0;
		while (j < tmp->size)
		{
			i = 0;
			while (i < tmp->size)
			{
				if (tmp->figure[j][i] != '.')
					arr[j][i] = tmp->num + 'A';
				i++;
			}
			j++;
		}
		tmp = tmp->next;
	}
	j = 0;
	while (j < tmp->size)
	{
		ft_putstr(arr[j]);
		ft_putstr("\n");
		j++;
	}
	ft_putstr("\n");
	ft_putstr("\n");
	sleep(2);
}
