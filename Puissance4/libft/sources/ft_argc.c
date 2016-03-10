/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:33:13 by abary             #+#    #+#             */
/*   Updated: 2016/01/29 15:43:50 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <sys/_types/_wint_t.h>
#include <wchar.h>

char	*ft_arg_lc(va_list ap)
{
	char	*str;
	wint_t	d;

	str = NULL;
	d = va_arg(ap, wint_t);
	if (!(str = ft_itoa(d)))
		return (NULL);
	return (str);
}

char	*ft_arg_c(va_list ap)
{
	char	*str;

	str = NULL;
	if (!(str = ft_itoa(va_arg(ap, int))))
		return (NULL);
	return (str);
}

char	*ft_arg_ls(va_list ap)
{
	char	*str;
	wchar_t	d;

	str = NULL;
	d = va_arg(ap, wchar_t);
	if (!(str = ft_itoa(d)))
		return (NULL);
	return (str);
}

char	*ft_arg_s(va_list ap)
{
	char	*str;

	str = NULL;
	if (!(str = ft_strdup(va_arg(ap, char *))))
		return (NULL);
	return (str);
}
