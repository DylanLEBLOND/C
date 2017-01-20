#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 15:55:49 by dle-blon          #+#    #+#              #
#    Updated: 2015/12/23 13:48:16 by dle-blon         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = test

FILES = ./main.c

LIBNAME = ./printf/libftprintf.a

all : $(NAME)

$(NAME) : $(FILES)
	make -C ./printf
	gcc $(FILES) $(LIBNAME) -o $(NAME)

clean :
	make -C ./printf clean

fclean : clean
	make -C ./printf fclean
	rm -rf $(NAME)

re : fclean all