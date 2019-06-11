/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 21:36:54 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/11 15:07:29 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//exit, open, close, write, read, malloc and free.
#include "fillit.h"

void	print(t_figure *head, int size)
{
	int i;
	char ch;

	ch = 'A';
	while (head != NULL)
	{
		i = 0;
		while (i < size)
		{
			printf("%c\t%s\n", ch, head->figure[i]);
			i++;
		}
		printf("\n");
		ch++;
		head = head->next;
	}
}

int		main(int argc, char **argv)
{
	t_figure	*head;
	int			fd;
	int			size;
	char		**board;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	head = figure_reader(fd);
	close(fd);
	size = board_size(head);
	printf("BOARD SIZE: %dx%d\n\n", size, size);
	//board = get_board(size); // works
	move_top(head, size);
	refresh(head, size);
	print(head, size);
}
