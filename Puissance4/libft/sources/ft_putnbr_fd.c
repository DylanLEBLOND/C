/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 09:46:18 by abary             #+#    #+#             */
/*   Updated: 2015/12/29 17:33:28 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbrn(int nb, int fd)
{
	if (nb <= -10)
		ft_putnbrn(nb / 10, fd);
	ft_putchar_fd('0' - nb % 10, fd);
}

static void	ft_putnbrp(int nb, int fd)
{
	if (nb >= 10)
		ft_putnbrp(nb / 10, fd);
	ft_putchar_fd('0' + nb % 10, fd);
}

void		ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbrn(nb, fd);
	}
	else
		ft_putnbrp(nb, fd);
}
