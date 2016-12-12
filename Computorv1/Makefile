#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/28 21:15:43 by dle-blon          #+#    #+#              #
#    Updated: 2015/04/01 18:29:06 by dle-blon         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FILES = ./srcs/aff.c ./srcs/initial.c ./srcs/atof.c ./srcs/lect.c ./srcs/main.c \
		./srcs/polynome.c ./srcs/check.c

FLAGS = -Wall -Wextra -Werror

NAME = computor

LIBNAME = srcs/libft/libft.a

all: $(NAME)

$(NAME): $(FILES)
	@make -C srcs/libft
	@gcc $(FLAGS) $(FILES) $(LIBNAME) -o $(NAME)

clean:
	@make -C srcs/libft clean

fclean: clean
	@make -C srcs/libft fclean
	@rm -f $(NAME)

re: fclean all
