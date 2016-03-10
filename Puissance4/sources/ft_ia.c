/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 21:40:48 by abary             #+#    #+#             */
/*   Updated: 2016/02/28 23:39:33 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"
#include "libft.h"

static int	ft_center(int nbr, int tabval, int col, int *scol)
{
	int demi;

	if (tabval < nbr)
	{
		*scol = col;
		return (nbr);
	}
	if (tabval == nbr)
	{
		demi = (g_col - 1) % 2 ? (g_col - 1) / 2 + 1 : (g_col - 1) / 2;
		if ((col <= demi && *scol <= demi && demi - *scol < demi - col)
			|| (col <= demi && *scol >= demi && *scol - demi < demi - col)
			|| (col >= demi && *scol <= demi && demi - *scol < col - demi)
			|| (col >= demi && *scol >= demi && *scol - demi < col - demi))
		{
			*scol = col;
			return (nbr);
		}
	}
	return (tabval);
}

void		ft_calcul_ai(char **p4, int piece, int *tab, int pro)
{
	int col;
	int scol;
	int nbr;
	int ligne;

	col = -1;
	if (pro > 0)
	{
		while (++col < g_col)
		{
			if (ft_check_column(p4, col))
			{
				ligne = ft_pos_piece(p4, col, piece);
				nbr = ft_check_max(p4, piece, col, ligne);
				tab[RETMAX] = ft_center(nbr, tab[RETMAX], col, &scol);
				if (piece)
					ft_calcul_player(p4, 0, tab, --pro);
				else
					ft_calcul_player(p4, 1, tab, --pro);
				ft_ret_piece(p4, col, piece);
			}
		}
	}
}

void		ft_calcul_player(char **p4, int piece, int *tab, int pro)
{
	int nbr;
	int ligne;
	int col;
	int scol;

	col = -1;
	if (pro > 0)
	{
		while (++col < g_col)
		{
			if (ft_check_column(p4, col))
			{
				ligne = ft_pos_piece(p4, col, piece);
				nbr = ft_check_max(p4, piece, col, ligne);
				tab[RETMIN] = ft_center(nbr, tab[RETMIN], col, &scol);
				if (piece)
					ft_calcul_ai(p4, 0, tab, --pro);
				else
					ft_calcul_ai(p4, 1, tab, --pro);
				ft_ret_piece(p4, col, piece);
			}
		}
	}
}

static int	*ft_init_tab(int *tab)
{
	if (!(tab = ft_memalloc(sizeof(int) * 6)))
		return (NULL);
	tab[VALMAX] = 0;
	tab[VALMIN] = 0;
	tab[COLMAX] = 0;
	tab[COLMIN] = 0;
	tab[RETMIN] = 0;
	tab[RETMAX] = 0;
	return (tab);
}

int			ft_ia(char **puissance4, int piece)
{
	int i;
	int *tab;
	int profondeur;

	tab = NULL;
	tab = ft_init_tab(tab);
	i = ft_win_loose(puissance4, piece);
	if (i > 0)
		return (i);
	profondeur = 7;
	i = -1;
	while (++i < g_col)
	{
		if (ft_check_column(puissance4, i))
		{
			ft_pos_piece(puissance4, i, piece);
			tab[RETMIN] = 0;
			tab[RETMAX] = 0;
			ft_calcul_player(puissance4, piece, tab, profondeur);
			ft_val_max_min(tab, i);
			ft_ret_piece(puissance4, i, piece);
		}
	}
	return (ft_getval(tab));
}
