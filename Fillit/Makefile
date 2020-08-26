#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/27 19:13:26 by dle-blon          #+#    #+#              #
#    Updated: 2016/02/11 21:01:59 by mnguyen          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRCS = 	./srcs/error.c ./srcs/main.c ./srcs/parsing_read.c ./srcs/tetriminos.c\
		./srcs/valid.c ./srcs/algo.c ./srcs/algo2.c

LIBNAME = ./libft/libft.a

all : $(NAME)

$(NAME) : $(SRCS)
	make -C libft
	gcc $(FLAGS) $(SRCS) $(LIBNAME) -o $(NAME)

clean :
	make -C libft clean

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all