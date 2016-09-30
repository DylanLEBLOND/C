/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 19:48:07 by dle-blon          #+#    #+#             */
/*   Updated: 2014/11/12 18:51:50 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str1[i] && str2[j] && i < n && str1[i] == str2[j])
	{
		i++;
		j++;
	}
	if ((str1[i] == '\0' && str2[j] == '\0')
		|| i == n)
		return (0);
	else if (str1[i] == 0 && str2[j])
		return (-1);
	else if (str2[i] == 0 && str1[i])
		return (1);
	else if (str1[i] < str2[j])
		return (-1);
	else
		return (1);
}
