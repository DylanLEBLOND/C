SRCS = srcs/main.c

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

LIB = ft_ls.a

NAME = ft_ls

all: $(NAME)

$(NAME): $(OBJ)
	ar -r $(LIB) $(OBJ)
	gcc $(FLAGS) $(LIB) -o $(NAME)

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(LIB) $(NAME)