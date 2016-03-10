/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:03:11 by abary             #+#    #+#             */
/*   Updated: 2016/01/31 18:56:15 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_utoap(unsigned int n, char *tmp, int i)
{
	++i;
	if (n >= 10)
		ft_utoap(n / 10, tmp, i);
	tmp[i] = '0' + n % 10;
	return (tmp);
}

char		*ft_utoa(int n)
{
	char *number;
	char tmp[11];

	ft_bzero(tmp, 11);
	number = NULL;
	number = ft_strdup(ft_strrev(ft_utoap(n, tmp, -1)));
	return (number);
}
