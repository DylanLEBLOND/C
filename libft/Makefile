#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/12 15:36:21 by dle-blon          #+#    #+#              #
#    Updated: 2015/06/02 18:49:58 by dle-blon         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRCS = 	./srcs/memcpy.c ./srcs/isprint.c ./srcs/isalnum.c ./srcs/isdigit.c \
		./srcs/isalpha.c ./srcs/isascii.c ./srcs/tolower.c ./srcs/toupper.c \
		./srcs/atoi.c ./srcs/memcmp.c ./srcs/memchr.c ./srcs/strchr.c \
		./srcs/strrchr.c ./srcs/strcmp.c ./srcs/strncmp.c ./srcs/strdup.c \
		./srcs/strcat.c ./srcs/strncat.c ./srcs/strlcat.c ./srcs/strcpy.c \
		./srcs/strncpy.c ./srcs/strlen.c ./srcs/memalloc.c ./srcs/memdel.c \
		./srcs/strnew.c ./srcs/strdel.c ./srcs/strclr.c ./srcs/striter.c \
		./srcs/striteri.c ./srcs/strmap.c ./srcs/strmapi.c ./srcs/strequ.c \
		./srcs/strnequ.c ./srcs/strsub.c ./srcs/strjoin.c ./srcs/strtrim.c \
		./srcs/strsplit.c ./srcs/itoa.c ./srcs/putchar.c ./srcs/putchar_fd.c \
		./srcs/putnbr.c ./srcs/putnbr_fd.c ./srcs/putstr.c ./srcs/putstr_fd.c \
		./srcs/putendl.c ./srcs/putendl_fd.c ./srcs/bzero.c ./srcs/memmove.c \
		./srcs/memset.c ./srcs/strstr.c ./srcs/strnstr.c ./srcs/memccpy.c

INCLUDES = ./includes

OBJECTS = 	./memcpy.o ./isprint.o ./isalnum.o ./isdigit.o ./isalpha.o \
			./isascii.o ./tolower.o ./toupper.o ./atoi.o ./memcmp.o ./memchr.o \
			./strchr.o ./strrchr.o ./strcmp.o ./strncmp.o ./strdup.o \
			./strcat.o ./strncat.o ./strlcat.o ./strcpy.o ./strncpy.o \
			./strlen.o ./memalloc.o	./memdel.o ./strnew.o ./strdel.o \
			./strclr.o ./striter.o	./striteri.o ./strmap.o	./strmapi.o \
			./strequ.o ./strnequ.o ./strsub.o ./strjoin.o ./strtrim.o \
			./strsplit.o ./itoa.o ./putchar.o ./putchar_fd.o ./putnbr.o \
			./putnbr_fd.o ./putstr.o ./putstr_fd.o ./putendl.o ./putendl_fd.o \
			./bzero.o ./memmove.o ./memset.o ./strstr.o ./strnstr.o ./memccpy.o

all : $(NAME)

$(NAME) : $(FILES)
	@gcc -Wall -Wextra -Werror -c $(SRCS) -I $(INCLUDES)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean :
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all;
