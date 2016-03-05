/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 17:01:29 by dle-blon          #+#    #+#             */
/*   Updated: 2015/06/06 17:30:19 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	view(t_ray *inf, int telep)
{
	if (telep == 1 || telep == 2)
	{
		inf->dirx = -1.0;
		inf->diry = 0.0;
		inf->plax = 0.00;
		inf->play = 0.66;
	}
	else
	{
		inf->dirx = 0.0;
		inf->diry = -1.0;
		inf->plax = -0.66;
		inf->play = 0.00;
	}
}

void	init(t_ray *inf, int telep)
{
	if (telep == 1)
	{
		inf->zone = 1;
		inf->posx = 50.00;
		inf->posy = 25.00;
	}
	else if (telep == 2)
	{
		inf->zone = 2;
		inf->posx = 33.00;
		inf->posy = 25.00;
	}
	else
	{
		inf->zone = 3;
		inf->posx = 16.00;
		inf->posy = 50.00;
	}
	view(inf, telep);
}

int		expose_hook(t_need *greed)
{
	if (greed->map[(int)greed->inf.posx][(int)greed->inf.posy] == 2)
		init(&greed->inf, 2);
	else if (greed->map[(int)greed->inf.posx][(int)greed->inf.posy] == 3)
		init(&greed->inf, 3);
	else if (greed->map[(int)greed->inf.posx][(int)greed->inf.posy] == 4)
		init(&greed->inf, 1);
	wolfhere(greed);
	modifmini(greed);
	mlx_put_image_to_window(greed->mlx, greed->win, greed->new, 0, 0);
	mlx_put_image_to_window(greed->mlx, greed->win, greed->new_mnp, 0, 0);
	return (0);
}

int		key_hook(int keycode, t_need *greed)
{
	ft_bzero(greed->img, greed->bt * 512 + 384 * greed->sz);
	if (keycode == ESCAPE)
		exit(0);
	else if (keycode == UP)
		moveup(greed->map, &greed->inf);
	else if (keycode == DOWN)
		movedown(greed->map, &greed->inf);
	else if (keycode == RIGHT)
		moveright(&greed->inf);
	else if (keycode == LEFT)
		moveleft(&greed->inf);
	else if (keycode == SPACE)
		init(&greed->inf, 1);
	if (keycode == UP || keycode == DOWN || keycode == LEFT
		|| keycode == RIGHT || keycode == SPACE)
		expose_hook(greed);
	return (0);
}

void	wolf(void)
{
	int		fd;
	t_need	greed;

	if (!(greed.mlx = mlx_init()))
		coderror('m');
	greed.win = mlx_new_window(greed.mlx, WMAP, HMAP, "Wolf3d");
	if (!(greed.new = mlx_new_image(greed.mlx, WMAP, HMAP)))
		coderror('m');
	greed.img = mlx_get_data_addr(greed.new, &greed.bt, &greed.sz, &greed.end);
	if (!(greed.img))
		coderror('m');
	fd = createfd();
	remp(fd, &greed);
	init(&greed.inf, 1);
	createminimap(&greed);
	mlx_expose_hook(greed.win, expose_hook, &greed);
	mlx_hook(greed.win, 2, 1L << 0, key_hook, &greed);
	mlx_loop(greed.mlx);
	freetab(greed.map);
}
