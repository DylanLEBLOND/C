/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:36:27 by abary             #+#    #+#             */
/*   Updated: 2015/12/05 22:21:53 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	nb;

	nb = 0;
	if (src || dst)
	{
		while (nb != n)
		{
			((unsigned char *)dst)[nb] = ((unsigned char *)src)[nb];
			if ((unsigned char)c == ((unsigned char *)src)[nb])
			{
				return (&dst[nb + 1]);
			}
			nb++;
		}
	}
	return (NULL);
}
