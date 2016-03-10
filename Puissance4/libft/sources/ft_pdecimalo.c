/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pdecimalo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:07:26 by abary             #+#    #+#             */
/*   Updated: 2016/02/04 17:48:52 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdlib.h>

static char	*ft_con_o_flag(char *format, int d, char *str,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	if (f_tab[HASH])
		str = f_tab[HASH](format, 2, str);
	if (f_tab[PRECISION])
	{
		str = f_tab[PRECISION](format, d, str);
		if (!*str && f_tab[HASH])
			str = ft_strdup("0");
	}
	if (f_tab[DIGIT])
		str = f_tab[DIGIT](format, d, str);
	if (f_tab[ZERO])
		str = f_tab[ZERO](format, d, str);
	if (f_tab[MINUS])
		str = f_tab[MINUS](format, d, str);
	return (str);
}

char		*ft_con_o(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	int				i;
	char			*str;

	ft_init_f_clear(f_tab);
	i = -1;
	str = NULL;
	if (!(str = ft_search_ap(format, d, ap, 'o')))
		return (NULL);
	str = ft_con_o_flag(format, d, str, f_tab);
	g_nbr += ft_strlen(str);
	return (str);
}

char		*ft_con_oo(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	int				i;
	char			*str;
	char			*fr;

	ft_init_f_clear(f_tab);
	i = -1;
	str = NULL;
	if (!(str = ft_search_ap(format, d, ap, 'O')))
		return (NULL);
	if (f_tab[PRECISION])
		str = f_tab[PRECISION](format, d, str);
	if (f_tab[HASH])
		str = f_tab[HASH](format, 2, str);
	if (f_tab[DIGIT] && (fr = str))
	{
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
