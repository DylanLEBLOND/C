#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/22 19:20:53 by dle-blon          #+#    #+#              #
#    Updated: 2016/10/27 21:37:54 by dle-blon         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls

CC = gcc

FLAGS = -Wall -Wextra -Werror

INC = -I ./includes -I ./libft/includes/

SRC = 	main.c error.c getinfo.c ft_ls.c aff.c check.c arrange.c

SRC_DIR = ./srcs

SRCS = $(addprefix $(SRC_DIR)/,$(SRC))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<

$(NAME): $(OBJS)
	make -C libft/
	$(CC) $(FLAGS) $(LIBS) $(INC) $(OBJS) -o $(NAME)

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all
