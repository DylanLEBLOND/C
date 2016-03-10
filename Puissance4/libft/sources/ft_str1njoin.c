/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str1njoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:43:19 by abary             #+#    #+#             */
/*   Updated: 2016/01/31 18:56:01 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str1njoin(const char *s1, const char *s2, int len)
{
	char *str;
	char *d;

	if (!(str = (char *)ft_memalloc(sizeof(char ) * ++len + ft_strlen(s2))))
		return (NULL);
	d = str;
	while (--len > 0)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (str - (str - d));
}
