/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 19:10:10 by abary             #+#    #+#             */
/*   Updated: 2016/02/02 18:46:38 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdlib.h>

char	*ft_con_c_flag(char *format, int d, char *str,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	if (f_tab[DIGIT])
		str = f_tab[DIGIT](format, d, str);
	if (f_tab[ZERO])
		str = f_tab[ZERO](format, d, str);
	if (f_tab[MINUS])
		str = f_tab[MINUS](format, d, str);
	return (str);
}

char	*ft_con_c(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	char	*str;
	int		c;
	char	*zero;

	zero = NULL;
	if (ft_strchrstr(format - d, "l", 'c'))
		return (str = ft_con_cc(format, d, ap, f_tab));
	c = (va_arg(ap, int));
	str = ft_strnew(2);
	str = ft_memset(str, c, 1);
	str = ft_con_c_flag(format, d, str, f_tab);
	if (!c && (g_nbr = CHARNULL))
	{
		if (*str)
		{
			zero = ft_strnew(ft_strlen(str) - 1);
			zero = ft_strncat(zero, str, ft_strlen(str) - 1);
			free(str);
			return (zero);
		}
	}
	if (g_nbr != CHARNULL)
		g_nbr += ft_strlen(str);
	return (str);
}
