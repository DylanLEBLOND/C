/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 08:03:10 by dle-blon          #+#    #+#             */
/*   Updated: 2014/11/14 17:39:45 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(t_cpchar s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;

	new_str = NULL;
	if (s && f)
	{
		new_str = ft_strnew(ft_strlen(s));
		if (!new_str)
			return (NULL);
		i = 0;
		while (s && *(s + i) && f)
		{
			*(new_str + i) = f(i, *(s + i));
			i++;
		}
	}
	return (new_str);
}
