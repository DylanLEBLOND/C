/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 16:26:11 by abary             #+#    #+#             */
/*   Updated: 2016/02/03 21:17:53 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_ibn(int n, char *tmp, int i, int base)
{
	++i;
	if (n <= -base)
		ft_ibn(n / base, tmp, i, base);
	if (n % base < -9)
		tmp[i] = 'a' - n % base - 10;
	else
		tmp[i] = '0' - n % base;
	return (tmp);
}

static char	*ft_ibp(int n, char *tmp, int i, int base)
{
	++i;
	if (n >= base)
		ft_ibp(n / base, tmp, i, base);
	if (n % base > 9)
		tmp[i] = 'a' + n % base - 10;
	else
		tmp[i] = '0' + n % base;
	return (tmp);
}

char		*ft_itoa_base(int n, int base)
{
	char *number;
	char tmp[32];

	ft_bzero(tmp, 32);
	if (n < 0)
		number = ft_strjoin("-", ft_strrev(ft_ibn(n, tmp, -1, base)));
	else
		number = ft_strdup(ft_strrev(ft_ibp(n, tmp, -1, base)));
	return (number);
}
