/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 09:11:06 by abary             #+#    #+#             */
/*   Updated: 2016/01/10 14:55:11 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbrn(int nb)
{
	if (nb <= -10)
		ft_putnbrn(nb / 10);
	ft_putchar('0' - nb % 10);
}

static void	ft_putnbrp(int nb)
{
	if (nb >= 10)
		ft_putnbrp(nb / 10);
	ft_putchar('0' + nb % 10);
}

void		ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbrn(nb);
	}
	else
		ft_putnbrp(nb);
}
