/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 18:34:52 by dle-blon          #+#    #+#             */
/*   Updated: 2014/11/16 00:09:01 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, cpchar src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t len;

	i = ft_strlen(dest);
	if (dstsize < i)
		len = dstsize + ft_strlen(src);
	else
		len = i + ft_strlen(src);
	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && i < dstsize - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (len);
}
