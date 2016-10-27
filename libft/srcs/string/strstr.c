/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 19:17:01 by dle-blon          #+#    #+#             */
/*   Updated: 2015/01/07 21:10:51 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(t_cpchar str1, t_cpchar str2)
{
	int		i;
	int		j;
	int		save;

	i = 0;
	j = 0;
	save = 0;
	while (str1[i])
	{
		if (str1[i] == str2[j])
		{
			save = i;
			while (str1[i] == str2[j] && str1[i++] && str2[j])
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
