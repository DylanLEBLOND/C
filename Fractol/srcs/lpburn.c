/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lpburn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 15:52:00 by dle-blon          #+#    #+#             */
/*   Updated: 2015/03/14 19:30:01 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_coor		isburn(int x, int y, double zoom, t_fract var)
{
	int				i;
	t_coor			pt;
	ZBOUB			c;
	ZBOUB			z;

	z = 0;
	i = 0;
	pt.x = x;
	pt.y = y;
	c = (x / zoom + var.x1) + (y / zoom + var.y1) * I;
	while ((double)z < 2 && i < var.ite)
	{
		z = (fabs(creal(z)) + fabs(cimag(z)) * I)
			* (fabs(creal(z)) + fabs(cimag(z)) * I) + c;
		i++;
	}
	if (i == var.ite)
		pt.c = 0x00000;
	else
		pt.c = i * var.color;
	return (pt);
}

t_coor		*burning(int xmax, int ymax, double z, t_fract var)
{
	int			x;
	int			y;
	int			i;
	t_coor		*brn;

	x = 0;
	y = 0;
	i = 0;
	brn = NULL;
	if (!(brn = (t_coor *)malloc(sizeof(t_coor) * (xmax * ymax))))
		coderror('M');
	while (x < xmax)
	{
		while (y < ymax)
		{
			brn[i] = isburn(x, y++, z, var);
			brn[i++].et = 'O';
		}
		x++;
		y = 0;
	}
	brn[i - 1].et = 'F';
	return (brn);
}
