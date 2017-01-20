/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 08:12:23 by dle-blon          #+#    #+#             */
/*   Updated: 2015/12/23 16:21:01 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen(char const *s)
{
	size_t		i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
		i++;
	return (i);
}

void		ft_trimechap(char *s, int pos)
{
	ft_strtrim(s, pos, ' ');
	ft_strtrim(s, pos, '\n');
	ft_strtrim(s, pos, '\t');
	ft_strtrim(s, pos, '\v');
	ft_strtrim(s, pos, '\f');
	ft_strtrim(s, pos, '\r');
}

void		ft_strcut(char *str)
{
	int		i;

	i = 1;
	while (str[i])
	{
		str[i - 1] = str[i];
		i++;
	}
	str[i - 1] = '\0';
}

void		ft_trimdigit(char *s, int pos)
{
	int		i;

	if (!s)
		return ;
	if (s[pos] == '.')
		ft_strcut(s);
	ft_trimechap(s, pos);
	if (s[pos] == '-')
		ft_strcut(s);
	i = pos;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	while (s[pos] && s[i])
	{
		s[pos++] = s[i];
		i++;
	}
	while (s[pos])
		s[pos] = '\0';
}

void		ft_strtrim(char *s, int pos, char c)
{
	int		i;

	if (!s)
		return ;
	i = pos;
	while (s[i] && s[i] == c)
		i++;
	while (s[pos] && s[i])
	{
		s[pos++] = s[i];
		i++;
	}
	while (s[pos])
		s[pos] = '\0';
}
