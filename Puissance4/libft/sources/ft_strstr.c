/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:22:31 by abary             #+#    #+#             */
/*   Updated: 2016/01/15 09:47:53 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	nb;
	char			*tmp;

	if (!s2)
		return ((char *)(s1));
	while (*s1)
	{
		nb = 0;
		if (*s1 == *(s2 + nb))
		{
			tmp = (char *)s1;
			while (*s1 && *(s2 + nb) == *s1 && *(s2 + nb))
			{
				s1++;
				nb++;
			}
			if (!*(s2 + nb))
				return ((char *)(s1 - nb));
			s1 = tmp;
		}
		s1++;
	}
	return (NULL);
}
