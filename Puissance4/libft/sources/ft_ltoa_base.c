/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:54:35 by abary             #+#    #+#             */
/*   Updated: 2016/01/26 15:02:58 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_lbn(long long n, char *tmp, int i, int base)
{
	++i;
	if (n <= -base)
		ft_lbn(n / base, tmp, i, base);
	if (n % base < -9)
		tmp[i] = 'a' - n % base - 10;
	else
		tmp[i] = '0' - n % base;
	return (tmp);
}

static char	*ft_lbp(long long n, char *tmp, int i, int base)
{
	++i;
	if (n >= base)
		ft_lbp(n / base, tmp, i, base);
	if (n % base > 9)
		tmp[i] = 'a' + n % base - 10;
	else
		tmp[i] = '0' + n % base;
	return (tmp);
}

char		*ft_ltoa_base(long long n, int base)
{
	char *number;
	char tmp[66];

	ft_bzero(tmp, 66);
	if (n < 0)
		number = ft_strjoin("-", ft_strrev(ft_lbn(n, tmp, -1, base)));
	else
		number = ft_strdup(ft_strrev(ft_lbp(n, tmp, -1, base)));
	return (number);
}
