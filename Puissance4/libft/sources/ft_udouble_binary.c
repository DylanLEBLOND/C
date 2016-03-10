/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_udouble_binary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 19:03:44 by abary             #+#    #+#             */
/*   Updated: 2016/02/04 17:59:15 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_recover_binary(double db)
{
	char		*str;
	char		*mndb;
	char		*t;
	size_t		len;
	union u_db	u_mont;

	u_mont.udb = db;
	str = ft_ultoa_base(u_mont.uint, 2);
	len = ft_strlen(str);
	mndb = (char *)ft_memalloc(sizeof(char) * 64 + 1);
	mndb = ft_memset(mndb, '0', 64);
	t = mndb;
	mndb = ft_memcpy(mndb + (64 - len), str, len);
	mndb = t;
	free(str);
	return (mndb);
}

static char	*ft_signe(char *mndb)
{
	char	*str;
	char	*zero;

	zero = mndb;
	while (*zero)
	{
		if (*zero != '0')
			break ;
		++zero;
	}
	if (*zero == '\0')
		return (ft_strdup("0x0p+0"));
	if (*mndb == '1')
		str = ft_strdup("-0x1.");
	else
		str = ft_strdup("0x1.");
	return (str);
}

static char	*ft_mantisse(const char *mndb, char *str)
{
	char	*fr;
	int		hexa;
	int		i;
	char	*itoa;

	i = 3;
	hexa = 0;
	while (*mndb)
	{
		if (*mndb == '1')
			hexa += ft_power(2, i);
		--i;
		if (i < 0 && (fr = str))
		{
			itoa = ft_itoa_base(hexa, 16);
			str = ft_strjoin(str, itoa);
			free(itoa);
			free(fr);
			hexa = 0;
			i = 3;
		}
		++mndb;
	}
	return (str);
}

static char	*ft_exposant(const char *mndb, char *str, int i)
{
	char	*fr;
	int		exposant;
	char	*itoa;

	fr = str;
	str = ft_strjoin(str, "p");
	free(fr);
	exposant = 0;
	while (--i >= 0)
	{
		if (*mndb == '1')
			exposant += ft_power(2, i);
		++mndb;
	}
	itoa = ft_itoa(exposant - 1023);
	if (exposant - 1023 >= 0 && (fr = str))
	{
		str = ft_strjoin(str, "+");
		free(fr);
	}
	fr = str;
	str = ft_strjoin(str, itoa);
	free(itoa);
	free(fr);
	return (str);
}

char		*ft_binary_double(double db)
{
	char	*mndb;
	char	*str;
	int		i;

	i = 11;
	mndb = ft_recover_binary(db);
	str = ft_signe(mndb);
	if (*(str + 2) != '0')
	{
		str = ft_mantisse(mndb + 12, str);
		str = ft_exposant(mndb + 1, str, i);
	}
	free(mndb);
	return (str);
}
