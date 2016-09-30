#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/22 19:20:53 by dle-blon          #+#    #+#              #
#    Updated: 2016/04/04 19:38:09 by dle-blon         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = poll_config
NAME_PRIMARY = primaire
NAME_SECONDARY = secondaire
NAME_TRAFFIC = trafic

CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDES = ./includes

SRC_SKELETON = error.c print.c ft_itoa.c
SRC_PRIMARY = primary_station.c
SRC_SECONDARY = secondary_station.c
SRC_TRAFFIC = traffic.c
SRC_INTERFACE = interface.c interface_primary.c interface_secondary.c \
				interface_traffic.c

SRCS_DIR = srcs

SRCS_SKELETON = $(addprefix $(SRCS_DIR)/,$(SRC_SKELETON))
SRCS_PRIMARY = $(addprefix $(SRCS_DIR)/,$(SRC_PRIMARY))
SRCS_SECONDARY = $(addprefix $(SRCS_DIR)/,$(SRC_SECONDARY))
SRCS_TRAFFIC = $(addprefix $(SRCS_DIR)/,$(SRC_TRAFFIC))
SRCS_INTERFACE = $(addprefix $(SRCS_DIR)/,$(SRC_INTERFACE))

OBJ_SKELETON = $(SRCS_SKELETON:.c=.o)
OBJ_PRIMARY = $(SRCS_PRIMARY:.c=.o)
OBJ_SECONDARY = $(SRCS_SECONDARY:.c=.o)
OBJ_TRAFFIC = $(SRCS_TRAFFIC:.c=.o)
OBJ_INTERFACE = $(SRCS_INTERFACE:.c=.o)

LIB_PRIMARY = ./primary.a
LIB_SECONDARY = ./secondary.a
LIB_TRAFFIC = ./traffic.a
LIB_INTERFACE = ./poll_config.a

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I $(INCLUDES) -c -o $@ $<

$(NAME): $(OBJ_SKELETON) $(OBJ_PRIMARY) $(OBJ_SECONDARY) $(OBJ_TRAFFIC) $(OBJ_INTERFACE)
	ar -r $(LIB_PRIMARY) $(OBJ_SKELETON) $(OBJ_PRIMARY)
	ar -r $(LIB_SECONDARY) $(OBJ_SKELETON) $(OBJ_SECONDARY)
	ar -r $(LIB_TRAFFIC) $(OBJ_SKELETON) $(OBJ_TRAFFIC)
	ar -r $(LIB_INTERFACE) $(OBJ_SKELETON) $(OBJ_INTERFACE)
	$(CC) $(FLAGS) $(LIB_PRIMARY) -I $(INCLUDES) -o $(NAME_PRIMARY)
	$(CC) $(FLAGS) $(LIB_SECONDARY) -I $(INCLUDES) -o $(NAME_SECONDARY)
	$(CC) $(FLAGS) $(LIB_TRAFFIC) -I $(INCLUDES) -o $(NAME_TRAFFIC)
	$(CC) $(FLAGS) $(LIB_INTERFACE) -I $(INCLUDES) -o $(NAME)

clean:
	rm -rf $(OBJ_SKELETON) $(OBJ_PRIMARY) $(OBJ_SECONDARY) $(OBJ_TRAFFIC) \
			$(OBJ_INTERFACE) $(LIB_PRIMARY) $(LIB_SECONDARY) $(LIB_TRAFFIC) \
			$(LIB_INTERFACE)

fclean: clean
	rm -rf $(NAME) $(NAME_PRIMARY) $(NAME_SECONDARY) $(NAME_TRAFFIC)

re: fclean all