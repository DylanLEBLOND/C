/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 20:51:56 by mnguyen           #+#    #+#             */
/*   Updated: 2016/02/11 20:58:41 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		size_min(int nb)
{
	int i;

	i = 2;
	while (i * i < nb * 4)
		i++;
	return (i);
}

char	**tab_init(int size)
{
	char	**solution;
	int		i;
	int		j;

	i = 0;
	if (!(solution = (char **)malloc(sizeof(char *) * size + 1)))
		ft_error('M');
	while (i < size)
		if (!(solution[i++] = (char *)malloc(sizeof(char) * size + 1)))
			ft_error('M');
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			solution[i][j++] = '.';
		solution[i++][j] = 0;
	}
	solution[i] = 0;
	return (solution);
}

void	aff_solution(char **solution)
{
	int i;
	int j;

	i = 0;
	while (solution[i])
	{
		j = 0;
		while (solution[i][j])
			write(1, &solution[i][j++], 1);
		i++;
		write(1, "\n", 1);
	}
}

void	init_letter(t_info data)
{
	int i;

	i = 0;
	while (i < data.nb)
	{
		data.tetris[i].nb = 'A' + i;
		i++;
	}
}

void	free_solution(char **solution)
{
	int i;

	i = 0;
	while (solution[i])
		free(solution[i++]);
	free(solution[i]);
	free(solution);
}
