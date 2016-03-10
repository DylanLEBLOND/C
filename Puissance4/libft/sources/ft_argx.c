/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:08:13 by abary             #+#    #+#             */
/*   Updated: 2016/01/29 15:48:04 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

char	*ft_arg_xhh(va_list ap)
{
	char			*str;
	unsigned char	d;

	str = NULL;
	d = va_arg(ap, unsigned int);
	if (!(str = ft_ultoa_base(d, 16)))
		return (NULL);
	return (str);
}

char	*ft_arg_xh(va_list ap)
{
	char			*str;
	unsigned short	d;

	str = NULL;
	d = va_arg(ap, unsigned int);
	if (!(str = ft_ultoa_base(d, 16)))
		return (NULL);
	return (str);
}

char	*ft_arg_xll(va_list ap)
{
	char	*str;

	str = NULL;
	if (!(str = ft_ultoa_base(va_arg(ap, unsigned long long), 16)))
		return (NULL);
	return (str);
}

char	*ft_arg_xl(va_list ap)
{
	char	*str;

	str = NULL;
	if (!(str = ft_ultoa_base(va_arg(ap, unsigned long), 16)))
		return (NULL);
	return (str);
}

char	*ft_arg_xj(va_list ap)
{
	char	*str;

	str = NULL;
	if (!(str = ft_ultoa_base(va_arg(ap, uintmax_t), 16)))
		return (NULL);
	return (str);
}
