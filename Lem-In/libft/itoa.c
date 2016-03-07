/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 18:27:20 by dle-blon          #+#    #+#             */
/*   Updated: 2014/11/14 19:49:47 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lennbr(int n)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char		*ft_intmin(void)
{
	char	*str;
	char	*nbr;
	int		i;

	str = NULL;
	if ((str = (char *)malloc(sizeof(char) * 12)))
	{
		nbr = "-2147483648";
		i = 0;
		while (i < 11)
		{
			str[i] = nbr[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;

	str = NULL;
	if (n == -2147483648)
		return (ft_intmin());
	len = ft_lennbr(n);
	if ((str = (char *)malloc(sizeof(char) * (len + 1))))
	{
		str[len--] = '\0';
		if (n < 0)
			str[0] = '-';
		if (n < 0)
			n *= -1;
		if (n == 0)
			str[len] = '0';
		while (n > 0)
		{
			str[len] = '0' + n % 10;
			len--;
			n /= 10;
		}
	}
	return (str);
}
