/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:36:52 by abary             #+#    #+#             */
/*   Updated: 2016/01/10 14:58:01 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putdouble(double nb)
{
	int nbr;

	nbr = nb;
	ft_putnbr(nbr);
	ft_putchar('.');
	nb = nb - nbr;
	nb = nb * 10000000;
	nbr = ft_abs(nb);
	if (nbr % 10 > 4)
		nbr += 10;
	nbr = nbr / 10;
	if (nbr != 0)
		ft_putnbr(nbr);
	else
		while (++nbr < 7)
			ft_putnbr(0);
}
