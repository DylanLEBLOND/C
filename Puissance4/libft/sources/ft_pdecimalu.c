/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pdecimalu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:10:50 by abary             #+#    #+#             */
/*   Updated: 2016/02/04 17:50:00 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdlib.h>

char	*ft_con_u_flag(char *format, int d, char *str,
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

char	*ft_con_u(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	char			*str;
	int				i;

	ft_init_f_clear(f_tab);
	i = -1;
	str = NULL;
	if (!(str = ft_search_ap(format, d, ap, 'u')))
		return (NULL);
	str = ft_con_u_flag(format, d, str, f_tab);
	g_nbr += ft_strlen(str);
	return (str);
}

char	*ft_con_uu(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	char			*str;
	int				i;
	char			*fr;

	i = -1;
	str = NULL;
	if (!(str = ft_ultoa(va_arg(ap, unsigned long))))
		return (NULL);
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
	g_nbr += ft_strlen(str);
	return (str);
}
