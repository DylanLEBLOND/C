/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 18:36:19 by dle-blon          #+#    #+#             */
/*   Updated: 2016/10/27 21:05:20 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, t_cpchar src, size_t num)
{
	size_t i;

	i = 0;
	while (src[i] && i < num)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < num)
		dest[i++] = '\0';
	return (dest);
}
