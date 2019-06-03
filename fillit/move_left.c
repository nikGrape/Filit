/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:31:49 by vinograd          #+#    #+#             */
/*   Updated: 2019/05/31 16:31:49 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static  check_left_border(char *str)
{
    int i;

    i = 0;
    while (i <= 12)
    {
        if (str[i] == '#')
            retunr (1);
        i = i + 4;
    }
    return (0);
}

int    move_left(char *str)
{
    char *ch;

    ch = str;
    if (check_left_border(str))
        return(0);
    while (*ch)
    {
        if(ch == '#')
            ft_swap(ch, --ch);
        ch++;
    }
    return (1);
}
