#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/03 18:22:49 by dle-blon          #+#    #+#              #
#    Updated: 2015/04/03 18:22:53 by dle-blon         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap

FLAGS = -Wall -Wextra -Werror

FILES = ./src/push_swap.c ./src/moove.c ./src/init.c ./src/algo.c \
        ./src/error.c ./src/useless.c ./src/lib.c ./src/options.c


all : $(NAME)

$(NAME) : $(FILES)
	@gcc $(FLAGS) $(FILES) -o $(NAME)

clean :
	@touch useless; rm -r useless

fclean : clean
	@rm -f $(NAME)

re : fclean all