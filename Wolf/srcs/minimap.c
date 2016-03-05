/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 18:20:43 by dle-blon          #+#    #+#             */
/*   Updated: 2015/06/06 17:31:02 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	put_minimap(t_need *greed, int z)
{
	int		x;
	int		y;

	x = 0;
	while (x < WMINI)
	{
		y = 0;
		while (y < HMINI)
		{
			if (x / 4 == (int)greed->inf.posy
				&& y / 9 + z == (int)greed->inf.posx)
				mlx_put_pixel_to_mini(greed, x, y, 0x003300FF);
			else if (greed->map[y / 9 + z][x / 4] == 1)
				mlx_put_pixel_to_mini(greed, x, y, 0x00000000);
			else if (greed->map[y / 9 + z][x / 4] == 2
					|| greed->map[y / 9 + z][x / 4] == 3)
				mlx_put_pixel_to_mini(greed, x, y, 0x0000FF00);
			else if (greed->map[y / 9 + z][x / 4] == 4)
				mlx_put_pixel_to_mini(greed, x, y, 0x00FF0000);
			else
				mlx_put_pixel_to_mini(greed, x, y, 0x77FFFFFF);
			y++;
		}
		x++;
	}
}

void	modifmini(t_need *greed)
{
	if (greed->inf.zone == 1)
		put_minimap(greed, 34);
	else if (greed->inf.zone == 2)
		put_minimap(greed, 17);
	else
		put_minimap(greed, 0);
}

void	createminimap(t_need *greed)
{
	if (!(greed->new_mnp = mlx_new_image(greed->mlx, WMINI, HMINI)))
		coderror('m');
	greed->img_mnp = mlx_get_data_addr(greed->new_mnp, &greed->bt_mini,
										&greed->sz_mini, &greed->end_mini);
	if (!(greed->img))
		coderror('m');
	modifmini(greed);
}
