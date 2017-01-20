/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:20:59 by dle-blon          #+#    #+#             */
/*   Updated: 2016/02/01 19:12:54 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		space_zero2(t_add *flag, int n, int before, int b_p)
{
	if ((before && flag->prflag != -1)
		|| (!before && flag->prflag == -1))
	{
		while (n-- > 0)
		{
			if (flag->prflag == 0)
				ft_putchar('0', flag);
			else
				ft_putchar(' ', flag);
		}
	}
	if (before && b_p == 3 && flag->hash && flag->prflag)
		ft_putchar('0', flag);
	else if (before && b_p == 4 && flag->hash && flag->prflag && !flag->caps)
		ft_putstr(flag, "0x");
	else if (before && b_p == 4 && flag->hash && flag->prflag)
		ft_putstr(flag, "0X");
	return (n);
}

int		space_zero(t_add *flag, int n, int before, int base_power)
{
	if (before && base_power == 3 && flag->hash)
	{
		n--;
		if (!flag->prflag)
			ft_putchar('0', flag);
	}
	else if (before && base_power == 4 && flag->hash)
	{
		n -= 2;
		if (!flag->prflag && !flag->caps)
			ft_putstr(flag, "0x");
		else if (!flag->prflag)
			ft_putstr(flag, "0X");
	}
	return (space_zero2(flag, n, before, base_power));
}

int		power(int x, int pow)
{
	int t;

	t = x;
	if (pow <= 0)
		return (1);
	while (pow-- > 1)
		x *= t;
	return (x);
}
