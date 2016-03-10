/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 16:16:49 by abary             #+#    #+#             */
/*   Updated: 2016/02/28 19:48:12 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void	ft_uncheck_column(int *tabline, int col)
{
	tabline[col]--;
}

int		ft_check_column(char **tab, int col)
{
	int i;

	i = 0;
	while (i < g_line)
	{
		if (tab[i][col] == ' ')
			return (1);
		++i;
	}
	return (0);
}
