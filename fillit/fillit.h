/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikgrape <nikgrape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:23:09 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/10 00:38:14 by nikgrape         ###   ########.fr       */
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
t_figure        *new_figure(char num);
void            move_top(t_figure *start);
t_figure        *figure_reader(int fd);

#endif