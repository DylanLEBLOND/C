/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 08:12:23 by dle-blon          #+#    #+#             */
/*   Updated: 2014/11/12 08:15:08 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_blank(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	char	*new_str;
	size_t	i;
	size_t	len;

	if (s)
	{
		len = ft_strlen(s) - 1;
		i = 0;
		while (ft_is_blank(s[i]) && s[i])
			i++;
		if (!s[i])
			return (ft_strnew(1));
		while (len != i && ft_is_blank(s[len]))
			len--;
		if (!i && len == ft_strlen(s) - 1)
		{
			new_str = ft_strsub(s, 0, ft_strlen(s));
			return (new_str);
		}
		new_str = ft_strsub(s, i, len - i + 1);
		if (!new_str)
			return (NULL);
		return (new_str);
	}
	return (NULL);
}
