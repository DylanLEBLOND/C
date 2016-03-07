/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lpjulia.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 14:26:32 by dle-blon          #+#    #+#             */
/*   Updated: 2015/03/14 20:47:17 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_coor		isjul(int x, int y, double zoom, t_fract var)
{
	int				i;
	t_coor			pt;
	ZBOUB			c;
	ZBOUB			z;

	z = 0;
	i = 0;
	pt.x = x;
	pt.y = y;
	c = var.c_r + var.c_i * I;
	z = (x / zoom + var.x1) + (y / zoom + var.y1) * I;
	while ((double)z < 2 && i < var.ite)
	{
		z = z * z + c;
		i++;
	}
	if (i == var.ite)
		pt.c = 0x00000;
	else
		pt.c = i * var.color;
	return (pt);
}

t_coor		*julie(int xmax, int ymax, double z, t_fract var)
{
	int			x;
	int			y;
	int			i;
	t_coor		*tabj;

	x = 0;
	y = 0;
	i = 0;
	tabj = NULL;
	if (!(tabj = (t_coor *)malloc(sizeof(t_coor) * (xmax * ymax))))
		coderror('M');
	while (x < xmax)
	{
		while (y < ymax)
		{
			tabj[i] = isjul(x, y++, z, var);
			tabj[i++].et = 'O';
		}
		x++;
		y = 0;
	}
	tabj[i - 1].et = 'F';
	return (tabj);
}
