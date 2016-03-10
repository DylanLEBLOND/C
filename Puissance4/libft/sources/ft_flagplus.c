/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagplus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 13:57:41 by abary             #+#    #+#             */
/*   Updated: 2016/02/04 17:53:21 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_flag_plus_norm(char *test, char *str, size_t len)
{
	test = ft_strnew(len + 1);
	*test = ' ';
	str = ft_strncat(test, str, len);
	return (str);
}

char		*ft_flag_plus(char *format, int d, char *str)
{
	char	*c;
	char	*test;
	size_t	len;

	format = 0;
	c = NULL;
	test = NULL;
	len = ft_strlen(str);
	if (*str == '-' && !(d = 0))
		return (str);
	if (*str != ' ')
	{
		if (*(str + --len) == ' ')
			str = ft_flag_plus_norm(test, str, len);
		else if ((c = str))
			str = ft_strjoin(" ", str);
	}
	test = str;
	while (*str == ' ')
		++str;
	*(str - 1) = '+';
	str = test;
	if (c)
		free(c);
	return (str);
}
