# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abary <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 12:31:57 by abary             #+#    #+#              #
#    Updated: 2016/02/28 20:09:25 by abary            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = puissance4

INC_DIR = includes

LIB_DIR = libft

INC_LIB_DIR = $(LIB_DIR)/$(INC_DIR)

NAME_LIB = puissance4.a\

CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR) -I $(INC_LIB_DIR)
#CFLAGS = -I$(INC_DIR) -I $(INC_LIB_DIR)

SRC = main.c ft_chechk_args.c ft_display_error.c ft_board.c ft_rand_player.c\
	  ft_display_board.c ft_recup_input.c ft_puissance4.c ft_check_winner.c\
	  ft_check.c ft_check_diagonal.c ft_check_line_col.c ft_ia.c menu.c\
	  ft_display_menu.c ft_free_line.c ft_display_result.c ft_max.c \
	  ft_check_victory.c ft_ia_norme.c

SRCS = $(addprefix sources/,$(SRC))

OBJ = $(SRCS:.c=.o)
CC = gcc
all : $(NAME)

$(NAME) : $(OBJ)
	(cd $(LIB_DIR) && $(MAKE))
	ar -r $(NAME_LIB) $(OBJ)
	gcc -o $(NAME) puissance4.a $(NAME_LIB) libft/libft.a

clean :
	(cd $(LIB_DIR) && make clean && cd ..)
	rm -rf $(OBJ)

fclean : clean
	(cd $(LIB_DIR) && make fclean && cd ..)
	rm -rf $(NAME)
	rm -rf $(NAME_LIB)

re : fclean all

.PHONY: all clean flcean re
