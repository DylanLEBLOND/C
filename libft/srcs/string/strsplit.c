/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 16:04:13 by dle-blon          #+#    #+#             */
/*   Updated: 2015/01/07 21:24:28 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_compt(cpchar s, char c)
{
	int	i;
	int	cmp;

	i = 0;
	cmp = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			cmp++;
			while (s[i] && s[i] == c)
				i++;
		}
		if (s[i])
			i++;
	}
	if (s[0] == c && s[i - 1] == c && cmp != 1)
		return (cmp - 1);
	if (s[0] != c && s[i - 1] != c && cmp != 0)
		return (cmp + 1);
	return (cmp);
}

static int	ft_uselesslikehell(cpchar s, int j, char c)
{
	while (s[j] && s[j] == c)
		j++;
	return (j);
}

static char	**ft_strone(cpchar s, int cmp, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		len;

	if (!(tab = (char **)malloc(sizeof(char *) * (cmp + 1))))
		return (NULL);
	i = 0;
	j = 0;
	len = 0;
	while (i < cmp)
	{
		j = ft_uselesslikehell(s, j, c);
		while (s[j + len] != c)
			len++;
		if (!(tab[i] = ft_strsub(s, j, len)))
			return (NULL);
		j += len;
		len = 0;
		i++;
	}
	if (!(tab[i] = (char *)malloc(sizeof(char))))
		return (NULL);
	tab[i] = 0;
	return (tab);
}

static char	**ft_cmpone(cpchar s, int cmp, char c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (s[0] == c && s[i - 1] == c)
		return (ft_strone("", 1, '\0'));
	else
		return (ft_strone(s, cmp, c));
}

char		**ft_strsplit(cpchar s, char c)
{
	int		cmp;

	if (s)
	{
		cmp = ft_compt(s, c);
		if (cmp == 0)
			return (ft_strone(s, 1, '\0'));
		else if (cmp == 1)
			return (ft_cmpone(s, cmp, c));
		else
			return (ft_strone(s, cmp, c));
	}
	return (NULL);
}
