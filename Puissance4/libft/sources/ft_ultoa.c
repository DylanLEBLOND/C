/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 14:56:49 by abary             #+#    #+#             */
/*   Updated: 2016/01/31 18:52:36 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_lltoap(unsigned long long n, char *tmp, int i)
{
	++i;
	if (n >= 10)
		ft_lltoap(n / 10, tmp, i);
	tmp[i] = '0' + (n % 10);
	return (tmp);
}

char		*ft_ultoa(unsigned long long n)
{
	char *number;
	char tmp[21];

	ft_bzero(tmp, 21);
	number = NULL;
	ft_lltoap(n, tmp, -1);
	number = ft_strdup(ft_strrev(tmp));
	return (number);
}
