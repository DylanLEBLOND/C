/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pmaskwide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 13:03:16 by abary             #+#    #+#             */
/*   Updated: 2016/02/02 13:15:48 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>
#include <stdlib.h>

/*
** join un seul cara a la fois
*/

char		*ft_widechar(wchar_t wide, char *dest)
{
	char			*str;
	unsigned int	i;
	char			*fr;

	i = 0;
	if (!(str = ft_memalloc(sizeof(char *) * 2)))
		return (NULL);
	i = wide;
	*str = i;
	fr = dest;
	if (!(dest = ft_strjoin(dest, str)))
		return (NULL);
	free(fr);
	free(str);
	return (dest);
}

char		*ft_wide11(wchar_t wide, char *dest)
{
	char			*str;
	unsigned int	i;
	char			*fr;

	i = 0;
	if (!(str = ft_memalloc(sizeof(char) * 3)))
		return (NULL);
	i = ((wide & 0x000000ff) | 0x80) & 0xBF;
	wide <<= 2;
	i |= (wide & 0x0000ff00) | 0x0000c000;
	*(str) = (i & 0x0000ff00) >> 8;
	*(str + 1) = (i & 0x000000ff);
	fr = dest;
	if (!(dest = ft_strjoin(dest, str)))
		return (NULL);
	free(fr);
	free(str);
	return (dest);
}

char		*ft_wide16(wchar_t wide, char *dest)
{
	char			*str;
	unsigned int	i;
	char			*fr;

	i = 0;
	if (!(str = ft_memalloc(sizeof(char) * 4)))
		return (NULL);
	i = ((wide & 0x000000ff) | 0x80) & 0xBF;
	wide <<= 2;
	i |= ((wide & 0x0000ff00) | 0x8000) & 0xBFFF;
	wide <<= 2;
	i |= (wide & 0x00ff0000) | 0x00E00000;
	*str = (i & 0x00ff0000) >> 16;
	*(str + 1) = (i & 0x0000ff00) >> 8;
	*(str + 2) = (i & 0x000000ff);
	fr = dest;
	if (!(dest = ft_strjoin(dest, str)))
		return (NULL);
	free(fr);
	free(str);
	return (dest);
}

char		*ft_wide(wchar_t wide, char *dest)
{
	char			*str;
	unsigned int	i;
	char			*fr;

	i = 0;
	if (!(str = ft_memalloc(sizeof(char) * 5)))
		return (NULL);
	i = 0;
	i = ((wide & 0x000000ff) | 0x80) & 0xBF;
	wide <<= 2;
	i |= ((wide & 0x0000ff00) | 0x8000) & 0xBFFF;
	wide <<= 2;
	i |= ((wide & 0x00ff0000) | 0x800000) & 0xBFFFFF;
	wide <<= 2;
	i |= (wide & 0xff000000) | 0xf0000000;
	*str = (i & 0xff000000) >> 24;
	*(str + 1) = (i & 0x00ff0000) >> 16;
	*(str + 2) = (i & 0x0000ff00) >> 8;
	*(str + 3) = (i & 0x000000ff);
	fr = dest;
	if (!(dest = ft_strjoin(dest, str)))
		return (NULL);
	free(fr);
	free(str);
	return (dest);
}
