/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pdecimalx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:03:29 by abary             #+#    #+#             */
/*   Updated: 2016/02/04 17:59:54 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

static char		*ft_con_x_flag(char *format, int d, char *str,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	if (f_tab[HASH])
		str = f_tab[HASH](format, 3, str);
	if (f_tab[DIGIT])
		str = f_tab[DIGIT](format, d, str);
	if (f_tab[ZERO])
		str = f_tab[ZERO](format, d, str);
	if (f_tab[MINUS])
		str = f_tab[MINUS](format, d, str);
	return (str);
}

char			*ft_con_x(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	char			*str;
	int				i;

	i = -1;
	str = NULL;
	ft_init_f_clear(f_tab);
	if (!(str = ft_search_ap(format, d, ap, 'x')))
		return (NULL);
	if (f_tab[PRECISION])
	{
		str = f_tab[PRECISION](format, d, str);
		if (ft_strlen(str) == 0)
			f_tab[HASH] = NULL;
	}
	str = ft_con_x_flag(format, d, str, f_tab);
	g_nbr += ft_strlen(str);
	return (str);
}

char			*ft_con_xx(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	char			*str;

	str = ft_con_x(format, d, ap, f_tab);
	str = ft_strtoupper(str);
	return (str);
}
