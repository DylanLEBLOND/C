#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/12 15:36:21 by dle-blon          #+#    #+#              #
#    Updated: 2015/02/06 17:10:49 by dle-blon         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

FILES = ./memcpy.c ./isprint.c ./isalnum.c ./isdigit.c ./isalpha.c ./isascii.c ./tolower.c \
		./toupper.c ./atoi.c ./memcmp.c ./memchr.c ./strchr.c ./strrchr.c ./strcmp.c \
		./strncmp.c ./strdup.c ./strcat.c ./strncat.c ./strlcat.c ./strcpy.c ./strncpy.c \
		./strlen.c ./memalloc.c ./memdel.c ./strnew.c ./strdel.c ./strclr.c ./striter.c \
		./striteri.c ./strmap.c ./strmapi.c ./strequ.c ./strnequ.c ./strsub.c ./strjoin.c \
		./strtrim.c ./strsplit.c ./itoa.c ./putchar.c ./putchar_fd.c ./putnbr.c ./putnbr_fd.c \
		./putstr.c ./putstr_fd.c ./putendl.c ./putendl_fd.c ./bzero.c ./memmove.c ./memset.c \
		./strstr.c ./strnstr.c ./memccpy.c

OBJECTS = 	./memcpy.o ./isprint.o ./isalnum.o ./isdigit.o ./isalpha.o ./isascii.o ./tolower.o \
			./toupper.o ./atoi.o ./memcmp.o ./memchr.o ./strchr.o ./strrchr.o ./strcmp.o \
			./strncmp.o ./strdup.o ./strcat.o ./strncat.o ./strlcat.o ./strcpy.o ./strncpy.o \
			./strlen.o ./memalloc.o	./memdel.o ./strnew.o ./strdel.o ./strclr.o ./striter.o	\
			./striteri.o ./strmap.o	./strmapi.o ./strequ.o ./strnequ.o ./strsub.o ./strjoin.o \
			./strtrim.o ./strsplit.o ./itoa.o ./putchar.o ./putchar_fd.o ./putnbr.o ./putnbr_fd.o \
			./putstr.o ./putstr_fd.o ./putendl.o ./putendl_fd.o ./bzero.o ./memmove.o ./memset.o \
			./strstr.o ./strnstr.o ./memccpy.o

all : $(NAME)

$(NAME) : $(FILES)
	@gcc -Wall -Wextra -Werror -c $(FILES) -I .
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean :
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all;