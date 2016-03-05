/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raynext.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 20:36:36 by dle-blon          #+#    #+#             */
/*   Updated: 2015/06/04 19:33:59 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	mlx_put_pixel_to_img(t_need *greed, int x, int y, int color)
{
	ft_memcpy(&greed->img[(x * 4) + (y * greed->sz)], &color, (sizeof(size_t)));
}

void	mlx_put_pixel_to_mini(t_need *greed, int x, int y, int color)
{
	ft_memcpy(&greed->img_mnp[(x * 4) + (y * greed->sz_mini)],
				&color, (sizeof(size_t)));
}

void	trace(int x, t_ray *inf, t_need *greed)
{
	int y;

	y = inf->drwstart;
	while (y < inf->drwend)
	{
		mlx_put_pixel_to_img(greed, x, y, inf->color);
		y++;
	}
}

void	putcolor(int x, t_ray *inf, t_need *greed)
{
	int		n;

	n = greed->map[inf->mapx][inf->mapy];
	if (n == 2 || n == 3)
		inf->color = 0xFFFFFF;
	else if (n == 4)
		inf->color = 0x000000;
	else if (inf->side == 1 && inf->raydy > 0)
		inf->color = 0xFF0000;
	else if (inf->side == 1 && inf->raydy <= 0)
		inf->color = 0x3333FF;
	else if (inf->side == 0 && inf->raydx > 0)
		inf->color = 0x33CC00;
	else if (inf->side == 0 && inf->raydx <= 0)
		inf->color = 0xFF9900;
	trace(x, inf, greed);
}

void	wolfhere(t_need *greed)
{
	int		x;

	x = 0;
	while (x < WMAP)
	{
		initfirst(&greed->inf, x);
		initsecond(&greed->inf);
		loopone(&greed->inf, greed->map);
		looptwo(&greed->inf, greed, x);
		loopthree(&greed->inf, greed, x);
		putcolor(x, &greed->inf, greed);
		x++;
	}
}
