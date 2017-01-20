/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 08:10:45 by dle-blon          #+#    #+#             */
/*   Updated: 2015/12/14 15:45:59 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strwlen(wchar_t const *s)
{
	size_t		i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
		i++;
	return (i);
}

char		*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (!(str = ft_strnew(i)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

wchar_t		*ft_strwdup(const wchar_t *s)
{
	int			i;
	wint_t		*str;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (!(str = ft_strwnew(i)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_strsub(char const *s, unsigned int start, size_t size)
{
	char	*str;
	size_t	i;

	str = NULL;
	if (s)
	{
		str = ft_strnew(size);
		if (!str)
			return (NULL);
		i = 0;
		while (i < size && s[start])
		{
			str[i] = s[start];
			i++;
			start++;
		}
		str[i] = '\0';
	}
	return (str);
}
