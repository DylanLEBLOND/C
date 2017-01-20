/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 17:42:42 by dle-blon          #+#    #+#             */
/*   Updated: 2016/01/22 19:09:02 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	base_u(t_add *flags, va_list *ap, char c)
{
	if (flags->modflag == 'H')
		ft_putnumber(flags, 0, va_arg(*ap, unsigned int), 1);
	else if (flags->modflag == 'l' || c == 'U')
		ft_putnumber(flags, 0, va_arg(*ap, unsigned long), 0);
	else if (flags->modflag == 'L')
		ft_putnumber(flags, 0, va_arg(*ap, unsigned long long), 0);
	else if (flags->modflag == 'j')
		ft_putnumber(flags, 0, va_arg(*ap, uintmax_t), 0);
	else if (flags->modflag == 'z')
		ft_putnumber(flags, 0, va_arg(*ap, ssize_t), 0);
	else
		ft_putnumber(flags, 0, va_arg(*ap, unsigned int), 0);
	if (flags->prflag < 0 && flags->min > 0)
		while (flags->min-- > 0)
			ft_putchar(' ', flags);
}

void	base_int(t_add *flags, va_list *ap, char c)
{
	if (ft_strchr("idD", c))
	{
		if (flags->modflag == 'H')
			ft_putnumber(flags, va_arg(*ap, int), 0, 1);
		else if (flags->modflag == 'l' || c == 'D')
			ft_putnumber(flags, va_arg(*ap, long), 0, 0);
		else if (flags->modflag == 'L')
			ft_putnumber(flags, va_arg(*ap, long long), 0, 0);
		else if (flags->modflag == 'j')
			ft_putnumber(flags, va_arg(*ap, intmax_t), 0, 0);
		else if (flags->modflag == 'z')
			ft_putnumber(flags, va_arg(*ap, size_t), 0, 0);
		else
			ft_putnumber(flags, va_arg(*ap, int), 0, 0);
		if (flags->prflag < 0 && flags->modflag == 'H')
			flags->min--;
		if (flags->prflag < 0 && flags->min > 0)
			while (flags->min-- > 0)
				ft_putchar(' ', flags);
	}
	else
		base_u(flags, ap, c);
}
/*
void	base_dec(t_add *flags, va_list *ap, char c)
{
	if (flags->min == flags->min)
		if (ft_strchr("fF", c))
			ft_putfloat(va_arg(*ap, double), 6);
}*/

void	base_char(t_add *flags, va_list *ap, char c)
{
	if (flags->modflag == 'l' || c == 'S')
	{
		if (ft_strchr("cC", c))
			ft_putwchar(va_arg(*ap, wint_t), flags);
		else
			ft_putwstr(flags, va_arg(*ap, wint_t *));
	}
	else
	{
		if (ft_strchr("cC", c))
			ft_putchar(va_arg(*ap, signed int), flags);
		else
			ft_putstr(flags, va_arg(*ap, char *));
	}
}
