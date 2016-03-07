/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getbest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 20:20:56 by dle-blon          #+#    #+#             */
/*   Updated: 2015/11/01 20:23:10 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_getfastest(t_road *roads, int nbroad)
{
	int		i;
	int		nb;
	int		len;

	i = 0;
	nb = 0;
	len = roads[0].len;
	while (i < nbroad)
	{
		if (roads[i].len < len)
		{
			nb = i;
			len = roads[i].len;
		}
		i++;
	}
	return (nb);
}

int		ft_noseq(t_road r1, t_road r2)
{
	int		i;

	i = 1;
	while (i < r1.len && i < r2.len)
	{
		if (r1.nodes[i] == r2.nodes[i])
			return (-1);
		i++;
	}
	return (0);
}

int		ft_combi(t_road *roads, int fast, int nbroad)
{
	int		i;
	int		nb;
	int		len;

	i = 0;
	nb = -1;
	len = roads[0].len;
	while (i < nbroad)
	{
		if (roads[i].len >= roads[fast].len && roads[i].len < len)
		{
			if (!ft_noseq(roads[fast], roads[i]))
			{
				nb = i;
				len = roads[i].len;
			}
		}
		i++;
	}
	return (nb);
}

int		*ft_getbestway(t_param *set)
{
	int		i;
	int		nblem;
	int		*fast;

	if (!(fast = (int *)malloc(sizeof(int) * (set->nbroad + 1))))
		ft_error('M');
	fast[0] = ft_getfastest(set->roads, set->nbroad);
	i = 1;
	while (i < set->nbroad + 1)
		fast[i++] = -1;
	i = 1;
	nblem = set->nblemin - set->roads[fast[0]].len;
	while (nblem > 0 && i < set->nbroad)
	{
		if ((fast[i] = ft_combi(set->roads, fast[i - 1], set->nbroad)) != -1)
		{
			if (set->roads[fast[i]].len - set->roads[fast[i - 1]].len > nblem)
				nblem = 0;
			nblem -= (set->roads[fast[i]].len - set->roads[fast[i - 1]].len);
			i++;
		}
		else
			nblem = 0;
	}
	return (fast);
}
