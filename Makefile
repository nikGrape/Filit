# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 21:12:56 by vinograd          #+#    #+#              #
#    Updated: 2019/05/31 14:41:45 by vinograd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

SRCS=*.c

OBJECTS=*.o

INCLUDES=./

all:
	gcc -Werror -Wextra -Wall fillit.c libft/libft.a -I libft/libft.h

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
