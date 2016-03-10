/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagprecision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 13:56:36 by abary             #+#    #+#             */
/*   Updated: 2016/02/04 17:54:52 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdlib.h>

static	char	*ft_flag_precision_while(long len, char *str)
{
	unsigned int min;

	if (*(str + len) == 32)
		*(str + len) = 48;
	if (*(str + len) == '-')
	{
		*(str + len) = 48;
		min = 0;
		while (*(str + min) == ' ')
			++min;
		if (min > 0)
			--min;
		*(str + min) = '-';
	}
	return (str);
}

static	char	*ft_flag_precision_norme(int d, char *str, char *format,
		int zero)
{
	long int	len;
	long		i;

	len = ft_strlen(str);
	i = ft_atoi(format - --d);
	if (i < 0)
	{
		if (len < ft_abs(i))
			str = ft_flag_digit(format, d, str);
		return (str = ft_flag_minus(format, d, str));
	}
	if (len < i)
	{
		str = ft_flag_digit(format, d, str);
		len = ft_strlen(str);
		if (ft_atoi(str) < 0)
			str = ft_strjoin(" ", str);
	}
	if (i == 0 && zero == 0)
		*(str + len - 1) = ' ';
	i = len - i;
	while (--len >= i)
		str = ft_flag_precision_while(len, str);
	return (str);
}

static char		*ft_flag_precision1(char *format, int d, char *str)
{
	int				zero;
	int				debut;

	zero = 1;
	if ((ft_strlen(str) == 1 && *str == 48) || ((ft_strlen(str) == 2
					&& *str == 48 && *(str + 1) == 'x')))
		zero = 0;
	str = ft_flag_digit(format, d, str);
	debut = d;
	while (*(format - d) != '.')
		--d;
	str = ft_flag_precision_norme(d, str, format, zero);
	if (ft_strlen(str) == 1 && *str == 32)
	{
		free(str);
		str = ft_strdup("\0");
	}
	if (*(format - debut) == '-')
		str = ft_flag_minus(format, d, str);
	return (str);
}

char			*ft_flag_precision(char *format, int d, char *str)
{
	char	*fr;

	fr = str;
	str = ft_flag_precision1(format, d, str);
	free(fr);
	return (str);
}
