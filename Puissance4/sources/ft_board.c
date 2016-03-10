/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 22:15:17 by abary             #+#    #+#             */
/*   Updated: 2016/02/28 10:11:06 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "puissance4.h"
#include <stdlib.h>

char		**ft_create_board(char **p4)
{
	int i;
	int j;

	i = 0;
	while (i < g_line)
	{
		j = 0;
		while (j < g_col)
		{
			*(*(p4 + i) + j) = ' ';
			++j;
		}
		++i;
	}
	return (p4);
}

char		**ft_init_board(char **argv)
{
	char	**p4;
	int		i;

	i = 0;
	g_line = ft_atoi(*(argv + 1));
	g_col = ft_atoi(*(argv + 2));
	if (!(p4 = (char **)ft_memalloc(sizeof(char *) * (g_line + 1))))
		return (NULL);
	while (i < g_line)
	{
		if (!(*(p4 + i) = (char *)ft_memalloc(sizeof(char) * (g_col + 1))))
			return (NULL);
		++i;
	}
	*(p4 + i) = NULL;
	p4 = ft_create_board(p4);
	return (p4);
}

void		ft_ret_piece(char **p4, int col, int piece)
{
	int		i;
	char	p;

	i = 0;
	while (p4[i])
	{
		if (p4[i][col] != ' ')
		{
			p = piece ? 'O' : 'X';
			if (p4[i][col] == p)
				p4[i][col] = ' ';
			break ;
		}
		++i;
	}
}

int			ft_pos_piece(char **puissance4, int input, int piece)
{
	int		i;
	char	p;

	i = 0;
	while (*(puissance4 + i))
		++i;
	--i;
	while (i >= 0)
	{
		if (*(*(puissance4 + i) + input) == ' ')
		{
			p = piece ? 'O' : 'X';
			*(*(puissance4 + i) + input) = p;
			return (i);
		}
		--i;
	}
	return (i);
}

void		ft_destruct_board(char **board)
{
	int i;

	i = 0;
	while (i <= g_col)
	{
		free(board[i]);
		board[i] = NULL;
		++i;
	}
	free(board);
	board = NULL;
}
