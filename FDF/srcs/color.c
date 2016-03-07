/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 19:05:09 by dle-blon          #+#    #+#             */
/*   Updated: 2015/02/09 17:02:18 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		colneg(int z, int zmin)
{
	int		dec;

	dec = zmin / 3;
	if (z >= dec)
		return (0x0066FF);
	if (z < dec && z >= dec * 2)
		return (0x0000CC);
	return (0x000066);
}

int		colpos(int z, int zmax)
{
	int		dec;

	dec = zmax / 12;
	if (z <= dec)
		return (0x00CC33);
	if (z > dec && z <= dec * 2)
		return (0x009933);
	if (z > dec * 2 && z <= dec * 3)
		return (0x006633);
	if (z > dec * 3 && z <= dec * 6)
		return (0x996600);
	return (0xFFFFFF);
}
