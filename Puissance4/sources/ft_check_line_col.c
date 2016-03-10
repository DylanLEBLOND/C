/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line_col.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 21:27:57 by abary             #+#    #+#             */
/*   Updated: 2016/02/28 19:57:53 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		ft_check_line_vd(char **tab, int i, int j, char p)
{
	int nbr;
	int y;

	y = 1;
	nbr = 1;
	while (j - y >= 0 && tab[i][j - y] == p)
	{
		++nbr;
		++y;
	}
	y = 1;
	while (j + y < g_col && tab[i][j + y] == p)
	{
		++nbr;
		++y;
	}
	return (nbr);
}

int		ft_check_col_vd(char **tab, int i, int j, char p)
{
	int nbr;
	int y;

	y = 1;
	nbr = 1;
	while (i + y < g_line && tab[i + y][j] == p)
	{
		++nbr;
		++y;
	}
	return (nbr);
}
