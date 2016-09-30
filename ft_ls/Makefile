#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/22 19:20:53 by dle-blon          #+#    #+#              #
#    Updated: 2016/04/04 19:38:09 by dle-blon         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls

CC = gcc

FLAGS = -Wall -Wextra -Werror

INCLUDES = ./includes

LIB_INCLUDES = ./libft/includes/

SRC = 	main.c error.c getinfo.c ft_ls.c \
		aff.c check.c arrange.c

SRC_DIR = srcs

SRCS = $(addprefix $(SRC_DIR)/,$(SRC))

OBJ = $(SRCS:.c=.o)

NAME_LIB = ./ft_ls.a

LIBS = $(NAME_LIB) ./libft/libft.a


all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -I $(INCLUDES) -I $(LIB_INCLUDES) -c -o $@ $<

$(NAME): $(OBJ)
	make -C libft/
	@ar -r $(NAME_LIB) $(OBJ)
	@$(CC) $(FLAGS) $(LIBS) -I $(INCLUDES) -I $(LIB_INCLUDES) -o $(NAME)

clean:
	make -C libft/ clean
	@rm -rf $(OBJ) $(NAME_LIB)

fclean: clean
	make -C libft/ fclean
	@rm -rf $(NAME)

re: fclean all
