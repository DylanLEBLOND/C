/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 14:34:38 by abary             #+#    #+#             */
/*   Updated: 2016/02/04 15:13:21 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <string.h>
# include <stdarg.h>
# include <wchar.h>
# define S_TAB_CON 16
# define S_TAB_FLAG 7
# define S_TAB_ARG 7
# define HASH 0
# define ZERO 1
# define MINUS 2
# define PLUS 3
# define SPACE 4
# define DIGIT 5
# define PRECISION 6
# define HH 3
# define LL 0
# define H 5
# define L 1
# define J 4
# define Z 2
# define CON 6
# define BITS7  0xffffff80
# define BITS11 0xfffff800
# define BITS16 0xffff0000
# define CHARNULL -1

long g_nbr;
typedef struct	s_con
{
	char		cara;
	char		*(*p)(char *, int, va_list,
			char *(*f_tab[S_TAB_FLAG])(char *, int, char *));
}				t_con;

typedef struct	s_flag
{
	char		cara;
	char		*(*p)(char *, int, char *);
}				t_flag;

typedef struct	s_arg
{
	char		*arg;
	char		*(*p)(va_list);
}				t_arg;

typedef struct	s_con_arg
{
	t_con		con[S_TAB_CON];
	t_flag		flag[S_TAB_FLAG];
	char		*(*f_tab[S_TAB_FLAG])(char *, int, char *);
}				t_con_arg;

typedef struct	s_string
{
	char		*str;
	char		*c;
}				t_string;

/*
** ----------------Conversion--------------------------//
*/
char			*ft_con_d(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *));
char			*ft_con_p(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *));
char			*ft_con_s(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *));
char			*ft_con_dd(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *));
char			*ft_con_u(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *));
char			*ft_con_uu(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *));
char			*ft_con_c(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *));
char			*ft_con_o(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *));
char			*ft_con_oo(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *));
char			*ft_con_x(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *));
char			*ft_con_xx(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *));
char			*ft_con_prct(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *));
char			*ft_con_ss(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *));
char			*ft_con_cc(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *));
char			*ft_con_a(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *));
/*
**	------------------------FLAGS----------------------
*/
char			*ft_flag_hash(char *format, int d, char *str);
char			*ft_flag_0(char *format, int d, char *str);
char			*ft_flag_minus(char *format, int d, char *str);
char			*ft_flag_plus(char *format, int d, char *str);
char			*ft_flag_space(char *format, int d, char *str);
char			*ft_flag_digit(char *format, int d, char *str);
char			*ft_flag_precision(char *format, int d, char *str);
char			*ft_flag_precisionss(char *format, int d, char *str);
char			*ft_recover_flags(char *str, va_list ap, t_con_arg con_arg,
		char *format);
/*
** ---------------------TAB----------------------
*/
void			ft_init_f_tab(char *(*f_tab[S_TAB_FLAG])(char *, int, char *));
void			ft_init_t_flag(t_flag *flag);
void			ft_init_t_con(t_con *con);
void			ft_init_f_clear(char *(*f_tab[S_TAB_FLAG])
		(char *, int, char *));
/*
** --------------------------Arg-------------------
*/
int				ft_init_t_arg(t_arg *arg, char con);
char			*ft_arg_hh(va_list ap);
char			*ft_arg_h(va_list ap);
char			*ft_arg_ll(va_list ap);
char			*ft_arg_l(va_list ap);
char			*ft_arg_j(va_list ap);
char			*ft_arg_z(va_list ap);
char			*ft_arg_d(va_list ap);
char			*ft_arg_lc(va_list ap);
char			*ft_arg_c(va_list ap);
char			*ft_arg_ls(va_list ap);
char			*ft_arg_s(va_list ap);
char			*ft_arg_ohh(va_list ap);
char			*ft_arg_oh(va_list ap);
char			*ft_arg_oll(va_list ap);
char			*ft_arg_ol(va_list ap);
char			*ft_arg_oj(va_list ap);
char			*ft_arg_oz(va_list ap);
char			*ft_arg_o(va_list ap);
char			*ft_arg_oohh(va_list ap);
char			*ft_arg_oo(va_list ap);
char			*ft_arg_uhh(va_list ap);
char			*ft_arg_u(va_list ap);
char			*ft_arg_xhh(va_list ap);
char			*ft_arg_xh(va_list ap);
char			*ft_arg_xll(va_list ap);
char			*ft_arg_xl(va_list ap);
char			*ft_arg_xj(va_list ap);
char			*ft_arg_xz(va_list ap);
char			*ft_arg_x(va_list ap);
char			*ft_arg_ddhh(va_list ap);
char			*ft_arg_ddh(va_list ap);
char			*ft_arg_ddll(va_list ap);
char			*ft_arg_ddl(va_list ap);
char			*ft_arg_ddj(va_list ap);
char			*ft_arg_ddz(va_list ap);
char			*ft_arg_dd(va_list ap);
void			ft_destruct(t_arg *arg);
/*
** --------------------OTHERS------------------
*/
void			ft_init_t_argc(t_arg *arg);
void			ft_init_t_args(t_arg *arg);
void			ft_init_t_argo(t_arg *arg);
void			ft_init_t_argoo(t_arg *arg);
void			ft_init_t_argx(t_arg *arg);
void			ft_destruct(t_arg *arg);
char			*ft_widechar(wchar_t wide, char *dest);
char			*ft_wide11(wchar_t wide, char *dest);
char			*ft_wide16(wchar_t wide, char *dest);
char			*ft_wide(wchar_t wide, char *dest);
char			*ft_convert_wide(wchar_t *wide);
char			*ft_con_nothing(char **format, int d,
				char *(*f_tab[S_TAB_FLAG])(char *, int, char *));
char			*ft_fill_f_tab(char *(*f_tab[S_TAB_FLAG])(char *, int, char *),
				char *format, t_flag *flag);
char			*ft_search_ap(char *format, int d, va_list ap, char letter);
#endif
