/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:11:46 by abary             #+#    #+#             */
/*   Updated: 2015/12/02 16:11:50 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	nbr_of_words(char const *s, char c)
{
	unsigned int (nbw);

	nbw = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			nbw++;
			while (*s && *s != c)
				s++;
		}
	}
	return (nbw);
}

static unsigned int	len_of_words(char const *s, char c, unsigned int nb_wrd)
{
	unsigned int len;
	unsigned int word;

	len = 0;
	word = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			word++;
			while (*s && *s != c)
			{
				if (word == nb_wrd)
					len++;
				s++;
			}
		}
	}
	return (len);
}

static char			*one_word(char const *s, char c,
		unsigned int nb_wrd, char *one_word)
{
	unsigned int word;
	unsigned int nb;

	nb = 0;
	word = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			word++;
			while (*s && *s != c)
			{
				if (word == nb_wrd)
				{
					*(one_word + nb) = *s;
					nb++;
				}
				s++;
			}
		}
	}
	*(one_word + nb) = '\0';
	return (one_word);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**str;
	unsigned int	nbw;
	unsigned int	ln_wrd;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 1;
	nbw = nbr_of_words(s, c);
	str = (char **)malloc(sizeof(char *) * nbw + 1);
	if (!str)
		return (NULL);
	while (i <= nbw)
	{
		ln_wrd = len_of_words(s, c, i);
		if (!(*(str + i - 1) = (char *)malloc(sizeof(char) * ln_wrd + 1)))
			return (NULL);
		one_word(s, c, i, *(str + i - 1));
		i++;
	}
	*(str + i - 1) = NULL;
	return (str);
}
