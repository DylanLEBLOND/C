/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pdecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 12:12:45 by abary             #+#    #+#             */
/*   Updated: 2016/02/04 17:25:55 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"
#include "libft.h"

static char	*ft_con_d_flag(char *format, int d, char *str,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	char *fr;

	fr = str;
	if (f_tab[PRECISION])
		str = f_tab[PRECISION](format, d, str);
	if (f_tab[PLUS])
		str = f_tab[PLUS](format, d, str);
	if (f_tab[DIGIT])
	{
		fr = str;
		str = f_tab[DIGIT](format, d, str);
		free(fr);
	}
	if (f_tab[ZERO])
		str = f_tab[ZERO](format, d, str);
	if (f_tab[SPACE])
		str = f_tab[SPACE](format, d, str);
	if (f_tab[MINUS])
		str = f_tab[MINUS](format, d, str);
	return (str);
}

char		*ft_con_d(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	char			*str;
	int				i;

	ft_init_f_clear(f_tab);
	i = -1;
	str = NULL;
	if (!(str = ft_search_ap(format, d, ap, 'd')))
		return (NULL);
	str = ft_con_d_flag(format, d, str, f_tab);
	g_nbr += ft_strlen(str);
	return (str);
}

static char	*ft_con_dd_flag(char *format, int d, char *str,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	char	*fr;

	if (f_tab[PRECISION])
		str = f_tab[PRECISION](format, d, str);
	if (f_tab[DIGIT])
	{
		fr = str;
		str = f_tab[DIGIT](format, d, str);
		free(fr);
	}
	if (f_tab[ZERO])
		str = f_tab[ZERO](format, d, str);
	if (f_tab[MINUS])
		str = f_tab[MINUS](format, d, str);
	return (str);
}

char		*ft_con_dd(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	char			*str;
	int				i;

	ft_init_f_clear(f_tab);
	i = -1;
	str = NULL;
	if (!(str = ft_search_ap(format, d, ap, 'D')))
		return (NULL);
	g_nbr += ft_strlen(str);
	str = ft_con_dd_flag(format, d, str, f_tab);
	return (str);
}
