/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnequ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 08:06:15 by dle-blon          #+#    #+#             */
/*   Updated: 2014/11/12 08:06:58 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(cpchar s1, cpchar s2, size_t n)
{
	if (s1 && s2)
	{
		if (!ft_strncmp((cpchar )s1, (cpchar )s2, n))
			return (1);
	}
	return (0);
}
