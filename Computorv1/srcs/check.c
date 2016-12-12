/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 18:13:11 by dle-blon          #+#    #+#             */
/*   Updated: 2015/04/02 14:23:36 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int			justnb(char *str)
{
	int		i;
	int		eq;

	i = 0;
	eq = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]) && str[i] != 'X')
			return (0);
		if (str[i] == '=')
			eq = 1;
		i++;
	}
	if (i == 0 || !eq)
		return (0);
	return (1);
}

t_puis		*checktab(t_puis *tab, int *len)
{
	int			i;
	int			j;
	int			size;
	t_puis		*new;

	size = 0;
	i = -1;
	while (++i < *len)
		if (tab[i].nb != 0)
			size++;
	if (!(new = (t_puis *)malloc(sizeof(t_puis) * size)))
		exit(0);
	j = 0;
	i = -1;
	while (++i < *len)
		if (tab[i].nb != 0)
		{
			new[j].nb = tab[i].nb;
			new[j].degre = tab[i].degre;
			j++;
		}
	*len = j;
	free(tab);
	return (new);
}
