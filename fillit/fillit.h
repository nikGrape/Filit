/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikgrape <nikgrape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:23:09 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/10 01:30:23 by nikgrape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "../libft/libft.h"
#include <stdio.h>

typedef struct  s_figure
{
    char num;
    char **figure;
    struct s_figure *next;
}               t_figure;

void            ft_swap(char *c1, char *c2);
t_figure        *figure_reader(int fd);
int             ft_size(t_figure *start);
char            **get_board(int size);
void            move_top(t_figure *start);

#endif