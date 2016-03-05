/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:20:44 by dle-blon          #+#    #+#             */
/*   Updated: 2015/06/04 17:31:59 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	moveup(int **map, t_ray *inf)
{
	if (map[(int)(inf->posx + inf->dirx * 0.5)][(int)(inf->posy)] != 1)
		inf->posx += inf->dirx * 0.5;
	if (map[(int)(inf->posx)][(int)(inf->posy + inf->diry * 0.5)] != 1)
		inf->posy += inf->diry * 0.5;
}

void	movedown(int **map, t_ray *inf)
{
	if (map[(int)(inf->posx - inf->dirx * 0.5)][(int)(inf->posy)] != 1)
		inf->posx -= inf->dirx * 0.5;
	if (map[(int)(inf->posx)][(int)(inf->posy - inf->diry * 0.5)] != 1)
		inf->posy -= inf->diry * 0.5;
}

void	moveleft(t_ray *inf)
{
	double	oldirx;
	double	oldplax;

	oldirx = inf->dirx;
	oldplax = inf->plax;
	inf->dirx = inf->dirx * cos(-ROT) - inf->diry * sin(-ROT);
	inf->diry = oldirx * sin(-ROT) + inf->diry * cos(-ROT);
	inf->plax = inf->plax * cos(-ROT) - inf->play * sin(-ROT);
	inf->play = oldplax * sin(-ROT) + inf->play * cos(-ROT);
}

void	moveright(t_ray *inf)
{
	double	oldirx;
	double	oldplax;

	oldirx = inf->dirx;
	oldplax = inf->plax;
	inf->dirx = inf->dirx * cos(ROT) - inf->diry * sin(ROT);
	inf->diry = oldirx * sin(ROT) + inf->diry * cos(ROT);
	inf->plax = inf->plax * cos(ROT) - inf->play * sin(ROT);
	inf->play = oldplax * sin(ROT) + inf->play * cos(ROT);
}
