# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abary <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 12:31:57 by abary             #+#    #+#              #
#    Updated: 2016/02/26 21:42:39 by abary            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC_DIR = includes

CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR)

SRC = ft_strlen.c\
		ft_strstr.c\
		ft_strcpy.c\
		ft_strdup.c\
		ft_strcat.c\
		ft_strcmp.c\
		ft_strncpy.c\
		ft_strncat.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strnstr.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_itoa.c\
		ft_putendl.c\
		ft_putnbr.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_putstr_fd.c\
		ft_memalloc.c\
		ft_lstadd_end.c\
		ft_abs.c\
		ft_strrev.c\
		ft_printbit.c\
		ft_putnbr_base.c\
		ft_strndup.c\
		ft_strnjoin.c\
		ft_lstclean.c\
		ft_itoa_base.c\
		ft_putdouble.c\
		ft_power.c\
		ft_printf.c\
		ft_recoverflags.c\
		ft_init_t_flags.c\
		ft_init_t_con.c\
		ft_flag.c\
		ft_pdecimal.c\
		ft_ultoa_adresse.c\
		ft_pstr.c\
		ft_utoa.c\
		ft_strtoupper.c\
		ft_init_t_arg.c\
		ft_ltoa.c\
		ft_imtoa.c\
		ft_arg.c\
		ft_argc.c\
		ft_argu.c\
		ft_argx.c\
		ft_ultoa.c\
		ft_strchrstr.c\
		ft_managewdchar.c\
		ft_pnohting.c\
		ft_argdd.c\
		ft_ltoa_base.c\
		ft_argoo.c\
		ft_argo.c\
		ft_utoa_base.c\
		ft_arg1.c\
		ft_argx2.c\
		ft_pwide.c\
		ft_pchar.c\
		ft_pwidechar.c\
		ft_pfill_tab.c\
		ft_pdecimalp.c\
		ft_pdecimalo.c\
		ft_pdecimalu.c\
		ft_searhc_ap.c\
		ft_pmaskwide.c\
		ft_init_t_arg1.c\
		ft_pdescrut_arg.c\
		ft_flag0.c\
		ft_flagplus.c\
		ft_flagprecision.c\
		ft_flagprecisions.c\
		ft_pdecimala.c\
		ft_udouble_binary.c\
		ft_pdecimalx.c\
		ft_lst_swap.c\
		ft_ls_addtri_char.c\
		get_next_line.c\
		ft_printf_error.c\
		ft_atol.c

SRCS = $(addprefix sources/,$(SRC))

OBJ = $(SRCS:.c=.o)

$(NAME) : $(OBJ)
	ar -r $(NAME) $(OBJ)
	ranlib $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean flcean re
