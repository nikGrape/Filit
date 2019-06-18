/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 22:54:17 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/17 18:04:49 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_all(t_figure *head)
{
	while (head)
	{
		print(head);
		head = head->next;
	}
}

int		main(int argc, char **argv)
{
	t_figure	*head;
	int			fd;

	if (argc != 2)
		ft_error(0);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error(-1);
	head = figure_reader(fd);
	close(fd);
	check_oll_figures(head);
	refresh(head, get_board_size(head));
	back_track(head);
	fill_figure_with_letters(head);
	fillit(head);
	print(head);
	dell_all_figures(head);
}
