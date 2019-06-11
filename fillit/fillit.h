/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:23:09 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/10 23:30:13 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct	s_figure
{
	//int				num;
	char			**figure;
	struct s_figure *next;
}				t_figure;

void			ft_swap(char *c1, char *c2);
t_figure		*figure_reader(int fd);
int				board_size(t_figure *start);
char			**get_board(int size);
void			move_top(t_figure *start, int size);
void			make_size(t_figure *start, int size);

#endif