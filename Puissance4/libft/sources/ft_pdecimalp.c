/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pdecimalp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:05:43 by abary             #+#    #+#             */
/*   Updated: 2016/02/04 17:46:55 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdlib.h>

static char	*ft_p_flag_zero(char *chr, char *str, int i)
{
	char	*zero;

	i = i - ft_strlen(chr);
	zero = ft_strnew(i + 1);
	zero = ft_memset(zero, '0', i);
	str = ft_strjoin(zero, chr);
	str = ft_strjoin("0x", str);
	zero = NULL;
	return (str);
}

static char	*ft_p_flag_space(char *str, int n)
{
	char	*zero;

	n = n - ft_strlen(str);
	zero = ft_strnew(n + 1);
	zero = ft_memset(zero, ' ', n);
	str = ft_strjoin(zero, str);
	zero = NULL;
	return (str);
}

static char	*ft_con_p_precision(char *format, char *str, int d)
{
	int		i;
	int		n;
	char	*chr;

	i = 0;
	n = 0;
	if (ft_strlen(str) == 3 && *(str + 2) == '0' && ft_atoi(format - d) == 0)
		str = ft_strdup("0x");
	n = ft_atoi(format - d);
	if (n > 0 && n > (int)ft_strlen(str))
		str = ft_p_flag_space(str, n);
	else
	{
		while (*(format - i) != '.')
			++i;
		i = ft_atoi(format - --i);
		n = 0;
		while (*(str + n) != 'x')
			++n;
		chr = str + n + 1;
		if (i > 0 && i > (int)ft_strlen(chr))
			str = ft_p_flag_zero(chr, str, i);
	}
	return (str);
}

char		*ft_con_p(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	char			*str;
	char			*chr;
	char			*fr;

	str = ft_ultoa_base(va_arg(ap, unsigned long), 16);
	chr = str;
	str = ft_strjoin("0x", str);
	free(chr);
	if (f_tab[PRECISION])
		str = ft_con_p_precision(format, str, d);
	else
	{
		if (f_tab[DIGIT])
		{
			fr = str;
			str = f_tab[DIGIT](format, d, str);
			free(fr);
			if (f_tab[ZERO])
				str = f_tab[ZERO](format, d, str);
			if (f_tab[MINUS])
				str = f_tab[MINUS](format, d, str);
		}
	}
	g_nbr += ft_strlen(str);
	return (str);
}
