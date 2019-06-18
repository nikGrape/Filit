/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 22:42:43 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/18 14:01:04 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

typedef struct	s_figure
{
	int				size;
	int				num;
	char			**figure;
	struct s_figure *next;
}				t_figure;

t_figure		*figure_reader(int fd);
t_figure		*go_back(t_figure *head, int num);
void			check_oll_figures(t_figure *head);
void			move_top_all(t_figure *start);
void			move_top(t_figure *list);
void			move_left(char **f, int size);
void			refresh(t_figure *start, int size);
void			dell_all_figures(t_figure *head);
void			ft_error(int err);
void			fillit(t_figure *head);
void			fill_figure_with_letters(t_figure *start);
void			print(t_figure *head);
void			back_track(t_figure *head);
int				get_board_size(t_figure *start);
int				is_overlap(t_figure *head, t_figure *body);
int				move_next(t_figure *list);

#endif
