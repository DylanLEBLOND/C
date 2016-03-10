/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:43:43 by abary             #+#    #+#             */
/*   Updated: 2015/12/03 12:23:24 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printbit(unsigned char byte)
{
	unsigned char octet;

	octet = 128;
	while (octet)
	{
		if (octet & byte)
			ft_putchar('1');
		else
			ft_putchar('0');
		octet = octet >> 1;
	}
}
