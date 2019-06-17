/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 21:36:54 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/14 22:34:23 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//exit, open, close, write, read, malloc and free.
#include "fillit.h"

int		check_boarders(t_figure *fig)
{
	int i;
	int j;

	i = check_boarder_down(fig->figure, fig->size);
	j = check_boarder_right(fig->figure, fig->size);
	return ((i && j) ? 1 : 0);
}

void	back_track(t_figure *head)
{
	t_figure	*tmp;
	int			flag;

	tmp = head;
	while (tmp)
	{
		flag = 1;
		while (is_overlap(head, tmp))
			if (move_next(tmp))
			{
				move_top_all(tmp);
				tmp = go_back(head, tmp->num);
				while (move_next(tmp))
					tmp = go_back(head, tmp->num);
				//if (check_borders(head))
				//	return (1);
				flag = 0;
			}
		if (flag)
			tmp = tmp->next;
	}
}

int		main(int argc, char **argv)
{
	t_figure	*head;
	int			fd;

	if (argc != 2)
		ft_error(0);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		return (0);
	}
	head = figure_reader(fd);
	close(fd);
	move_top_all(head);
	refresh(head, get_board_size(head));
	back_track(head);
	fill_figure_with_letters(head);
	print_all(head);
	fillit(head);
	print(head);
}

/*
		ABBBB.
		ACCCEE
		AFFCEE
		A.FFGG
		HHHDDG
		.HDD.G

ABBBB.
AHHHDD
A.HDD.
AGGCCC
EEGFFC
EEG.FF

0       ABBBB.
0       AHHHDD
0       A.HDD.
0       AGGCCC
0       EEGFFC
0       EEG.FF

		DDAA
		CDDA
		CCCA
		BBBB

    	DDAA
    	CDDA
	    CCCA
		BBBB
*/