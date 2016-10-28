#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/12 15:36:21 by dle-blon          #+#    #+#              #
#    Updated: 2016/10/28 16:04:22 by dle-blon         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

PROJECT_NAME = libft

NAME = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

INC = -I ./includes

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

WHITE =		\033[37;01m
RED =		\033[31;01m
GREEN =		\033[32;01m
YELLOW =	\033[33;01m
BLUE =		\033[34;01m
BASIC =		\033[0m

.PHONY: all clean fclean re

all : info $(NAME)

info :
	@if (! (test -e $(NAME) && test -e srcs/debug/debug.o));			\
	then																\
		echo "$(WHITE) Project: $(BASIC) $(PROJECT_NAME)";				\
		echo "$(WHITE) Flags: $(BASIC) $(FLAGS)";						\
		echo "$(WHITE) Compiler: $(BASIC) $(CC)";						\
	fi

%.o : %.c
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "$(BLUE) $< $(WHITE)->$(RED) $@ $(BASIC)"

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(BLUE) objs $(WHITE)->$(RED) $(NAME) $(BASIC)"

clean :
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all;
