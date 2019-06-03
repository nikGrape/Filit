/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:54:35 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/03 15:54:36 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	figure_reader(int j, char arr[4][4], char *str, char num)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (ft_strchr(str, '#'))
			arr[j][i] = num;
	}
}