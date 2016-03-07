#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/14 19:37:17 by dle-blon          #+#    #+#              #
#    Updated: 2016/03/07 21:21:05 by dle-blon         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

FLAGS = -Wall -Wextra -Werror

ARG = 	-L/usr/local/lib/ -I/usr/local/include -lmlx \
		-framework OpenGL -framework AppKit

FILES = ./srcs/burn.c ./srcs/error.c ./srcs/julia.c ./srcs/libft.c \
		./srcs/lpburn.c ./srcs/lpjulia.c ./srcs/lpmand.c ./srcs/douady.c \
		./srcs/main.c ./srcs/mandel.c ./srcs/lpdoua.c \

all : $(NAME)

$(NAME) : $(FILES)
	@gcc $(FLAGS) $(ARG) $(FILES) -o $(NAME)

clean :
	@touch nul; rm nul

fclean : clean
	@rm -f $(NAME)

re : fclean all