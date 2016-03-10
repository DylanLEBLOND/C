/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pdecimala.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:57:10 by abary             #+#    #+#             */
/*   Updated: 2016/02/04 14:23:31 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdlib.h>

static char		*ft_con_a_flag_plus(char *str)
{
	char	*fr;
	char	*retour;
	char	*debut;

	fr = str;
	while (*str != 'x')
		++str;
	debut = ft_strndup(fr, str - fr + 1);
	retour = ft_strdup(str + 2);
	free(fr);
	fr = retour;
	retour = ft_strjoin(debut, retour);
	free(fr);
	free(debut);
	return (retour);
}

static char		*ft_con_a_flag_zero(char *str)
{
	char *fr;

	fr = str;
	++str;
	while (*str == '0')
		++str;
	*str = '0';
	str = str - (str - fr);
	*(str + 2) = 'x';
	return (fr);
}

static char		*ft_con_a_flag(char *format, int d, char *str,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	char	*fr;

	if (f_tab[DIGIT])
	{
		fr = str;
		str = f_tab[DIGIT](format, d, str);
		free(fr);
	}
	if (f_tab[ZERO])
	{
		str = f_tab[ZERO](format, d, str);
		if (*str == '-')
		{
			str = ft_con_a_flag_zero(str);
			f_tab[PLUS] = NULL;
		}
	}
	if (f_tab[PLUS])
	{
		str = f_tab[PLUS](format, d, str);
		if (*(str + 3) == '0')
			str = ft_con_a_flag_plus(str);
	}
	return (str);
}

char			*ft_con_a(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	char *str;

	str = ft_binary_double(va_arg(ap, double));
	str = ft_con_a_flag(format, d, str, f_tab);
	g_nbr += ft_strlen(str);
	return (str);
}
