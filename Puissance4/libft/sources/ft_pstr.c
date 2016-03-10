/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 16:18:29 by abary             #+#    #+#             */
/*   Updated: 2016/02/04 17:32:24 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"
#include "libft.h"
#include <wchar.h>

char	*ft_con_s_flag(char *str, int d, char *format,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	if (f_tab[MINUS])
		f_tab[ZERO] = NULL;
	if (f_tab[PRECISION] && str)
		str = ft_flag_precisionss(format, d, str);
	if (f_tab[DIGIT] && str)
		str = f_tab[DIGIT](format, d, str);
	if (f_tab[ZERO] && str)
		str = f_tab[ZERO](NULL, d, str);
	if (f_tab[MINUS] && str)
		str = f_tab[MINUS](format, d, str);
	return (str);
}

char	*ft_con_s(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	char *str;

	if (ft_strchrstr(format - d, "l", 's'))
		return (str = ft_con_ss(format, d, ap, f_tab));
	str = va_arg(ap, char *);
	if (!str)
	{
		if (!f_tab[PRECISION])
		{
			str = ft_strdup("(null)");
			g_nbr += ft_strlen(str);
			return (str);
		}
		str = ft_strdup("\0");
	}
	if (!(str = ft_strdup(str)))
		return (NULL);
	if (!(str = ft_con_s_flag(str, d, format, f_tab)))
		return (NULL);
	g_nbr += ft_strlen(str);
	return (str);
}

int		ft_con_prct_flag(char *format, int d, char **str,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	int yes;

	yes = 0;
	if (f_tab[PRECISION] && str)
		yes = 1;
	if (f_tab[PLUS] && str && (yes = 1))
		*str = f_tab[PLUS](format, d, *str);
	if (f_tab[DIGIT] && str && (yes = 1))
		*str = f_tab[DIGIT](format, d, *str);
	if (f_tab[ZERO] && str && (yes = 1))
		*str = f_tab[ZERO](format, d, *str);
	if (f_tab[SPACE] && str && (yes = 1))
		*str = *str;
	if (f_tab[MINUS] && str && (yes = 1))
		*str = f_tab[MINUS](format, d, *str);
	return (yes);
}

char	*ft_con_prct(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	char *str;

	ap = NULL;
	if (f_tab[MINUS])
		f_tab[ZERO] = NULL;
	str = ft_strdup("%");
	if (*(format) == '%' && d == 0)
	{
		g_nbr += 1;
		return (str);
	}
	if (!ft_con_prct_flag(format, d, &str, f_tab))
	{
		free(str);
		str = ft_strdup("\0");
	}
	g_nbr += ft_strlen(str);
	return (str);
}
