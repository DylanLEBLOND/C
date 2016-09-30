/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 08:38:13 by dle-blon          #+#    #+#             */
/*   Updated: 2014/11/12 08:39:48 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *ptr_1;
	const unsigned char *ptr_2;

	ptr_1 = (const unsigned char*)s1;
	ptr_2 = (const unsigned char*)s2;
	while (n)
	{
		if (*ptr_1 != *ptr_2)
			return ((int)(*ptr_1 - *ptr_2));
		n--;
		ptr_1++;
		ptr_2++;
	}
	return (0);
}
