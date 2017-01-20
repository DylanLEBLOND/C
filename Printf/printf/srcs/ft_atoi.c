/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:48:23 by dle-blon          #+#    #+#             */
/*   Updated: 2016/01/14 19:38:12 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

unsigned int	ft_getsize(uintmax_t nb, unsigned int a)
{
	unsigned int	n;

	n = 0;
	while (nb > 0)
	{
		nb /= 10;
		n++;
	}
	return (n + a);
}

int				ft_atoi(const char *str)
{
	int i;
	int sign;
	int nb;

	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			|| (str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + str[i++] - 48;
	return (nb * sign);
}
