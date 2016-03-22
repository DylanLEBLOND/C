#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/27 17:07:23 by dle-blon          #+#    #+#              #
#    Updated: 2016/03/22 19:18:25 by dle-blon         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

FLAGS = -Wall -Wextra -Werror

ARG = 	-L/usr/local/lib -I/usr/local/include -lmlx \
		-framework OpenGL -framework AppKit

FILES = ./srcs/error.c ./srcs/lect.c ./srcs/main.c ./srcs/minimap.c \
		./srcs/mlx.c ./srcs/move.c ./srcs/ray.c ./srcs/raynext.c ./srcs/tab.c

LIBNAME = ./libft/libft.a

all : $(NAME)

$(NAME) : $(FILES)
	make -C libft
	@gcc $(FLAGS) $(ARG) $(FILES) $(LIBNAME) -o $(NAME)

clean :
	make -C libft clean

fclean : clean
	make -C libft fclean
	@rm -f $(NAME)

re : fclean all