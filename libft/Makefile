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

CC = gcc

FLAGS = -Wall -Wextra -Werror

INC = ./includes

SRC = 	converter/atoi.c converter/itoa.c \
		ctype/isalnum.c ctype/isalpha.c ctype/isascii.c ctype/isdigit.c \
		ctype/isprint.c ctype/tolower.c ctype/toupper.c \
		debug/debug.c \
		memory/bzero.c memory/memalloc.c memory/memccpy.c memory/memchr.c \
		memory/memcmp.c memory/memcpy.c memory/memmove.c memory/memset.c \
		memory/memdel.c \
		print/putchar.c print/putchar_fd.c print/putnbr.c print/putnbr_fd.c \
		print/putstr.c print/putstr_fd.c print/putendl.c print/putendl_fd.c \
		string/strcat.c string/strchr.c string/strclr.c string/strcmp.c \
		string/strcpy.c string/strdel.c string/strdup.c string/strequ.c \
		string/striter.c string/striteri.c string/strjoin.c string/strlcat.c \
		string/strlen.c string/strmap.c string/strmapi.c string/strncat.c \
		string/strncmp.c string/strncpy.c string/strnequ.c string/strnew.c \
		string/strnstr.c string/strrchr.c string/strsplit.c string/strstr.c \
		string/strsub.c string/strtrim.c 

SRC_DIR = ./srcs

SRCS = $(addprefix $(SRC_DIR)/,$(SRC))

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -I $(INC) -c -o $@ $<

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean :
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all;
