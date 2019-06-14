/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 19:39:51 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/13 20:12:13 by vinograd         ###   ########.fr       */
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
