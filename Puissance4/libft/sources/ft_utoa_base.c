/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:12:29 by abary             #+#    #+#             */
/*   Updated: 2016/02/04 17:39:27 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_ubp(unsigned int n, char *tmp, int i, int base)
{
	++i;
	if (n >= (unsigned int)base)
		ft_ubp(n / base, tmp, i, base);
	if (n % base > 9)
		tmp[i] = 'a' + n % base - 10;
	else
		tmp[i] = '0' + n % base;
	return (tmp);
}

char		*ft_utoa_base(unsigned int n, int base)
{
	char *number;
	char tmp[65];

	ft_bzero(tmp, 65);
	number = ft_strdup(ft_strrev(ft_ubp(n, tmp, -1, base)));
	return (number);
}
