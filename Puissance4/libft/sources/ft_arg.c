/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <abary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 08:24:26 by abary             #+#    #+#             */
/*   Updated: 2016/01/29 14:53:01 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

char	*ft_arg_hh(va_list ap)
{
	char	*str;
	char	d;

	str = NULL;
	d = va_arg(ap, int);
	if (!(str = ft_itoa(d)))
		return (NULL);
	return (str);
}

char	*ft_arg_h(va_list ap)
{
	char	*str;
	short	d;

	str = NULL;
	d = va_arg(ap, int);
	if (!(str = ft_itoa(d)))
		return (NULL);
	return (str);
}

char	*ft_arg_ll(va_list ap)
{
	char		*str;
	long long	d;

	str = NULL;
	d = va_arg(ap, long long);
	if (!(str = ft_ltoa(d)))
		return (NULL);
	return (str);
}

char	*ft_arg_l(va_list ap)
{
	char	*str;
	long	d;

	str = NULL;
	d = va_arg(ap, long);
	if (!(str = ft_ltoa(d)))
		return (NULL);
	return (str);
}

char	*ft_arg_j(va_list ap)
{
	char		*str;
	intmax_t	d;

	str = NULL;
	d = va_arg(ap, intmax_t);
	if (!(str = ft_ltoa(d)))
		return (NULL);
	return (str);
}
