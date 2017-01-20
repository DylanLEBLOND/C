/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:53:47 by dle-blon          #+#    #+#             */
/*   Updated: 2016/02/01 19:13:11 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <wchar.h>

typedef struct	s_add
{
	int		min;
	int		max;
	int		hash;
	int		prflag;
	int		plflag;
	char	modflag;
	int		space;
	int		caps;
	int		pos;
	int 	cpt;	
}				t_add;

int				ft_printf(char const *str, ...);
int				ft_atoi(const char *str);
void			ft_putchar(char c, t_add *flags);
void			ft_putwchar(wchar_t c, t_add *flags);
void			ft_putstr(t_add *flag, char const *s);
void			ft_putwstr(t_add *flag, wint_t const *s);
unsigned int	ft_getsize(uintmax_t nb, unsigned int a);
void			ft_putnbr(uintmax_t n, t_add *flag);
void			ft_putnumber(t_add *flag, intmax_t n, uintmax_t m, unsigned int a);
char			*ft_strchr(const char *s, int c);
void			ft_strtrim(char *s, int pos, char c);
void			ft_trimdigit(char *s, int pos);
int				ft_isdigit(int c);
size_t			ft_strlen(char const *s);
size_t			ft_strwlen(wchar_t const *s);
char			*ft_strnew(size_t size);
wchar_t			*ft_strwnew(size_t size);
char			*ft_strdup(const char *s);
wchar_t			*ft_strwdup(const wchar_t *s);
char			*ft_strsub(char const *s, unsigned int start, size_t size);
void			initflags(t_add *add, int yes);
void			ft_getspace(char *str, int *pos, t_add *add);
void			ft_getmod(char *str, int *pos, t_add *add);
void			ft_getprec(char *str, int *pos, t_add *add);
void			ft_getprflags(char *str, int *pos, t_add *add);
void			base_int(t_add *flags, va_list *ap, char c);
void			base_char(t_add *flags, va_list *ap, char c);
void			base_oh(t_add *flags, va_list *ap, char c);
int				put_base_2(unsigned long long x, int b_p, int size, t_add *flag);
void			put64(unsigned long long x, t_add *flag);
void			encode64(char *s, t_add *flag);
void			call(t_add *flag, va_list *ap, char c, int pow);
int				space_zero2(t_add *flag, int n, int before, int base_power);
int				space_zero(t_add *flag, int n, int before, int base_power);
int				power(int x, int pow);
void			putvoid(void *s, t_add *flag);
#endif
