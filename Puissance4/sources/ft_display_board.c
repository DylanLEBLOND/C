/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_board.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:58:56 by abary             #+#    #+#             */
/*   Updated: 2016/02/28 18:41:50 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "puissance4.h"

static void	ft_display_col(void)
{
	int i;

	i = 0;
	ft_putstr("     ");
	while (i < g_col)
	{
		if (i < 10)
		{
			ft_putchar(' ');
			ft_putnbr(i + 1);
			ft_putchar(' ');
		}
		else
		{
			ft_putnbr(i + 1);
			ft_putchar(' ');
		}
		++i;
	}
	ft_putchar('\n');
}

void		ft_display_board(char **board)
{
	int i;
	int j;

	i = 0;
	while (i < g_line)
	{
		j = 0;
		ft_putstr("     ");
		while (j < g_col)
		{
			ft_putchar('|');
			if (board[i][j] == 'X')
				ft_printf("%C ", 128308);
			else if (board[i][j] == 'O')
				ft_printf("%C ", 0x1F535);
			else
				ft_printf("%C ", 0x26AA);
			++j;
		}
		ft_putendl("|");
		++i;
	}
	ft_display_col();
}

void		ft_display_victory(char **board, int player, int winner)
{
	ft_display_board(board);
	if (winner != -1)
	{
		if (player)
		{
			ft_putendl("the computer won");
			ft_display_you_loose();
			ft_putchar('\n');
		}
		else
		{
			ft_putendl("the computer loose");
			ft_display_you_won();
			ft_putchar('\n');
		}
	}
	else
	{
		ft_display_null();
		ft_putchar('\n');
	}
}
