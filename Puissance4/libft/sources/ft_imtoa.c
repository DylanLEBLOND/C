/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 13:55:26 by abary             #+#    #+#             */
/*   Updated: 2016/02/02 13:55:29 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_imtoap(intmax_t n, char *tmp, int i)
{
	++i;
	if (n >= 10)
		ft_imtoap(n / 10, tmp, i);
	tmp[i] = '0' + n % 10;
	return (tmp);
}

char		*ft_imtoa(intmax_t n)
{
	char *number;
	char tmp[21];

	ft_bzero(tmp, 21);
	number = NULL;
	number = ft_strdup(ft_strrev(ft_imtoap(n, tmp, -1)));
	return (number);
}
