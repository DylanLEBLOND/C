/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:51:44 by abary             #+#    #+#             */
/*   Updated: 2016/02/04 17:37:12 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

char	*ft_arg_oohh(va_list ap)
{
	char			*str;
	unsigned long	d;

	str = NULL;
	d = va_arg(ap, unsigned long);
	if (!(str = ft_ultoa_base(d, 8)))
		return (NULL);
	return (str);
}

char	*ft_arg_oo(va_list ap)
{
	char			*str;

	str = NULL;
	if (!(str = ft_ultoa_base(va_arg(ap, unsigned long), 8)))
		return (NULL);
	return (str);
}

char	*ft_arg_oz(va_list ap)
{
	char *str;

	str = NULL;
	if (!(str = ft_ultoa_base(va_arg(ap, size_t), 8)))
		return (NULL);
	return (str);
}

char	*ft_arg_o(va_list ap)
{
	char		*str;

	str = NULL;
	if (!(str = ft_utoa_base(va_arg(ap, unsigned int), 8)))
		return (NULL);
	return (str);
}
