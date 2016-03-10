/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:11:11 by abary             #+#    #+#             */
/*   Updated: 2015/12/02 16:35:33 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	unsigned int	length_whitout_spaces(char const *s)
{
	unsigned int nb;

	nb = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (*s)
	{
		s++;
		nb++;
	}
	s--;
	if (nb != 0)
	{
		while (*s == ' ' || *s == '\n' || *s == '\t')
		{
			s--;
			nb--;
		}
	}
	return (nb);
}

static	char			*trim(char const *s, char *str, int length)
{
	unsigned int nb;

	nb = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (length > 0)
	{
		*(str + nb) = *s;
		s++;
		nb++;
		length--;
	}
	*(str + nb) = '\0';
	return (str);
}

char					*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	nb;

	if (!s)
		return (NULL);
	nb = length_whitout_spaces(s);
	str = (char *)malloc(sizeof(char) * nb + 1);
	if (!str)
		return (NULL);
	str = trim(s, str, nb);
	return (str);
}
