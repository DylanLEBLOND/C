/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argdd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:25:08 by abary             #+#    #+#             */
/*   Updated: 2016/01/29 15:26:15 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

char	*ft_arg_ddhh(va_list ap)
{
	char			*str;
	unsigned int	d;

	str = NULL;
	d = va_arg(ap, unsigned int);
	if (!(str = ft_ultoa(d)))
		return (NULL);
	return (str);
}

char	*ft_arg_ddh(va_list ap)
{
	char			*str;
	unsigned short	d;

	str = NULL;
	d = va_arg(ap, unsigned int);
	if (!(str = ft_utoa(d)))
		return (NULL);
	return (str);
}

char	*ft_arg_ddll(va_list ap)
{
	char	*str;

	str = NULL;
	if (!(str = ft_ultoa(va_arg(ap, unsigned long long))))
		return (NULL);
	return (str);
}

char	*ft_arg_ddl(va_list ap)
{
	char	*str;

	str = NULL;
	if (!(str = ft_ultoa(va_arg(ap, unsigned long))))
		return (NULL);
	return (str);
}

char	*ft_arg_ddj(va_list ap)
{
	char	*str;

	str = NULL;
	if (!(str = ft_ultoa(va_arg(ap, uintmax_t))))
		return (NULL);
	return (str);
}
