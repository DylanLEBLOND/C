/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recoverflags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 18:06:45 by abary             #+#    #+#             */
/*   Updated: 2016/02/04 15:11:33 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"
#include "libft.h"
#include <stdlib.h>

static char		*ft_join_free(char *s, char *str)
{
	char	*chr;

	chr = NULL;
	if (g_nbr == CHARNULL)
	{
		g_nbr = ft_strlen(str) + 1 + ft_strlen(s);
		ft_putstr(str);
		ft_putstr(s);
		free(str);
		free(s);
		ft_putchar(0);
		str = ft_strdup("\0");
		return (str);
	}
	if (str)
		chr = str;
	if (!(str = ft_strjoin(str, s)))
		return (NULL);
	free(s);
	if (chr)
		free(chr);
	return (str);
}

static char		*ft_joinn_free(char *str, char **format)
{
	char *chr;
	char *c;

	chr = NULL;
	c = *format;
	while (**format && **format != '%')
	{
		++*format;
		++g_nbr;
	}
	if (str)
		chr = str;
	if (!(str = ft_strnjoin(str, *format - (*format - c + 1), *format - c + 1)))
		return (NULL);
	free(chr);
	--*format;
	++g_nbr;
	return (str);
}

static	char	*ft_manage_con(char **tab, char **str,
		va_list ap, t_con_arg con_arg)
{
	int		i;
	char	*format;
	char	*c;

	c = tab[1];
	format = tab[0];
	i = -1;
	while (++i < S_TAB_CON)
	{
		if (*format == con_arg.con[i].cara)
		{
			if (!(*str = ft_join_free(con_arg.con[i].p(format, format - c, ap,
								con_arg.f_tab), *str)))
				return (NULL);
			break ;
		}
		if (i == S_TAB_CON - 1)
		{
			if (!(*str = ft_join_free(ft_con_nothing(&c, format - c,
								con_arg.f_tab), *str)))
				return (NULL);
			format = c;
		}
	}
	return (format);
}

char			*ft_recover_flags(char *str, va_list ap, t_con_arg con_arg,
		char *format)
{
	char	*tab[2];

	tab[0] = format;
	tab[1] = NULL;
	while (*format)
	{
		if (*(format++) == '%')
		{
			tab[1] = format;
			format = ft_fill_f_tab(con_arg.f_tab, format, con_arg.flag);
			tab[0] = format;
			if (!(format = ft_manage_con(tab, &str, ap, con_arg)))
				return (NULL);
		}
		else if (!(str = ft_joinn_free(str, &format)))
			return (NULL);
		++format;
	}
	return (str);
}
