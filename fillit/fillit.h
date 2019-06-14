/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:23:09 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/13 16:46:05 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct	s_figure
{
	int				size;
	int				num;
	char			**figure;
	struct s_figure *next;
}				t_figure;

void			ft_swap(char *c1, char *c2);
t_figure		*figure_reader(int fd);
int				board_size(t_figure *start);
char			**get_board(int size);
void			move_top(t_figure *start);
void			move_top_all(t_figure *start);
void			move_left(char **f, int size);
void			refresh(t_figure *start, int size);
t_figure		*new_figure(int size);
void			del_figure(t_figure *list);
int				move_next(t_figure *list);
void			fill_letters(t_figure *list);
void			fill_letters_all(t_figure *start);
int				is_overlap_tmp(t_figure *head, t_figure *fig);
void			fillit(t_figure *head);
int 			is_overlap(t_figure *head, t_figure *body);
int				figure_compare(char **head, char **body, int size);

#endif
