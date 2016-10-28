/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 16:27:00 by dle-blon          #+#    #+#             */
/*   Updated: 2016/10/27 21:02:50 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, t_cpvoid src, int c, size_t n)
{
	char	*tmp_d;
	char	*tmp_s;
	char	stop;

	stop = c;
	tmp_s = (char*)src;
	tmp_d = (char*)dest;
	while (n != 0 && *tmp_s != stop)
	{
		*tmp_d = *tmp_s;
		tmp_d++;
		tmp_s++;
		n--;
	}
	if (*tmp_s == stop)
	{
		*tmp_d = *tmp_s;
		return ((void*)++tmp_d);
	}
	return (NULL);
}
