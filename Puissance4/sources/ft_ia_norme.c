/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia_norme.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 11:11:06 by abary             #+#    #+#             */
/*   Updated: 2016/02/28 23:20:23 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "puissance4.h"

void		ft_destruct_tab(int *tab)
{
	if (tab)
		free(tab);
}

static void	ft_val_max(int *tab, int i)
{
	int col;
	int demi;

	if (tab[VALMAX] < tab[RETMAX])
	{
		tab[COLMAX] = i;
		tab[VALMAX] = tab[RETMAX];
	}
	if (tab[VALMAX] == tab[RETMAX])
	{
		col = tab[COLMAX];
		demi = (g_col - 1) % 2 ? (g_col - 1) / 2 + 1 : (g_col - 1) / 2;
		if ((col <= demi && i <= demi && demi - i < demi - col)
			|| (col <= demi && i >= demi && i - demi < demi - col)
			|| (col >= demi && i <= demi && demi - i < col - demi)
			|| (col >= demi && i >= demi && i - demi < col - demi))
		{
			tab[VALMAX] = tab[RETMAX];
			tab[COLMAX] = i;
		}
	}
}

static void	ft_val_min(int *tab, int i)
{
	int col;
	int demi;

	if (tab[VALMIN] < tab[RETMIN])
	{
		tab[COLMIN] = i;
		tab[VALMIN] = tab[RETMIN];
	}
	if (tab[VALMIN] == tab[RETMIN])
	{
		col = tab[COLMIN];
		demi = (g_col - 1) % 2 ? (g_col - 1) / 2 + 1 : (g_col - 1) / 2;
		if ((col <= demi && i <= demi && demi - i < demi - col)
			|| (col <= demi && i >= demi && i - demi < demi - col)
			|| (col >= demi && i <= demi && demi - i < col - demi)
			|| (col >= demi && i >= demi && i - demi < col - demi))
		{
			tab[VALMIN] = tab[RETMIN];
			tab[COLMIN] = i;
		}
	}
}

void		ft_val_max_min(int *tab, int i)
{
	ft_val_max(tab, i);
	ft_val_min(tab, i);
}
