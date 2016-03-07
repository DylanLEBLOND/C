/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 17:08:42 by dle-blon          #+#    #+#             */
/*   Updated: 2015/11/01 20:22:24 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_affnode(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (!(ft_strcmp("##start", tab[i])))
			ft_putendl(tab[i]);
		else if (!(ft_strcmp("##end", tab[i])))
			ft_putendl(tab[i]);
		else if (ft_getspace(tab[i]) == 2)
			ft_putendl(tab[i]);
		else if (tab[i][0] == '#' && tab[i][1] != '#')
			ft_putendl(tab[i]);
		i++;
	}
}

void	ft_afflink(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		if ((ft_getdash(tab[i])) > -1)
			ft_putendl(tab[i]);
		i++;
	}
}

int		main(void)
{
	t_param		set;

	set.file = ft_organize();
	set.tree = ft_createnode(set.file, &set.node);
	ft_initnode(&set);
	ft_initlinks(&set);
	ft_getroad(&set);
	ft_putnbr(set.nblemin);
	ft_putstr("\n");
	ft_affnode(set.file);
	ft_afflink(set.file);
	ft_putstr("\n");
	set.best = ft_getbestway(&set);
	ft_moove(&set);
	return (0);
}
