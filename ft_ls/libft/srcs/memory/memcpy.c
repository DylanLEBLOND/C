/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 22:27:23 by dle-blon          #+#    #+#             */
/*   Updated: 2016/10/27 21:03:07 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, t_cpvoid src, size_t n)
{
	char	*tmp_d;
	char	*tmp_s;

	if (!n || dest == src)
		return (dest);
	tmp_s = (char*)src;
	tmp_d = (char*)dest;
	while (n)
	{
		*tmp_d = *tmp_s;
		tmp_s++;
		tmp_d++;
		n--;
	}
	return (dest);
}
