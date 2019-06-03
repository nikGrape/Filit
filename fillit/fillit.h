/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:23:09 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/03 15:53:24 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "../libft/libft.h"

typedef struct s_figure
{
    int num;
    int cost;
    int figure[4][4];
    struct s_figure *next;
} t_figure;

void    fillit(char *str);
void    ft_swap(char *c1, char *c2);
int     move_left(char *str);

#endif