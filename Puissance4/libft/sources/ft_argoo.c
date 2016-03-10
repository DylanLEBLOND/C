/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argoo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:34:44 by abary             #+#    #+#             */
/*   Updated: 2016/01/29 15:55:13 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

char	*ft_arg_ohh(va_list ap)
{
	char			*str;
	unsigned char	d;

	str = NULL;
	d = va_arg(ap, unsigned int);
	if (!(str = ft_ultoa_base(d, 8)))
		return (NULL);
	return (str);
}

char	*ft_arg_oh(va_list ap)
{
	char			*str;
	unsigned short	d;

	str = NULL;
	d = va_arg(ap, unsigned int);
	if (!(str = ft_ultoa_base(d, 8)))
		return (NULL);
	return (str);
}

char	*ft_arg_oll(va_list ap)
{
	char *str;

	str = NULL;
	if (!(str = ft_ultoa_base(va_arg(ap, unsigned long long), 8)))
		return (NULL);
	return (str);
}

char	*ft_arg_ol(va_list ap)
{
	char *str;

	str = NULL;
	if (!(str = ft_ultoa_base(va_arg(ap, unsigned long), 8)))
		return (NULL);
	return (str);
}

char	*ft_arg_oj(va_list ap)
{
	char *str;

	str = NULL;
	if (!(str = ft_ultoa_base(va_arg(ap, uintmax_t), 8)))
		return (NULL);
	return (str);
}
