#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/22 19:20:53 by dle-blon          #+#    #+#              #
#    Updated: 2016/10/28 17:26:40 by dle-blon         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls

CC = gcc

FLAGS = -Wall -Wextra -Werror

INC = -I ./includes -I ./libft/includes

LIBS = libft/libft.a

SRC = 	main.c error.c getinfo.c ft_ls.c aff.c check.c arrange.c

SRC_DIR = ./srcs

SRCS = $(addprefix $(SRC_DIR)/,$(SRC))

OBJS = $(SRCS:.c=.o)

WHITE =     \033[37;01m
RED =       \033[31;01m
GREEN =     \033[32;01m
YELLOW =    \033[33;01m
BLUE =      \033[34;01m
BASIC =     \033[0m

.PHONY: all clean fclean re

all : info $(NAME)

info :
	@if (! (test -e $(NAME) &&  test -e srcs/main.o));		\
	then													\
		echo "$(WHITE) Project: $(BASIC) $(NAME)";			\
		echo "$(WHITE) Flags: $(BASIC) $(FLAGS)";			\
		echo "$(WHITE) Compiler: $(BASIC) $(CC)";			\
	fi

%.o : %.c
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "$(BLUE) $< $(WHITE)->$(RED) $@ $(BASIC)"

$(NAME): $(OBJS)
	@echo "$(GREEN) ***** Make libft Begin ***** $(BASIC)"
	@make -C libft/
	@echo "$(GREEN) ***** Make libft End ***** $(BASIC)"
	@$(CC) $(FLAGS) $(LIBS) $(INC) $(OBJS) -o $(NAME)
	@echo "$(BLUE) objs $(WHITE)->$(RED) $@ $(BASIC)"

clean:
	@make -C libft/ clean
	@rm -rf $(OBJS)

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)

re: fclean all
