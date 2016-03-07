/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 13:28:20 by dle-blon          #+#    #+#             */
/*   Updated: 2016/03/07 21:36:42 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_mand(t_mlx *map)
{
	t_coor	*mdl;

	mdl = mandel(540, 600, map->z, map->var);
	putfrac(map, mdl);
	mlx_put_image_to_window(map->mlx, map->win, map->new, 0, 0);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_mlx *map)
{
	if (button == 1 || button == 4)
	{
		map->z += 100;
		map->s += 0.5;
		map->var.x1 = map->var.x1 + x / (map->s * map->z);
		map->var.y1 = map->var.y1 + y / (map->s * map->z);
	}
	if (button == 1 || button == 4)
		putimg(map);
	return (0);
}

int		key_mand(int keycode, t_mlx *map)
{
	map->z > 200 && keycode == LEFT ? map->var.x1 -= 0.01 : keycode;
	map->z > 200 && keycode == RIGHT ? map->var.x1 += 0.01 : keycode;
	map->z > 200 && keycode == UP ? map->var.y1 -= 0.015 : keycode;
	map->z > 200 && keycode == DOWN ? map->var.y1 += 0.015 : keycode;
	if (keycode == PLUS)
	{
		map->lp % 20 == 0 || map->lp < 10 ? map->var.ite += 10 : keycode;
		map->lp += 1;
	}
	if (keycode == MINUS && map->var.ite - 10 > 0)
	{
		map->lp % 20 == 0 || map->lp < 10 ? map->var.ite -= 10 : keycode;
		map->lp -= 1;
	}
	keycode == SPACE ? init_mand(map, 'N', 0) : keycode;
	if ((map->lp % 20 == 0 || map->lp < 10)
		&& (keycode == PLUS || keycode == MINUS || keycode == SPACE))
		putimg(map);
	if (map->z > 200 && (keycode == LEFT || keycode == RIGHT
					|| keycode == DOWN || keycode == UP))
		putimg(map);
	if (keycode == ESCAPE)
		exit(0);
	return (0);
}

void	init_mand(t_mlx *map, char n, int color)
{
	if (n == 'Y')
		if (!(map->name = ft_strdup("Mand")))
			coderror('M');
	map->var.x1 = -2.1;
	map->var.y1 = -1.5;
	map->var.ite = 50;
	if (color)
		map->var.color = color;
	map->z = 200;
	map->s = 2.0;
	map->rol = 0;
	map->lp = 0;
	map->c = 0;
}

void	mandelbrot(int c)
{
	t_mlx	map;

	if (!(map.mlx = mlx_init()))
		coderror('m');
	map.win = mlx_new_window(map.mlx, 540, 600, "Mandelbrot");
	if (!(map.new = mlx_new_image(map.mlx, 540, 600)))
		coderror('m');
	map.img = mlx_get_data_addr(map.new, &map.bit, &map.size, &map.end);
	if (!(map.img))
		coderror('m');
	init_mand(&map, 'Y', c);
	mlx_expose_hook(map.win, expose_mand, &map);
	mlx_hook(map.win, 2, 1L << 0, key_mand, &map);
	mlx_mouse_hook(map.win, mouse_hook, &map);
	mlx_loop(map.mlx);
}
