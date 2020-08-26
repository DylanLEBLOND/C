/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 16:23:37 by dle-blon          #+#    #+#             */
/*   Updated: 2016/02/03 17:03:11 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	adjacblock(t_tetri block)
{
	int		i;
	int		px;
	int		adj;

	px = 0;
	adj = 0;
	while (px < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (i != px && block.x[px] == block.x[i]
				&& (block.y[px] == block.y[i] - 1
					|| block.y[px] == block.y[i] + 1))
				adj++;
			if (i != px && block.y[px] == block.y[i]
				&& (block.x[px] == block.x[i] - 1
					|| block.x[px] == block.x[i] + 1))
				adj++;
			i++;
		}
		px++;
	}
	if (!adj || adj / 2 < 3)
		ft_error('T');
}

void	normetetri(t_info *data, int pos)
{
	int		i;
	int		xmin;
	int		ymin;

	i = 0;
	xmin = INT_MAX;
	ymin = INT_MAX;
	while (i < 4)
	{
		if (xmin > data->tetris[pos].x[i])
			xmin = data->tetris[pos].x[i];
		if (ymin > data->tetris[pos].y[i])
			ymin = data->tetris[pos].y[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		data->tetris[pos].x[i] -= xmin;
		data->tetris[pos].y[i] -= ymin;
		i++;
	}
}

void	validtetri(t_info *data)
{
	int		i;

	i = 0;
	while (i < data->nb)
	{
		normetetri(data, i);
		adjacblock(data->tetris[i]);
		i++;
	}
}
