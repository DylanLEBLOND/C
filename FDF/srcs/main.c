/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 16:20:23 by dle-blon          #+#    #+#             */
/*   Updated: 2016/03/07 20:54:25 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	freeall(t_coor ***map)
{
	int		i;

	i = 0;
	while (*map[i])
	{
		free(*map[i]);
		*map[i] = NULL;
		++i;
	}
	free(*map);
	*map = NULL;
}

int		ft_maxln(t_coor *map)
{
	int		i;
	int		et;

	i = 0;
	et = 0;
	while (et == 0)
	{
		if (map[i].etat == 'F')
			et = 1;
		i++;
	}
	return (i);
}

void	ft_fdf(t_mlx point)
{
	int		i;
	int		j;
	int		et;
	int		max;

	i = 0;
	while (point.map[i])
	{
		j = 0;
		et = 0;
		if (point.map[i + 1])
			max = ft_maxln(point.map[i + 1]);
		while (et != 1)
		{
			if (point.map[i][j].etat == 'F')
				et = 1;
			else
				drt(point.mlx, point.new, point.map[i][j], point.map[i][j + 1]);
			if (point.map[i + 1] && j < max)
				drt(point.mlx, point.new, point.map[i][j], point.map[i + 1][j]);
			j++;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	t_mlx	point;

	if (ac == 2)
	{
		point.map = stockmap(av[1], &point.dim);
		newcoor(point.map, point.dim, redim(point.dim));
		if (!(point.mlx = mlx_init()))
			coderror('m');
		point.new = mlx_new_window(point.mlx, WIDTH, HEIGHT, "Test FDF");
		mlx_expose_hook(point.new, expose_hook, &point);
		mlx_hook(point.new, 2, 1L << 0, key_hook, &point);
		mlx_loop(point.mlx);
		freeall(&point.map);
	}
	else
	{
		ft_putstr("**** Nombre d'arguments incorrect (");
		ft_putnbr(ac - 1);
		ft_putendl(") Attendu = 1 ****");
	}
	return (0);
}
