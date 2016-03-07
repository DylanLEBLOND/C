/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:52:18 by dle-blon          #+#    #+#             */
/*   Updated: 2016/03/07 20:37:09 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		mincolor(t_coor *tab, t_ix *dim)
{
	int		i;
	int		et;

	i = 0;
	et = 0;
	while (et != 1)
	{
		tab[i].z < dim->zmin ? dim->zmin = tab[i].z : i;
		tab[i].z > dim->zmax ? dim->zmax = tab[i].z : i;
		if (tab[i].etat == 'F')
			et = 1;
		i++;
	}
}

t_coor		**putcolor(t_coor **map, t_ix *dim)
{
	int		i;
	int		j;
	int		et;

	i = 0;
	j = 0;
	et = 0;
	while (map[i])
	{
		while (et != 1)
		{
			map[i][j].z < 0 ? map[i][j].c = colneg(map[i][j].z, dim->zmin) : j;
			map[i][j].z >= 0 ? map[i][j].c = colpos(map[i][j].z, dim->zmax) : j;
			if (map[i][j].etat == 'F')
				et = 1;
			j++;
		}
		i++;
		et = 0;
		j = 0;
	}
	return (map);
}

void		remp(char *str, int y, t_coor *tab, t_ix *dim)
{
	int		i;
	int		pos;

	i = 0;
	pos = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] && str[i] != ' ')
		{
			tab[pos].z = ft_atoi(str + i);
			tab[pos].x = (pos * AGR) * CST1 - CST2 * (y * AGR);
			tab[pos].y = (tab[pos].z * PROF) + (CST1 / 2) * (pos * AGR) \
				+ (CST2 / 2) * (y * AGR);
			tab[pos].etat = 'O';
			tab[pos].x > dim->xmax ? dim->xmax = tab[pos].x : pos;
			tab[pos].x < dim->xmin ? dim->xmin = tab[pos].x : pos;
			tab[pos].y > dim->ymax ? dim->ymax = tab[pos].y : pos;
			tab[pos].y < dim->ymin ? dim->ymin = tab[pos++].y : pos++;
		}
		while (str[i] && str[i] != ' ')
			i++;
	}
	tab[pos - 1].etat = 'F';
}

t_coor		*getnbr(char *str, int y, t_ix *dim)
{
	int		i;
	int		cpt;
	t_coor	*tab;

	if (!str)
		return (NULL);
	cpt = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		(str[i] && str[i] != ' ') ? cpt++ : cpt;
		while (str[i] && str[i] != ' ')
			i++;
	}
	if (!(tab = (t_coor *)malloc(sizeof(t_coor) * cpt)))
		coderror('M');
	remp(str, y, tab, dim);
	mincolor(tab, dim);
	return (tab);
}
