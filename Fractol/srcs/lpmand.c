/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lpmand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 13:28:03 by dle-blon          #+#    #+#             */
/*   Updated: 2015/03/14 19:32:57 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_coor		ismandl(int x, int y, double zoom, t_fract var)
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
		z = (creal(z) * creal(z) - cimag(z) * cimag(z) + creal(c))
			+ (2 * cimag(z) * creal(z) + cimag(c)) * I;
		i++;
	}
	if (i == var.ite)
		pt.c = 0x00000;
	else
		pt.c = i * var.color;
	return (pt);
}

t_coor		*mandel(int xmax, int ymax, double z, t_fract var)
{
	int			x;
	int			y;
	int			i;
	t_coor		*mandl;

	x = 0;
	y = 0;
	i = 0;
	mandl = NULL;
	if (!(mandl = (t_coor *)malloc(sizeof(t_coor) * (xmax * ymax))))
		coderror('M');
	while (x < xmax)
	{
		while (y < ymax)
		{
			mandl[i] = ismandl(x, y++, z, var);
			mandl[i++].et = 'O';
		}
		x++;
		y = 0;
	}
	mandl[i - 1].et = 'F';
	return (mandl);
}
