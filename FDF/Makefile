#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/19 14:48:25 by dle-blon          #+#    #+#              #
#    Updated: 2016/03/07 20:53:39 by dle-blon         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

FLAGS = -Wall -Wextra -Werror

ARG = 	-L/usr/local/lib/ -I/usr/local/include -lmlx \
		-framework OpenGL -framework AppKit

FILES = ./srcs/color.c ./srcs/droite.c ./srcs/getnbr.c ./srcs/mlx.c \
		./srcs/error.c ./srcs/get_next_line.c ./srcs/lect.c \
		./srcs/main.c

LIBNAME = ./libft/libft.a

all : $(NAME)

$(NAME) : $(FILES)
	make -C libft
	gcc $(FLAGS) $(ARG) $(FILES) $(LIBNAME) -o $(NAME)

clean :
	make -C libft

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all