/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 20:06:16 by dle-blon          #+#    #+#             */
/*   Updated: 2015/11/01 20:24:27 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_lemperroad(t_param *set, int *nblem)
{
	int		i;
	int		lem;

	i = 0;
	lem = 0;
	while (nblem[i] != -1)
		lem += nblem[i++];
	while (lem < set->nblemin)
	{
		i = 0;
		while (nblem[i] != -1)
			nblem[i++] += 1;
		lem += i;
	}
}

int		*ft_initlem(t_param *set)
{
	int		i;
	int		len;
	int		*nblem;

	len = 0;
	while (set->best[len] != -1)
		len++;
	if (!(nblem = (int *)malloc(sizeof(int) * (len + 2))))
		ft_error('M');
	i = 0;
	while (i < len + 1)
		nblem[i++] = -1;
	i -= 2;
	if (set->nblemin > 0)
		nblem[i--] = 1;
	else
		nblem[i--] = 0;
	while (i >= 0)
	{
		nblem[i] = set->roads[set->best[i + 1]].len
			- set->roads[set->best[i]].len + nblem[i + 1];
		i--;
	}
	ft_lemperroad(set, nblem);
	return (nblem);
}

void	ft_mooveroad(t_road road, t_param *set, int nb, int dec)
{
	int		i;
	int		end;

	i = 1;
	end = 0;
	if (nb > road.len && !(nb % 2))
		end = nb - road.len - 1;
	else if (nb > road.len && nb % 2)
		end = nb - road.len - 2;
	while (nb >= set->nblemin)
	{
		i++;
		nb -= dec;
	}
	while (nb >= 0 && i < road.len)
	{
		ft_putstr("L");
		ft_putnbr(nb);
		ft_putstr("-");
		ft_putstr(set->tree[road.nodes[i]].name);
		ft_putstr(" ");
		i++;
		nb -= dec;
	}
}

void	ft_moove(t_param *set)
{
	int		i;
	int		j;
	int		end;
	int		dec;
	int		*nblem;

	i = 0;
	dec = 0;
	nblem = ft_initlem(set);
	while (nblem[i++] != -1)
		dec++;
	i = 0;
	end = nblem[0] + set->roads[set->best[0]].len;
	while (end)
	{
		j = 0;
		while (nblem[j] > 0)
			ft_mooveroad(set->roads[set->best[j++]], set, i++, dec);
		if (j < dec)
			dec--;
		ft_putstr("\n");
		end--;
	}
}
