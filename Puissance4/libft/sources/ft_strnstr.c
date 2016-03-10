/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:45:28 by abary             #+#    #+#             */
/*   Updated: 2015/12/01 14:15:35 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static	unsigned int	ft_search(const char *s1, const char *s2,
		size_t n, unsigned int nb)
{
	while (*s1 && *(s2 + nb) == *s1 && *(s2 + nb) && n > 0)
	{
		n--;
		s1++;
		nb++;
	}
	return (nb);
}

char					*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	nb;

	if (!*s2)
		return ((char *)(s1));
	while (*s1 && n > 0)
	{
		nb = 0;
		if (*s1 == *(s2 + nb))
		{
			nb = ft_search(s1, s2, n, nb);
			if (!*(s2 + nb))
				return ((char *)(s1));
		}
		n--;
		s1++;
	}
	return (NULL);
}
