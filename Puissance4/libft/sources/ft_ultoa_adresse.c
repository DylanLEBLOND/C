/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_adresse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:15:48 by abary             #+#    #+#             */
/*   Updated: 2016/02/04 17:29:43 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_ulbp(unsigned long long n, char *tmp, int i, int base)
{
	++i;
	if (n >= (unsigned long)base)
		ft_ulbp(n / base, tmp, i, base);
	if (n % base > 9)
		tmp[i] = 'a' + n % base - 10;
	else
		tmp[i] = '0' + n % base;
	return (tmp);
}

char		*ft_ultoa_base(unsigned long long n, int base)
{
	char *number;
	char tmp[65];

	ft_bzero(tmp, 65);
	number = ft_strdup(ft_strrev(ft_ulbp(n, tmp, -1, base)));
	return (number);
}
