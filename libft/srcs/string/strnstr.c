/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 19:26:15 by dle-blon          #+#    #+#             */
/*   Updated: 2015/01/07 21:34:38 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(cpchar str1, cpchar str2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	save;

	i = 0;
	j = 0;
	save = 0;
	while (str1[i] && i < n)
	{
		if (str1[i] == str2[j])
		{
			save = i;
			while (str1[i] == str2[j] && str1[i] && str2[j] && n > i++)
				j++;
		}
		if (str2[j] == '\0')
			return ((char *)(str1 + save));
		if (i > save && j)
			i = save;
		j = 0;
		i++;
	}
	return (NULL);
}
