/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_winner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 14:58:47 by abary             #+#    #+#             */
/*   Updated: 2016/02/28 17:56:54 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		ft_check_wline(char **puissance4, int player)
{
	int		i;
	int		j;
	int		piece;
	char	p;

	i = 0;
	p = player ? 'X' : 'O';
	while (i < g_line)
	{
		j = 0;
		piece = 0;
		while (j < g_col)
		{
			if (p == puissance4[i][j])
				++piece;
			else
				piece = 0;
			if (piece == 4)
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

int		ft_check_wcol(char **puissance4, int player)
{
	int		i;
	int		j;
	int		piece;
	char	p;

	i = 0;
	p = player ? 'X' : 'O';
	while (i < g_col)
	{
		j = 0;
		piece = 0;
		while (j < g_line)
		{
			if (p == puissance4[j][i])
				++piece;
			else
				piece = 0;
			if (piece == 4)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_check_wdiag(char **puissance4, int player)
{
	int		i;
	int		j;
	int		retour;
	char	p;

	i = -1;
	p = player ? 'X' : 'O';
	while (++i < g_line - 3)
	{
		j = -1;
		retour = 0;
		while (++j < g_col)
		{
			if (puissance4[i][j] == p)
			{
				if (j > 2)
					retour = ft_check_diag_gauche(puissance4, i, j);
				if (!retour && j < g_col - 3)
					retour = ft_check_diag_droite(puissance4, i, j);
				if (retour)
					return (retour);
			}
		}
	}
	return (0);
}

int		ft_check_winner(char **puissance4, int size, int player)
{
	if (!size)
		return (-1);
	return (ft_check_wline(puissance4, player) ||
			ft_check_wcol(puissance4, player) ||
			ft_check_wdiag(puissance4, player));
}
