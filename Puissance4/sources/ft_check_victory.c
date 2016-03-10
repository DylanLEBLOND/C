/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_victory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 10:26:05 by abary             #+#    #+#             */
/*   Updated: 2016/02/28 17:36:29 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static int	ft_check_victory(char **p4, int piece)
{
	char	p;
	int		nbr;
	int		g;
	int		ligne;

	g = 0;
	p = piece ? 'O' : 'X';
	nbr = 0;
	while (g < g_col && nbr <= 3)
	{
		if (ft_check_column(p4, g))
		{
			ligne = ft_pos_piece(p4, g, piece);
			nbr = ft_check_line_vd(p4, ligne, g, p);
			if (nbr <= 3)
				nbr = ft_check_col_vd(p4, ligne, g, p);
			if (nbr <= 3)
				nbr = ft_check_diag_vd_gauche(p4, ligne, g);
			if (nbr <= 3)
				nbr = ft_check_diag_vd_droite(p4, ligne, g);
			ft_ret_piece(p4, g, piece);
		}
		++g;
	}
	return (nbr < 4 ? 0 : g);
}

int			ft_win_loose(char **puissance4, int piece)
{
	int i;

	i = ft_check_victory(puissance4, piece);
	if (i > 0)
		return (i);
	if (piece)
		i = ft_check_victory(puissance4, 0);
	else
		i = ft_check_victory(puissance4, 1);
	return (i);
}
