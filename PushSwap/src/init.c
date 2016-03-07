/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 18:23:44 by dle-blon          #+#    #+#             */
/*   Updated: 2015/04/03 18:23:48 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*pile_a(t_var var, char **av)
{
	int i;
	int *p_a;

	if (!(p_a = malloc(sizeof(int) * (var.size))))
		ft_error(3);
	i = 1;
	while (i <= var.size)
	{
		p_a[var.size - i] = ft_atoi(av[i + var.o]);
		ft_check(av[i + var.o]);
		i++;
	}
	return (p_a);
}

int		*tri_tab(int *pile_a, int ac, int *t)
{
	int swap;
	int *tri;
	int i;

	*t = 0;
	if (!(tri = ft_tabdup(pile_a, ac)))
		ft_error(3);
	while (!test(tri, ac + 1))
	{
		i = 0;
		while (i < ac - 1)
		{
			if (tri[i] < tri[i + 1])
			{
				swap = tri[i];
				tri[i] = tri[i + 1];
				tri[i + 1] = swap;
				*t += 1;
			}
			tri[i] == tri[i + 1] ? ft_error(2) : i;
			i++;
		}
		ac--;
	}
	return (tri);
}

int		test(int *tri, int ac)
{
	int i;

	i = 0;
	while (i < ac - 2)
	{
		if (tri[i] <= tri[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		*ft_tabdup(int *tab, int size)
{
	int *dup;
	int i;

	i = 0;
	dup = (int *)malloc(sizeof(int) * (size));
	if (dup)
	{
		while (i < size)
		{
			dup[i] = tab[i];
			i++;
		}
	}
	return (dup);
}
