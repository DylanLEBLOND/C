/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwide.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 19:06:36 by abary             #+#    #+#             */
/*   Updated: 2016/02/02 16:39:29 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

static char	*ft_pwidep1(char *str, int *i, int *mem)
{
	if (!(*(str + ++*i) && *(str + *i) & 0x80 && *(str + ++*i)
				& 0x80 && *(str + ++*i) & 0x80))
		while (*(str + *mem))
			*(str + *mem) = '\0';
	return (str);
}

static char	*ft_pwidep2(char *str, int *i, int *mem)
{
	if (!(*(str + ++*i) && *(str + *i) & 0x80 && *(str + ++*i) & 0x80))
		while (*(str + *mem))
			*(str + *mem) = '\0';
	return (str);
}

static char	*ft_pwidep(char *str)
{
	int i;
	int mem;

	i = 0;
	while (*(str + i))
	{
		mem = i;
		if ((*(str + i) & 0xF0) == 0xF0)
			str = ft_pwidep1(str, &i, &mem);
		else if ((*(str + i) & 0xE0) == 0xE0)
			str = ft_pwidep2(str, &i, &mem);
		else if ((*(str + i) & 0xC0) == 0xC0)
		{
			if (!(*(str + ++i) && *(str + i) & 0x80))
				while (*(str + mem))
					*(str + mem) = '\0';
		}
		else
			++i;
		if (*(str + mem) == '\0')
			break ;
	}
	return (str);
}

char		*ft_con_ss(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	char	*str;
	wchar_t *wide;
	char	*fr;
	char	*strfr;

	fr = NULL;
	strfr = NULL;
	wide = va_arg(ap, wchar_t *);
	if (!(str = ft_convert_wide(wide)))
		return (NULL);
	if (f_tab[PRECISION])
	{
		str = ft_flag_precisionss(format, d, str);
		str = ft_pwidep(str);
	}
	if (f_tab[DIGIT])
		str = f_tab[DIGIT](format, d, str);
	if (f_tab[ZERO])
		str = f_tab[ZERO](NULL, d, str);
	if (f_tab[MINUS])
		str = f_tab[MINUS](format, d, str);
	g_nbr += ft_strlen(str);
	return (str);
}
