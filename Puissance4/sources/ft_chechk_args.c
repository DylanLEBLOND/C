/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chechk_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:46:03 by abary             #+#    #+#             */
/*   Updated: 2016/02/28 20:07:06 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_value(char *str)
{
	int i;

	i = 0;
	if (*(str + i) == '+' || *(str + i) == '-')
		++i;
	while (*(str + i))
	{
		if (!ft_isdigit(*(str + i)))
			return (0);
		++i;
	}
	return (1);
}

int	ft_check_args(char **args)
{
	int		i;
	long	nbr;

	i = 1;
	while (i < 3)
	{
		if (!(ft_check_value(*(args + i))))
			return (-1);
		nbr = ft_atol(*(args + i));
		if (nbr > 100 || nbr < -2147483648)
			return (-2);
		if (nbr < 0)
			return (-3);
		if (i == 1 && nbr < 6)
			return (-4);
		if (i == 2 && nbr < 7)
			return (-5);
		++i;
	}
	return (1);
}
