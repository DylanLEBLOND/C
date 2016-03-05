/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:39:50 by dle-blon          #+#    #+#             */
/*   Updated: 2015/06/04 17:43:27 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	initfirst(t_ray *inf, int x)
{
	inf->camx = 2 * x / (double)(WMAP) - 1;
	inf->raypx = inf->posx;
	inf->raypy = inf->posy;
	inf->raydx = inf->dirx + inf->plax * inf->camx;
	inf->raydy = inf->diry + inf->play * inf->camx;
	inf->mapx = (int)(inf->raypx);
	inf->mapy = (int)(inf->raypy);
	inf->dltdx = sqrt(1 + (inf->raydy * inf->raydy)
						/ (inf->raydx * inf->raydx));
	inf->dltdy = sqrt(1 + (inf->raydx * inf->raydx)
						/ (inf->raydy * inf->raydy));
	inf->hit = 0;
}

void	initsecond(t_ray *inf)
{
	if (inf->raydx < 0)
	{
		inf->stepx = -1;
		inf->sidedx = (inf->raypx - inf->mapx) * inf->dltdx;
	}
	else
	{
		inf->stepx = 1;
		inf->sidedx = (inf->mapx + 1.0 - inf->raypx) * inf->dltdx;
	}
	if (inf->raydy < 0)
	{
		inf->stepy = -1;
		inf->sidedy = (inf->raypy - inf->mapy) * inf->dltdy;
	}
	else
	{
		inf->stepy = 1;
		inf->sidedy = (inf->mapy + 1.0 - inf->raypy) * inf->dltdy;
	}
}

void	loopone(t_ray *inf, int **map)
{
	while (inf->hit == 0)
	{
		if (inf->sidedx < inf->sidedy)
		{
			inf->sidedx += inf->dltdx;
			inf->mapx += inf->stepx;
			inf->side = 0;
		}
		else
		{
			inf->sidedy += inf->dltdy;
			inf->mapy += inf->stepy;
			inf->side = 1;
		}
		if (map[inf->mapx][inf->mapy] > 0)
			inf->hit = 1;
	}
}

void	looptwo(t_ray *inf, t_need *greed, int x)
{
	if (inf->side == 0)
		inf->perpwd = fabs((inf->mapx - inf->raypx +
							(1 - inf->stepx) / 2) / inf->raydx);
	else
		inf->perpwd = fabs((inf->mapy - inf->raypy +
							(1 - inf->stepy) / 2) / inf->raydy);
	if (inf->perpwd == 0.0)
		inf->perpwd += 0.01;
	inf->lheight = abs((int)(HMAP / inf->perpwd));
	inf->drwstart = -inf->lheight / 2 + HMAP / 2;
	if (inf->drwstart < 0)
		inf->drwstart = 0;
	inf->save = inf->drwstart;
	while (inf->drwstart)
	{
		inf->color = 0x99FFFF;
		mlx_put_pixel_to_img(greed, x, inf->drwstart, inf->color);
		inf->drwstart--;
	}
}

void	loopthree(t_ray *inf, t_need *greed, int x)
{
	inf->drwstart = inf->save;
	inf->drwend = inf->lheight / 2 + HMAP / 2;
	if (inf->drwend >= HMAP)
		inf->drwend = HMAP - 1;
	inf->save = inf->drwend;
	while (inf->drwend < HMAP - 1)
	{
		inf->color = 0x663300;
		mlx_put_pixel_to_img(greed, x, inf->drwend, inf->color);
		inf->drwend++;
	}
	inf->drwend = inf->save;
}
