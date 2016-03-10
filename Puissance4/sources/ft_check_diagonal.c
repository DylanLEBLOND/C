/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_diagonal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 18:39:36 by abary             #+#    #+#             */
/*   Updated: 2016/02/28 11:20:57 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		ft_check_diag_droite(char **tab, int i, int j)
{
	if (tab[i][j] == tab[i + 1][j + 1] && tab[i + 1][j + 1] == tab[i + 2][j + 2]
			&& tab[i + 2][j + 2] == tab[i + 3][j + 3])
		return (1);
	return (0);
}

int		ft_check_diag_gauche(char **tab, int i, int j)
{
	if (tab[i][j] == tab[i + 1][j - 1] && tab[i + 1][j - 1] == tab[i + 2][j - 2]
			&& tab[i + 2][j - 2] == tab[i + 3][j - 3])
		return (1);
	return (0);
}

int		ft_check_diag_vd_droite(char **tab, int i, int j)
{
	int		nbr;
	int		y;
	char	p;

	y = 1;
	nbr = 1;
	p = tab[i][j];
	while (i - y >= 0 && j + y < g_col && (tab[i - y][j + y] == p))
	{
		++nbr;
		++y;
	}
	y = 1;
	while (i + y < g_line && j - y >= 0 && (tab[i + y][j - y] == p))
	{
		++nbr;
		++y;
	}
	return (nbr);
}

int		ft_check_diag_vd_gauche(char **tab, int i, int j)
{
	int		nbr;
	int		y;
	char	p;

	y = 1;
	nbr = 1;
	p = tab[i][j];
	while (i - y >= 0 && j - y >= 0 && (tab[i - y][j - y] == p))
	{
		++nbr;
		++y;
	}
	y = 1;
	while (i + y < g_line && j + y < g_col && (tab[i + y][j + y] == p))
	{
		++nbr;
		++y;
	}
	return (nbr);
}
