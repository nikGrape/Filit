/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikgrape <nikgrape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 01:06:44 by nikgrape          #+#    #+#             */
/*   Updated: 2019/06/10 01:30:15 by nikgrape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"



char    **get_board(int size)
{
    int     i;
    char    **board;
    
    i = 0;
    board = (char**)malloc(sizeof(char*) * size);
    while (i < size)
    {
        board[i++] = (char*)malloc(size + 1);
    }
    return (board);
}