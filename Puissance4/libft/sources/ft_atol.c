/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:23:13 by abary             #+#    #+#             */
/*   Updated: 2016/02/24 20:38:10 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long		ft_atol(const char *str)
{
	long nb;
	long dizaine;
	long signe;

	nb = 0;
	dizaine = 10;
	signe = -1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			signe *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		nb *= dizaine;
		nb -= (*str - 48);
		str++;
	}
	return (nb * signe);
}
