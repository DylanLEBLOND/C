/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 13:19:03 by dle-blon          #+#    #+#             */
/*   Updated: 2015/03/16 13:45:28 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		fract(char *str, int c)
{
	if (!(ft_strcmp("Man", str)))
		mandelbrot(c);
	else if (!(ft_strcmp("Jul", str)))
		julia(c);
	else if (!(ft_strcmp("Bur", str)))
		burningship(c);
	else if (!(ft_strcmp("Dou", str)))
		douady(c);
	else
		return (1);
	return (0);
}

void	puterror(void)
{
	ft_putendl("******* Parametres Incorrects *******");
	ft_putendl("Fractales :\nMan = Mandelbrot\nJul = Julia");
	ft_putendl("Bur = Burning Ship\nDou = Lapin de Douady");
	ft_putendl("Color :");
	ft_putendl("1 | 2 | 3");
}

int		main(int ac, char **av)
{
	int		c;

	if (ac == 2 || ac == 3)
	{
		if (ac == 3)
			c = color(av[2]);
		ac == 2 ? c = color("0") : 0;
		if (fract(av[1], c))
			puterror();
	}
	else
		puterror();
	return (0);
}
