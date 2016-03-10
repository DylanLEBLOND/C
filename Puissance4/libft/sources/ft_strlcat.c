/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:55:51 by abary             #+#    #+#             */
/*   Updated: 2015/11/30 15:05:57 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t nb;
	size_t i;
	size_t save;

	save = size;
	i = 0;
	nb = 0;
	while (*(dst + nb) && size > 0)
	{
		size--;
		nb++;
	}
	if (size == 0)
		return (ft_strlen(src) + nb);
	while (*(src + i) && (nb + i + 1) < save)
	{
		*(dst + nb + i) = *(src + i);
		i++;
	}
	if ((nb + i + 1) <= save)
		*(dst + nb + i) = '\0';
	return (nb + ft_strlen(src));
}
