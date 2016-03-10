/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 10:06:43 by abary             #+#    #+#             */
/*   Updated: 2016/02/28 23:20:39 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		ft_check_max(char **p4, int piece, int col, int ligne)
{
	int		poid;
	int		nopiece;
	char	p;

	poid = 0;
	p = piece ? 'O' : 'X';
	nopiece = piece ? 0 : 1;
	if (ft_check_winner(p4, 1, piece))
		poid = 10000;
	else if (ft_check_winner(p4, 1, nopiece))
		poid = -10000;
	else
	{
		poid += ft_check_line_vd(p4, ligne, col, p) * 10;
		poid += ft_check_col_vd(p4, ligne, col, p) * 10;
		poid += ft_check_diag_vd_gauche(p4, ligne, col) * 10;
		poid += ft_check_diag_vd_droite(p4, ligne, col) * 10;
	}
	return (poid);
}
