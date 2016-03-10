/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 20:58:11 by abary             #+#    #+#             */
/*   Updated: 2016/01/22 16:44:00 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_itoan(int n, char *tmp, int i)
{
	++i;
	if (n <= -10)
		ft_itoan(n / 10, tmp, i);
	tmp[i] = '0' - n % 10;
	return (tmp);
}

static char	*ft_itoap(int n, char *tmp, int i)
{
	++i;
	if (n >= 10)
		ft_itoap(n / 10, tmp, i);
	tmp[i] = '0' + n % 10;
	return (tmp);
}

char		*ft_itoa(int n)
{
	char *number;
	char tmp[11];

	ft_bzero(tmp, 11);
	number = NULL;
	if (n < 0)
		number = ft_strjoin("-", ft_strrev(ft_itoan(n, tmp, -1)));
	else
		number = ft_strdup(ft_strrev(ft_itoap(n, tmp, -1)));
	return (number);
}
