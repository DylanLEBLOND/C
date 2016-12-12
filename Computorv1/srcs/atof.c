/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 16:42:43 by dle-blon          #+#    #+#             */
/*   Updated: 2015/03/30 18:53:08 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	ft_initint(int *tab, int size)
{
	while (size >= 0)
		tab[size--] = -1;
}

int		ft_member(int *tab, int nb, int size)
{
	while (size >= 0)
	{
		if (tab[size] == nb)
			return (0);
		size--;
	}
	return (1);
}

int		ft_error(char *str)
{
	int		i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if ((i == 0 && str[i] == ' ') || (i == 1 && str[0] == '-' && str[i] == ' '))
		return (1);
	if ((str[0] != '-' && i - 1 > 10) || (str[0] == '-' && i - 2 > 10))
		return (1);
	if (str[0] != '-' && i - 1 == 10
		&& ft_strcmp(ft_strsub(str, 0, i), "2147483647") > 0)
		return (1);
	if (str[0] == '-' && i - 2 == 10
		&& ft_strcmp(ft_strsub(str, 0, i), "-2147483648") > 0)
		return (1);
	return (0);
}

int		ft_reatoi(const char *str, int *exp, int *s)
{
	int		i;
	int		nb;

	if (strcmp(str, "-2147483648") == 0)
		return (-2147483648);
	i = 0;
	*s = 1;
	nb = 0;
	while (str[i] && (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
				|| str[i] == ' ' || str[i] == '\f'
				|| str[i] == '\r' || str[i] == '\0' || str[i] == '\011'
				|| str[i] == '\012' || str[i] == '\013' || str[i] == '\014'
				|| str[i] == '\015'))
		i++;
	if (str[i] == '-')
		*s = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	*exp = i;
	return (nb);
}

float	ft_atof(char *str)
{
	int		i;
	int		s;
	int		exp;
	float	nb;

	s = 1;
	i = 0;
	exp = 10;
	nb = ft_reatoi(str, &i, &s);
	if (str[i] != '.')
		return (s * nb);
	i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb + ((float)(str[i] - '0') / exp);
		i++;
		exp = exp * 10;
	}
	return (s * nb);
}
