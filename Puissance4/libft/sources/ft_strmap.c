/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:01:50 by abary             #+#    #+#             */
/*   Updated: 2015/12/02 16:32:45 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
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
			*(new + nb) = f(*s);
			s++;
			nb++;
		}
		*(new + nb) = '\0';
		return (new);
	}
	return (0);
}
