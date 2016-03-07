/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 16:28:02 by dle-blon          #+#    #+#             */
/*   Updated: 2016/03/07 20:37:33 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_mlx *point)
{
	if (point)
		;
	if (keycode == 65307)
		exit(0);
	return (0);
}

int		expose_hook(t_mlx *point)
{
	ft_fdf(*point);
	return (0);
}

int		redim(t_ix dim)
{
	int		x;
	int		vx;
	int		vy;

	vx = dim.xmax - dim.xmin;
	vy = dim.ymax - dim.ymin;
	if ((vx / WIDTH < 1) && (vy / HEIGHT < 1))
		return (1);
	if (vx / WIDTH >= vy / HEIGHT)
	{
		x = 10 * vx / (0.85 * WIDTH);
		return (x % 10 == 0 ? x / 10 : (x + 10) / 10);
	}
	else
	{
		x = 10 * vy / (0.75 * HEIGHT);
		return (x % 10 == 0 ? x / 10 : (x + 10) / 10);
	}
}

void	newcoor(t_coor **map, t_ix dim, int c)
{
	int		i;
	int		j;
	int		et;
	int		k;
	int		l;

	k = (WIDTH - dim.xmax / c + dim.xmin / c) / 2 - dim.xmin / c;
	l = (HEIGHT - dim.ymax / c + dim.ymin / c) / 2 - dim.ymin / c;
	i = 0;
	j = 0;
	et = 0;
	while (map[i])
	{
		while (et != 1)
		{
			map[i][j].x = (map[i][j].x) / c + k;
			map[i][j].y = (map[i][j].y) / c + l;
			if (map[i][j].etat == 'F')
				et = 1;
			j++;
		}
		i++;
		et = 0;
		j = 0;
	}
}
