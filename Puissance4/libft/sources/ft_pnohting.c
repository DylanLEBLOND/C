/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnohting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 15:43:25 by abary             #+#    #+#             */
/*   Updated: 2016/02/03 16:48:46 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

char	*ft_con_nothing(char **format, int d,
		char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	char *str;
	char *fr;

	d = 0;
	while (1)
	{
		if (*(*format - d) == '%')
			break ;
		++d;
	}
	fr = *format - d + 1;
	while ((**format == ' ' || ft_isdigit(**format) || **format == '.' ||
				**format == '-' || **format == 'h' || **format == 'l' ||
				**format == 'z' || **format == 'j') &&
			**format && **format != '%')
		++*format;
	str = ft_strndup(*format, 1);
	if (f_tab[DIGIT])
		str = f_tab[DIGIT](fr, 0, str);
	if (f_tab[MINUS])
		str = f_tab[MINUS](fr, d, str);
	if (f_tab[ZERO])
		str = f_tab[ZERO](fr, d, str);
	g_nbr += ft_strlen(str);
	return (str);
}
