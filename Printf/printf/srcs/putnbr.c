/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 19:07:30 by dle-blon          #+#    #+#             */
/*   Updated: 2016/01/14 20:55:32 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_space(t_add *flag, int a)
{
	if (flag->prflag > 0)
	{
		if (flag->pos == -1 || flag->plflag == 1)
			flag->min--;
		while (flag->min-- > 0)
			ft_putchar(' ', flag);
		if (flag->pos == -1)
			ft_putchar('-', flag);
		else if (flag->plflag == 1)
			ft_putchar('+', flag);
	}
	else if (flag->prflag == 0)
	{
		if (flag->pos == -1)
            ft_putchar('-', flag);
        else if (flag->plflag == 1)
            ft_putchar('+', flag);
        if (flag->pos == -1 || flag->plflag == 1)
            flag->min--;
		while (flag->min-- > 0)
            ft_putchar('0', flag);
	} 
	a == 1 ? ft_putchar('0', flag) : 1;
	a == 1 ? flag->min-- : 1;
}

void	ft_first(t_add *flag)
{
	if (flag->space && flag->pos != -1)
	{
		ft_putchar(' ', flag);
		flag->min--;
	}
}

void	ft_putnumber(t_add *flag, intmax_t n, uintmax_t m, unsigned int a)
{
	if (n > 0 && m == 0)
		m = n;
	else if (n < 0)
	{
		m = n * -1;
		flag->pos = -1;
	}
	flag->min -= ft_getsize(m, a);
	ft_first(flag);
	ft_space(flag, a);
	if (flag->prflag < 0 && flag->pos == -1)
	{
		ft_putchar('-', flag);
		flag->min--;
	}
	if (flag->prflag < 0 && flag->plflag == 1 && flag->pos != -1)
	{
		ft_putchar('+', flag);
		flag->min--;
	}
	ft_putnbr(m, flag);
}

void	ft_putnbr(uintmax_t n, t_add *flag)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10, flag);
		ft_putnbr(n % 10, flag);
	}
	else
		ft_putchar(n + '0', flag);
}
