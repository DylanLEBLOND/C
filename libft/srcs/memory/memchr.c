/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 08:36:07 by dle-blon          #+#    #+#             */
/*   Updated: 2014/11/12 08:37:36 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(cpvoid s, int c, size_t n)
{
	unsigned char		car;
	const unsigned char	*ptr;

	car = (unsigned char)c;
	ptr = (const unsigned char*)s;
	while (n)
	{
		if (*ptr == car)
			return ((void*)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
