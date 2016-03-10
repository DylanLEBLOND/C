/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwidechar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 19:11:22 by abary             #+#    #+#             */
/*   Updated: 2016/02/04 17:41:00 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

char	*ft_con_cc(char *format, int d, va_list ap,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	char			*str;
	wchar_t			wide[2];

	wide[0] = (va_arg(ap, wchar_t));
	wide[1] = L'\0';
	if (!wide[0])
	{
		g_nbr = CHARNULL;
		return (ft_strdup("\0"));
	}
	if (!(str = ft_convert_wide(wide)))
		return (NULL);
	if (f_tab[DIGIT])
		str = f_tab[DIGIT](format, d, str);
	if (f_tab[ZERO])
		str = f_tab[ZERO](format, d, str);
	if (f_tab[MINUS])
		str = f_tab[MINUS](format, d, str);
	g_nbr += ft_strlen(str);
	return (str);
}
