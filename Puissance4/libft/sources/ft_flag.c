/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 19:18:57 by abary             #+#    #+#             */
/*   Updated: 2016/02/04 15:14:59 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdlib.h>

char		*ft_flag_hash(char *format, int d, char *str)
{
	format = str;
	str = ft_strnew(ft_strlen(format) + d);
	if (ft_strlen(format) == 1 && *format == 48)
	{
		str = ft_strcat(str, format);
		return (str);
	}
	if (d == 2)
		str = ft_memcpy(str, "0", 1);
	else
		str = ft_memcpy(str, "0x", 2);
	str = ft_strcat(str, format);
	free(format);
	return (str);
}

char		*ft_flag_minus(char *format, int d, char *str)
{
	char	*nbr;
	int		i;

	i = 0;
	d = 0;
	format = NULL;
	nbr = ft_strnew(ft_strlen(str) + 1);
	while (*(str + d) == ' ')
		++d;
	--d;
	while (*(str + ++d))
		nbr[i++] = *(str + d);
	str = ft_memset(str, ' ', ft_strlen(str));
	str = ft_memcpy(str, nbr, i);
	free(nbr);
	return (str);
}

char		*ft_flag_space(char *format, int d, char *str)
{
	d = 0;
	format = str;
	if (*str == '-')
		return (str);
	if (*str == '0' || *str == ' ')
		*str = ' ';
	else if (*str != '+')
	{
		str = ft_strjoin(" ", str);
		free(format);
	}
	return (str);
}

char		*ft_flag_digit(char *format, int d, char *str)
{
	int		space;
	char	*mem;

	while (*(format - d) == '0' || *(format - d) == '+' || *(format - d) == '-'
			|| *(format - d) == '#')
		d--;
	space = 0;
	space = ft_atoi(format - d);
	space -= ft_strlen(str);
	if (space > 0)
	{
		mem = ft_strnew(space);
		mem = ft_memset(mem, ' ', space);
		format = ft_strjoin(mem, str);
		free(mem);
	}
	else
		format = ft_strdup(str);
	return (format);
}
