/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 16:39:10 by dle-blon          #+#    #+#             */
/*   Updated: 2015/06/01 15:02:55 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	afftab(int **map)
{
	int		i;
	int		j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			ft_putnbr(map[i][j]);
			if (j < HEIGHT - 1)
				ft_putstr(" ");
			else
				ft_putstr("\n");
			j++;
		}
		i++;
	}
}

void	freetab(int **map)
{
	int		i;

	i = 0;
	while (i < WIDTH)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	if (map)
		free(map);
}
