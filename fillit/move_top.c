/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikgrape <nikgrape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 22:41:40 by nikgrape          #+#    #+#             */
/*   Updated: 2019/06/10 00:30:13 by nikgrape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void    move_left(char f[4][5])
{
    unsigned int i;
    unsigned int j;
    unsigned int top;
    unsigned int flag;

    top = 0;
    i = 0;
    while (i < 4)
    {
        j = 0;
        flag = 0;
        while (j < 4)
        {
            if (f[j][i] == '#')
            {
                ft_swap(&f[j][i], &f[j][top]);
                flag++;
            }
            j++;
        }
        if (flag)
            top++;
        i++;
    }
}

static void    move_up(char f[4][5])
{
    unsigned int i;
    unsigned int j;
    int top;
    int flag;

    top = 0;
    j = 0;
    while (j < 4)
    {
        i = 0;
        flag = 0;
        while (i < 4)
        {
            if (f[j][i] == '#')
            {
                ft_swap(&f[j][i], &f[top][i]);
                flag++;
            }
            i++;
        }
        if (flag)
            top++;
        j++;
    }
}

//void    move_top(t_figure *start)
int main()// compile with swap.c
{
    int i;
    int j;
    char arr[4][5] =    {"....",
                         "....",
                         "..##",
                         ".##."};
    move_up(arr);
    move_left(arr);
    while (i < 4)
        printf("%s\n", arr[i++]);
}