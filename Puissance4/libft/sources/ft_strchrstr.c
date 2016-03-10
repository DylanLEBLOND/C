/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 17:57:25 by abary             #+#    #+#             */
/*   Updated: 2016/02/04 17:35:52 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchrstr(const char *s1, const char *s2, int c)
{
	char			*tmp;
	char			*c2;

	while (*s1 && *s1 != c)
	{
		if (*s1 == *(s2) && (tmp = (char *)s1))
		{
			c2 = (char *)s2;
			while (*s1 && *s1 != c && *s2 == *s1 && *s2)
			{
				++s1;
				++s2;
			}
			if (!*(s2))
				return (tmp);
			s2 = c2;
			s1 = tmp;
		}
		++s1;
	}
	if (*s1 == *s2 && ft_strlen(s2) == 1)
		return ((char *)s1);
	return (NULL);
}
