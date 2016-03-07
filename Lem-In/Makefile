#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/01 20:05:13 by dle-blon          #+#    #+#              #
#    Updated: 2015/11/01 20:07:23 by dle-blon         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

FLAGS = -Wall -Wextra -Werror

FILES = ./srcs/error.c ./srcs/get.c ./srcs/main.c ./srcs/getbest.c \
		./srcs/move.c ./srcs/parsing_read.c ./srcs/parsing_road.c \
		./srcs/parsing_link.c ./srcs/parsing_node.c

LIBNAME = ./libft/libft.a

all : $(NAME)

$(NAME) : $(FILES)
	make -C libft
	@gcc $(FLAGS) $(FILES) $(LIBNAME) -o $(NAME)

clean :
	make -C libft clean

fclean : clean
	make -C libft fclean
	@rm -f $(NAME)

re : fclean all
