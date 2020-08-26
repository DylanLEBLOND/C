/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 20:32:13 by dle-blon          #+#    #+#             */
/*   Updated: 2016/02/03 16:57:37 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_nbtetri(char **file)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (file[i] != NULL)
	{
		if (ft_strlen(file[i]) == 4)
			len++;
		i++;
	}
	if (len / 4 > 26)
		ft_error('T');
	return (len / 4);
}

void		getpos(t_info *data, int i, int j, int pos)
{
	int		nb;

	nb = data->tetris[pos].nb;
	data->tetris[pos].x[nb] = i;
	data->tetris[pos].y[nb] = j;
	data->tetris[pos].nb++;
}

void		ft_initdata(t_info *data, char **file, int *start, int pos)
{
	int		j;

	data->tetris[pos].nb = 0;
	if (!(data->tetris[pos].x = (int *)malloc(sizeof(int) * 4)))
		ft_error('M');
	if (!(data->tetris[pos].y = (int *)malloc(sizeof(int) * 4)))
		ft_error('M');
	while (file[*start] != NULL && ft_strlen(file[*start]) != 0)
	{
		j = 0;
		while (j < 4)
		{
			if (file[*start][j] == '#')
				getpos(data, j, *start, pos);
			if (data->tetris[pos].nb > 4)
				ft_error('T');
			j++;
		}
		*start += 1;
	}
	if (data->tetris[pos].nb != 4)
		ft_error('T');
}

void		ft_getdata(char **file, t_info *data)
{
	int		i;
	int		j;

	data->nb = ft_nbtetri(file);
	if (!(data->tetris = (t_tetri *)malloc(sizeof(t_tetri) * data->nb)))
		ft_error('M');
	i = 0;
	j = 0;
	while (file[i] != NULL)
	{
		ft_initdata(data, file, &i, j);
		if (file[i] != NULL)
			i++;
		j++;
	}
}
