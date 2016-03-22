#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/14 19:37:17 by dle-blon          #+#    #+#              #
#    Updated: 2016/03/22 19:24:00 by dle-blon         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

FLAGS = -Wall -Wextra -Werror

ARG = 	-L/usr/local/lib/ -I/usr/local/include -lmlx \
		-framework OpenGL -framework AppKit

SRCS = ./srcs/burn.c ./srcs/error.c ./srcs/julia.c ./srcs/libft.c \
		./srcs/lpburn.c ./srcs/lpjulia.c ./srcs/lpmand.c ./srcs/douady.c \
		./srcs/main.c ./srcs/mandel.c ./srcs/lpdoua.c \

OBJ = $(SRCS:c=o)

LIB = fractol.a

all : $(NAME)

$(NAME) : $(OBJ)
	ar -r $(LIB) $(OBJ)
	@gcc $(FLAGS) $(LIB) $(ARG) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	@rm -f $(LIB) $(NAME)

re : fclean all