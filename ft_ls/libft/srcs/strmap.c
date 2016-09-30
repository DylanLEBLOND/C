/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 07:59:14 by dle-blon          #+#    #+#             */
/*   Updated: 2014/11/14 17:39:33 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	int		i;

	new_str = NULL;
	if (s && f)
	{
		new_str = ft_strnew(ft_strlen(s));
		if (!new_str)
			return (NULL);
		i = 0;
		while (s && *(s + i) && f)
		{
			*(new_str + i) = f(*(s + i));
			i++;
		}
	}
	return (new_str);
}
