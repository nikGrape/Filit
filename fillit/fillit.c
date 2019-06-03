/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 21:36:54 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/03 15:37:55 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//exit, open, close, write, read, malloc and free.
#include "../libft/libft.h"
#include "fillit.h"

int main()
{
	//t_figure head;
	int		fd;
	char	*line;

	fd = open("test.fillit", O_RDONLY);
	while(get_next_line(fd, &line))
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	close(fd);
}
