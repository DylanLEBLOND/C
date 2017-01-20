/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putvoid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 18:22:43 by dle-blon          #+#    #+#             */
/*   Updated: 2016/02/01 18:40:52 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putvoid2(unsigned long long x, t_add *flag)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (i < 4)
	{
		x & 1 ? a += power(2, i) : i;
		x = x >> 1;
		i++;
	}
	if (x)
		putvoid2(x, flag);
	if (a < 10)
		ft_putchar(a + 48, flag);
	else
		ft_putchar(a + 87, flag);
}

void	putvoid(void *s, t_add *flag)
{
    unsigned long long x;

	x = (unsigned long long)s;
	ft_putstr(flag, "0x");
    putvoid2(x, flag);
}
