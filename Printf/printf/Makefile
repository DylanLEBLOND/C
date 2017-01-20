#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 15:19:01 by dle-blon          #+#    #+#              #
#    Updated: 2016/02/01 18:29:33 by dle-blon         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -c

FILES = ./srcs/base.c ./srcs/ft_atoi.c ./srcs/ft_printf.c ./srcs/getflags.c \
		./srcs/putchar.c ./srcs/putnbr.c ./srcs/putstr.c ./srcs/putvoid.c	\
		./srcs/strchr.c  ./srcs/strnew.c ./srcs/strsub.c ./srcs/strtrim.c	\
		./srcs/putoct.c ./srcs/puthex.c

OBJECTS = 	./base.o ./ft_atoi.o ./ft_printf.o ./getflags.o ./putchar.o \
			./putnbr.o ./putstr.o ./strchr.o ./strnew.o ./putvoid.o 	\
			./strsub.o ./strtrim.o ./putoct.o ./puthex.o

all : $(NAME)

$(NAME) : $(FILES)
	gcc $(FLAGS) $(FILES) -I .
	ar rc $(NAME) $(OBJECTS)

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all