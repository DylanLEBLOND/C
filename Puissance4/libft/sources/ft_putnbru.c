/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 09:11:06 by abary             #+#    #+#             */
/*   Updated: 2016/01/31 19:03:19 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbrp(unsigned int nb)
{
	if (nb >= 10)
		ft_putnbrp(nb / 10);
	ft_putchar('0' + nb % 10);
}

void		ft_putnbru(unsigned int nb)
{
	ft_putnbrp(nb);
}
