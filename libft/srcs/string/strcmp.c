/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 19:37:25 by dle-blon          #+#    #+#             */
/*   Updated: 2014/11/12 18:43:59 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(cpchar str1, cpchar str2)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (str1[i] && str2[j] && str1[i] == str2[j])
	{
		i++;
		j++;
	}
	if (str1[i] == 0 && str2[j] == 0)
		return (0);
	else if (str1[i] == 0 && str2[j])
		return (-1);
	else if (str2[j] == 0 && str1[i])
		return (1);
	else if (str1[i] < str2[j])
		return (-1);
	else
		return (1);
}
