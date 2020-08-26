/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 20:44:32 by mnguyen           #+#    #+#             */
/*   Updated: 2016/02/11 20:54:05 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_tetriminos(t_tetri tetriminos, char **solution, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (!solution[x + tetriminos.y[i]] ||
			solution[x + tetriminos.y[i]][y + tetriminos.x[i]] != '.')
			return (0);
		i++;
	}
	return (1);
}

void	place_tetriminos(t_tetri tetriminos, char **solution, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		solution[x + tetriminos.y[i]][y + tetriminos.x[i]] = tetriminos.nb;
		i++;
	}
}

void	remove_tetriminos(t_tetri tetriminos, char **solution, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		solution[x + tetriminos.y[i]][y + tetriminos.x[i]] = '.';
		i++;
	}
}

void	solve(t_info data, char **solution, int x, int y)
{
	if (check_tetriminos(data.tetris[data.n], solution, x, y))
	{
		place_tetriminos(data.tetris[data.n], solution, x, y);
		data.n += 1;
		if (data.n == data.nb)
		{
			aff_solution(solution);
			solution[0][0] = '0';
			return ;
		}
		solve(data, solution, 0, 0);
		if (solution[0][0] == '0')
			return ;
		data.n -= 1;
		remove_tetriminos(data.tetris[data.n], solution, x, y);
	}
	if (solution[x][y + 1])
		y++;
	else
	{
		y = 0;
		x++;
	}
	if (solution[x])
		solve(data, solution, x, y);
}

void	algo(t_info data)
{
	int		size;
	char	**solution;

	init_letter(data);
	size = size_min(data.nb);
	while (1)
	{
		solution = tab_init(size);
		data.n = 0;
		solve(data, solution, 0, 0);
		if (solution[0][0] == '0')
		{
			free_solution(solution);
			return ;
		}
		free_solution(solution);
		size++;
	}
}
