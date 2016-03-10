/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puissance4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 14:52:34 by abary             #+#    #+#             */
/*   Updated: 2016/02/28 19:56:38 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"
#include "libft.h"
#include <stdlib.h>

static void	ft_display_player(int player)
{
	ft_putstr("  ");
	if (player)
		ft_putendl("Player's turn");
	else
		ft_putendl("Computer's turn");
	ft_putchar('\n');
}

static void	ft_init_val(int winner, int *player, long *size)
{
	*size = g_line * g_col;
	*size = *size % 2 ? *size - 1 : *size;
	winner = 0;
	*player = ft_select_player();
}

int			ft_puissance4(char **puissance4)
{
	long	size;
	int		tab[3];
	int		i;
	int		input;

	ft_init_val(tab[0], &tab[1], &size);
	tab[PIECE] = 0;
	system("clear");
	while ((tab[WINNER] = ft_check_winner(puissance4, size, tab[PIECE])) == 0)
	{
		ft_display_player(tab[PLAYER]);
		ft_display_board(puissance4);
		input = tab[PLAYER] ? ft_recup_input(puissance4) :
			ft_ia(puissance4, tab[PIECE]);
		ft_pos_piece(puissance4, input - 1, tab[PIECE]);
		tab[PLAYER] = tab[PLAYER] ? 0 : 1;
		tab[PIECE] = tab[PIECE] ? 0 : 1;
		--size;
		if (tab[PLAYER] && (i = 200000000))
			while (i)
				--i;
		system("clear");
	}
	ft_display_victory(puissance4, tab[PLAYER], tab[WINNER]);
	return (tab[WINNER]);
}
