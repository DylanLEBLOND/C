/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnequ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 08:06:15 by dle-blon          #+#    #+#             */
/*   Updated: 2016/10/27 21:05:01 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(t_cpchar s1, t_cpchar s2, size_t n)
{
	if (s1 && s2)
	{
		if (!ft_strncmp((t_cpchar)s1, (t_cpchar)s2, n))
			return (1);
	}
	return (0);
}
