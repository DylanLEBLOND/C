/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:24:42 by abary             #+#    #+#             */
/*   Updated: 2015/12/01 14:15:50 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	occur;
	unsigned int	nb;

	nb = 0;
	occur = 0;
	while (*(s + nb))
	{
		if (*(s + nb) == c)
			occur++;
		nb++;
	}
	if (*(s + nb) == c)
		occur++;
	while (occur > 0)
	{
		if (*s == c)
			occur--;
		if (occur == 0)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
