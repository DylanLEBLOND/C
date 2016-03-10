/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:11:00 by abary             #+#    #+#             */
/*   Updated: 2016/01/09 22:28:10 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	nb;

	nb = -1;
	while (++nb < n)
		*((unsigned char *)dst + nb) = *((unsigned char *)src + nb);
	return (dst);
}
