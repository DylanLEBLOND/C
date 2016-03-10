/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:13:19 by abary             #+#    #+#             */
/*   Updated: 2015/12/01 14:14:59 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	unsigned int nb;

	nb = 0;
	while (*src && n > 0)
	{
		*(dst + nb) = *src;
		src++;
		n--;
		nb++;
	}
	if (n > 0)
	{
		while (n > 0)
		{
			*(dst + nb) = '\0';
			n--;
			nb++;
		}
	}
	return (dst);
}
