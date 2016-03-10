/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:09:39 by abary             #+#    #+#             */
/*   Updated: 2016/01/24 12:47:39 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*result;
	unsigned int	nb;
	char			*d;

	nb = ft_strlen(s1);
	if (!(result = (char *)ft_memalloc(sizeof(char) * nb + 1)))
		return (NULL);
	d = result;
	while (*s1)
		*result++ = *s1++;
	*result = '\0';
	return (result - (result - d));
}
