/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:10:58 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/10 19:21:04 by vinograd         ###   ########.fr       */
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
