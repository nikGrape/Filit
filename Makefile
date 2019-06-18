# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 21:12:56 by vinograd          #+#    #+#              #
#    Updated: 2019/06/17 20:26:31 by dbubnov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

SRCS=*.c

OBJECTS=*.o

INCLUDES=libft/

FLAGS=-Werror -Wextra -Wall

all: $(NAME)

$(NAME):
	@make -C libft/ re
	gcc $(FLAGS) src/$(SRCS) libft/libft.a -I$(INCLUDES)libft.h src/fillit.h

clean:
	@make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
