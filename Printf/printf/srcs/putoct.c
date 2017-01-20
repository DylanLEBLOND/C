/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putoct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:21:22 by dle-blon          #+#    #+#             */
/*   Updated: 2016/02/01 19:08:41 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_base_2(unsigned long long x, int b_p, int size, t_add *flag)
{
	int i;
	int a;
	int ret;

	i = 0;
	a = 0;
	while (i < b_p)
	{
		x & 1 ? a += power(2, i) : i;
		x = x >> 1;
		i++;
	}
	if (x)
		ret = put_base_2(x, b_p, size - 1, flag);
	else
		size = space_zero(flag, size, 1, b_p);
	if (a < 10)
		ft_putchar(a + 48, flag);
	else if (flag->caps)
		ft_putchar(a + 55, flag);
	else
		ft_putchar(a + 87, flag);
	if (!x)
		return (size);
	return (ret);
}

void	put64(unsigned long long x, t_add *flag)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (i < 6)
	{
		if (x & 1)
			a += power(2, i);
		x = x >> 1;
		i++;
	}
	if (x)
		put64(x, flag);
	if (a < 26)
		ft_putchar(a + 65, flag);
	else if (a < 52)
		ft_putchar(a + 71, flag);
	else if (a < 62)
		ft_putchar(a - 4, flag);
	else if (a == 62)
		ft_putchar('+', flag);
	else
		ft_putchar('/', flag);
}

void	encode64(char *s, t_add *flag)
{
	int i;
	int j;
	int x;

	if (!s || !*s)
		return ;
	i = 0;
	while (s[i])
	{
		j = 3;
		x = 0;
		while (j > 0 && s[i])
		{
			x = x << 8 | s[i];
			j--;
			i++;
		}
		x = x << (2 * j);
		put64(x, flag);
	}
	while (j-- > 0)
		ft_putchar('=', flag);
}

void	call(t_add *flag, va_list *ap, char c, int pow)
{
	if (c == 'B')
		encode64(va_arg(*ap, char *), flag);
	else if(flag->modflag == 'H')
		space_zero(flag, put_base_2((unsigned char)va_arg(*ap, unsigned int),
									pow, flag->min - 1, flag), 0, 0);
	else if (flag->modflag == 'h')
		space_zero(flag, put_base_2((unsigned short)va_arg(*ap, unsigned int),
									pow, flag->min - 1, flag), 0, 0);
	else if (flag->modflag == 'l' || c == 'O')
		space_zero(flag, put_base_2(va_arg(*ap, unsigned long),
									pow, flag->min - 1, flag), 0, 0);
	else if (flag->modflag == 'L')
		space_zero(flag, put_base_2(va_arg(*ap, unsigned long long),
									pow, flag->min - 1, flag), 0, 0);
	else if (flag->modflag == 'j')
		space_zero(flag, put_base_2(va_arg(*ap, uintmax_t),
									pow, flag->min - 1, flag), 0, 0);
	else if (flag->modflag == 'z')
		space_zero(flag, put_base_2(va_arg(*ap, size_t),
									pow, flag->min - 1, flag), 0, 0);
	else if (pow)
		space_zero(flag, put_base_2(va_arg(*ap, unsigned int),
									pow, flag->min - 1, flag), 0, 0);
}

void	base_oh(t_add *flag, va_list *ap, char c)
{
	int pow;

	if (c == 'p')
	{
		putvoid(va_arg(*ap, void *), flag);
		return;
	}
	pow = 0;
	if (c == 'o' || c == 'O')
		pow = 3;
	else if (c == 'X' || c == 'x')
		pow = 4;
	else if (c == 'b')
		pow = 1;
	else if (c == 'Z')
		pow = 5;
	else if (c == 'q')
		pow = 2;
	if (c == 'X')
		flag->caps = 1;
	call(flag, ap, c, pow);
}
