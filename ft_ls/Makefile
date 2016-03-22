SRCS = 	srcs/main.c srcs/error.c srcs/getinfo.c srcs/ft_ls.c srcs/aff.c \
		srcs/check.c srcs/arrange.c

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

LIB = ft_ls.a libft/libft.a

NAME = ft_ls

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	ar -r $(LIB) $(OBJ)
	gcc $(FLAGS) $(LIB) -o $(NAME)

clean:
	make -C libft/ clean
	rm -rf $(OBJ)
	
fclean: clean
	make -C libft/ fclean
	rm -rf $(LIB) $(NAME)
	
re: fclean all