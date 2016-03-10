/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 13:06:13 by abary             #+#    #+#             */
/*   Updated: 2015/12/27 16:59:30 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	char *str;
	char *d;

	if (!(str = (char *)ft_memalloc(sizeof(char) * ++len)))
		return (NULL);
	d = str;
	while (*s1 && --len > 0)
		*str++ = *s1++;
	return (str - (str - d));
}
