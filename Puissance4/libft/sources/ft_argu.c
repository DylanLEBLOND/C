/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:23:21 by abary             #+#    #+#             */
/*   Updated: 2016/02/01 15:03:56 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

char	*ft_arg_uhh(va_list ap)
{
	char			*str;
	unsigned char	d;

	str = NULL;
	d = va_arg(ap, unsigned int);
	if (!(str = ft_utoa(d)))
		return (NULL);
	return (str);
}

char	*ft_arg_ddz(va_list ap)
{
	char	*str;

	str = NULL;
	if (!(str = ft_ultoa(va_arg(ap, size_t))))
		return (NULL);
	return (str);
}

char	*ft_arg_dd(va_list ap)
{
	char			*str;
	unsigned long	d;

	str = NULL;
	d = va_arg(ap, unsigned long);
	str = ft_ltoa(d);
	return (str);
}

char	*ft_arg_u(va_list ap)
{
	char	*str;

	if (!(str = ft_utoa(va_arg(ap, unsigned int))))
		return (NULL);
	return (str);
}
