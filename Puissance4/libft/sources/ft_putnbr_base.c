/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 22:26:12 by abary             #+#    #+#             */
/*   Updated: 2016/02/05 22:26:27 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbrn_base(int nbr, int base)
{
	if (nbr <= -base)
		ft_putnbrn_base(nbr / base, base);
	if (nbr % base > -10)
		ft_putchar('0' - nbr % base);
	else
		ft_putchar('A' - nbr % base - 10);
}

static void	ft_putnbrp_base(int nbr, int base)
{
	if (nbr >= base)
		ft_putnbrp_base(nbr / base, base);
	if (nbr % base < 10)
		ft_putchar('0' + nbr % base);
	else
		ft_putchar('A' + nbr % base - 10);
}

void		ft_putnbr_base(int nbr, int base)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbrn_base(nbr, base);
	}
	else
		ft_putnbrp_base(nbr, base);
}
