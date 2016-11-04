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

NAME = poll_config
NAME_PRIMARY = primaire
NAME_SECONDARY = secondaire
NAME_TRAFFIC = trafic

CC = gcc

FLAGS = -Wall -Wextra -Werror

INC = -I ./includes

SRC_COMMON = common/error.c common/print.c common/ft_itoa.c
SRC_PRIMARY = stations/primary_station.c
SRC_SECONDARY = stations/secondary_station.c
SRC_TRAFFIC = stations/traffic.c
SRC_POLL =	interface/interface.c interface/interface_primary.c \
			interface/interface_secondary.c interface/interface_traffic.c

SRC_DIR = ./srcs

SRCS_COMMON = $(addprefix $(SRC_DIR)/,$(SRC_COMMON))
SRCS_PRIMARY = $(addprefix $(SRC_DIR)/,$(SRC_PRIMARY))
SRCS_SECONDARY = $(addprefix $(SRC_DIR)/,$(SRC_SECONDARY))
SRCS_TRAFFIC = $(addprefix $(SRC_DIR)/,$(SRC_TRAFFIC))
SRCS_POLL = $(addprefix $(SRC_DIR)/,$(SRC_POLL))

OBJS_COMMON = $(SRCS_COMMON:.c=.o)
OBJS_PRIMARY = $(SRCS_PRIMARY:.c=.o)
OBJS_SECONDARY = $(SRCS_SECONDARY:.c=.o)
OBJS_TRAFFIC = $(SRCS_TRAFFIC:.c=.o)
OBJS_POLL = $(SRCS_POLL:.c=.o)

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

$(NAME): $(OBJS_COMMON) $(OBJS_PRIMARY) $(OBJS_SECONDARY) $(OBJS_TRAFFIC) $(OBJS_POLL)
	@$(CC) $(FLAGS) $(LIBS) $(INC) $(OBJS_PRIMARY) $(OBJS_COMMON) -o $(NAME_PRIMARY)
	@echo "$(BLUE) objs primary $(WHITE)->$(RED) $(NAME_PRIMARY) $(BASIC)"

	@$(CC) $(FLAGS) $(LIBS) $(INC) $(OBJS_SECONDARY) $(OBJS_COMMON) -o $(NAME_SECONDARY)
	@echo "$(BLUE) objs secondary $(WHITE)->$(RED) $(NAME_SECONDARY) $(BASIC)"

	@$(CC) $(FLAGS) $(LIBS) $(INC) $(OBJS_TRAFFIC) $(OBJS_COMMON) -o $(NAME_TRAFFIC)
	@echo "$(BLUE) objs trafic $(WHITE)->$(RED) $(NAME_TRAFFIC) $(BASIC)"

	@$(CC) $(FLAGS) $(LIBS) $(INC) $(OBJS_POLL) $(OBJS_COMMON) -o $(NAME)
	@echo "$(BLUE) objs poll $(WHITE)->$(RED) $@ $(BASIC)"

clean:
	@rm -rf $(OBJS_COMMON) $(OBJS_PRIMARY) $(OBJS_SECONDARY) $(OBJS_TRAFFIC) $(OBJS_POLL)

fclean: clean
	@rm -rf $(NAME) $(NAME_PRIMARY) $(NAME_SECONDARY) $(NAME_TRAFFIC)

re: fclean all
