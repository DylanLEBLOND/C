/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 18:29:45 by dle-blon          #+#    #+#             */
/*   Updated: 2016/01/22 20:44:27 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwchar(wchar_t c, t_add *flags)
{
	flags->cpt++;
	write(1, &c, 4);
}

void	ft_putchar(char c, t_add *flags)
{
	flags->cpt++;
	write(1, &c, 1);
}
