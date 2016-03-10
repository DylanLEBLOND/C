/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 14:46:10 by abary             #+#    #+#             */
/*   Updated: 2016/02/04 17:40:47 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

char	*ft_arg_z(va_list ap)
{
	char		*str;
	long int	d;

	str = NULL;
	d = va_arg(ap, long int);
	if (!(str = ft_ltoa(d)))
		return (NULL);
	return (str);
}

char	*ft_arg_d(va_list ap)
{
	char		*str;

	str = NULL;
	if (!(str = ft_itoa(va_arg(ap, int))))
		return (NULL);
	return (str);
}
