/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   droite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 16:25:23 by dle-blon          #+#    #+#             */
/*   Updated: 2016/03/07 20:36:26 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		drtfctx(void *mlx, void *new, t_coor p1, t_coor p2)
{
	int		x;
	int		y;
	int		pix;
	int		col;

	x = p1.x;
	col = p1.c;
	while (x <= p2.x)
	{
		y = p2.y + ((p1.y - p2.y) * (x - p2.x)) / (p1.x - p2.x);
		pix = mlx_pixel_put(mlx, new, x, y, col);
		if (x >= p2.x / 2 && p1.c != p2.c)
			col = p2.c;
		x++;
	}
}

void		drtfcty(void *mlx, void *new, t_coor p1, t_coor p2)
{
	int		x;
	int		y;
	int		pix;
	int		col;

	y = p1.y;
	col = p1.c;
	while (y <= p2.y)
	{
		x = p2.x + ((p1.x - p2.x) * (y - p2.y)) / (p1.y - p2.y);
		pix = mlx_pixel_put(mlx, new, x, y, col);
		if (y >= p2.y / 2 && p1.c != p2.c)
			col = p2.c;
		y++;
	}
}

void		drt(void *mlx, void *new, t_coor p1, t_coor p2)
{
	int		x;
	int		y;

	if ((x = p2.x - p1.x) < 0)
		x *= -1;
	if ((y = p2.y - p1.y) < 0)
		y *= -1;
	if (x >= y)
	{
		if (p1.x < p2.x)
			drtfctx(mlx, new, p1, p2);
		else if (p1.x > p2.x)
			drtfctx(mlx, new, p2, p1);
	}
	else
	{
		if (p1.y <= p2.y)
			drtfcty(mlx, new, p1, p2);
		else
			drtfcty(mlx, new, p2, p1);
	}
}
