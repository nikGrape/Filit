/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 21:36:54 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/13 00:39:33 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//exit, open, close, write, read, malloc and free.
#include "fillit.h"

void	print(t_figure *head)
{
	int i;
	
	i = 0;
	while (i < head->size)
	{
		printf("%i\t%s\n", head->num, head->figure[i]);
		i++;
	}
}

void	print_all(t_figure *head)
{
	while (head)
	{
		print(head);
		printf("\n");
		head = head->next;
	}
}

t_figure	*go_back(t_figure *head, int num)
{
	while (head->num < (num - 1))
		head = head->next;
	return (head);
}

int		main(int argc, char **argv)
{
	t_figure	*head;
	t_figure	*tmp;
	int			fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	head = figure_reader(fd);
	close(fd); 
	move_top_all(head);
	refresh(head, board_size(head));
	fill_letters_all(head);
	tmp = head;
	int i;
	while (tmp)
	{
		i = 1;
		while (is_overlap_tmp(head, tmp))
			if (move_next(tmp))
			{
				move_top_all(tmp);
				tmp = go_back(head, tmp->num);
				while (move_next(tmp))
				 	tmp = go_back(head, tmp->num);
				i = 0;
			}
		if(i)
			tmp = tmp->next;
	}
	//print_all(head);
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

		DDAA
		CDDA
		CCCA
		BBBB
		
    	DDAA
    	CDDA
	    CCCA
		BBBB
*/