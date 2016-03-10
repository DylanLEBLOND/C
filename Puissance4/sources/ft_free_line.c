/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 01:12:46 by abary             #+#    #+#             */
/*   Updated: 2016/02/28 23:40:49 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "puissance4.h"

int		ft_getval(int *tab)
{
	int	val;

	val = tab[VALMIN] > tab[VALMAX] ? tab[COLMIN] + 1 : tab[COLMAX] + 1;
	if (tab)
		free(tab);
	return (val);
}

void	ft_free_line(char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
}
