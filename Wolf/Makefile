#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/27 17:07:23 by dle-blon          #+#    #+#              #
#    Updated: 2015/06/04 18:20:37 by dle-blon         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

FLAGS = -Wall -Wextra -Werror

ARG = -L/usr/X11/lib -Lminilibx_macos -framework OpenGL -framework AppKit

FILES = ./srcs/error.c ./srcs/lect.c ./srcs/main.c ./srcs/minimap.c \
		./srcs/mlx.c ./srcs/move.c ./srcs/ray.c ./srcs/raynext.c ./srcs/tab.c

LIBNAME = ./minilibx_macos/libmlx.a ./libft/libft.a

all : $(NAME)

$(NAME) : $(FILES)
	make -C minilibx_macos
	make -C libft
	@gcc $(FLAGS) $(ARG) $(FILES) $(LIBNAME) -o $(NAME)

clean :
	make -C minilibx_macos clean
	make -C libft clean

fclean : clean
	make -C minilibx_macos fclean
	make -C libft fclean
	@rm -f $(NAME)

re : fclean all