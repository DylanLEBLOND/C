/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 08:08:44 by dle-blon          #+#    #+#             */
/*   Updated: 2015/12/10 20:18:34 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)s;
	while (i < n)
		str[i++] = c;
	return ((void *)str);
}

void		*ft_memalloc(size_t size)
{
	char	*ptr;

	ptr = (char*)malloc(sizeof(*ptr) * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, size);
	return ((void*)ptr);
}

char		*ft_strnew(size_t size)
{
	return ((char *)ft_memalloc(size + 1));
}

wchar_t		*ft_strwnew(size_t size)
{
	return ((wchar_t *)ft_memalloc(size + 1));
}
