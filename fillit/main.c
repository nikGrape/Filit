/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikgrape <nikgrape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 21:36:54 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/10 01:38:04 by nikgrape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//exit, open, close, write, read, malloc and free.
#include "fillit.h"

int main(int argc, char **argv)
{
	t_figure	*head;
	int			fd;
	int			size;
	char		**board;
	
	if (argc != 2)
		return (0);
	fd = open("test.fillit", O_RDONLY);
	head = figure_reader(fd);
	close(fd);
	size = ft_size(head);
	board = get_board(size);
	move_top(head); // need to correct???
	
}

int  ft_size(t_figure *start)
{
    int size;

    size = 0;
    while (start != NULL)
    {
        start = start->next;
        size++;
    }
    return (size);
}