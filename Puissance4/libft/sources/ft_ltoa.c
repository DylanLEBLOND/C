/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 14:56:33 by abary             #+#    #+#             */
/*   Updated: 2016/01/18 14:57:17 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_ltoan(long n, char *tmp, int i)
{
	++i;
	if (n <= -10)
		ft_ltoan(n / 10, tmp, i);
	tmp[i] = '0' - n % 10;
	return (tmp);
}

static char	*ft_ltoap(long n, char *tmp, int i)
{
	++i;
	if (n >= 10)
		ft_ltoap(n / 10, tmp, i);
	tmp[i] = '0' + n % 10;
	return (tmp);
}

char		*ft_ltoa(long long n)
{
	char *number;
	char tmp[20];

	ft_bzero(tmp, 20);
	number = NULL;
	if (n < 0)
		number = ft_strjoin("-", ft_strrev(ft_ltoan(n, tmp, -1)));
	else
		number = ft_strdup(ft_strrev(ft_ltoap(n, tmp, -1)));
	return (number);
}
