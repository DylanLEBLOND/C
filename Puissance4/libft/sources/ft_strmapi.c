/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:10:02 by abary             #+#    #+#             */
/*   Updated: 2015/12/03 12:29:13 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	nb;

	if (!s)
		return (NULL);
	nb = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	if (f)
	{
		while (*s)
		{
			*(new + nb) = f(nb, *s);
			s++;
			nb++;
		}
		*(new + nb) = '\0';
		return (new);
	}
	return (NULL);
}
