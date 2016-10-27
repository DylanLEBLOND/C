/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 19:07:41 by dle-blon          #+#    #+#             */
/*   Updated: 2014/11/12 19:27:42 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(t_cpchar s, int c)
{
	int i;
	int t_cpt;

	i = 0;
	t_cpt = 0;
	while (s[i])
	{
		if (s[i] == c)
			t_cpt++;
		i++;
	}
	if (t_cpt == 0 && c == 0)
		return ((char *)(s + i));
	else if (t_cpt == 0)
		return (NULL);
	while (*s && t_cpt > 0)
	{
		if (*s == c)
			t_cpt--;
		s++;
	}
	return ((char *)(s - 1));
}
