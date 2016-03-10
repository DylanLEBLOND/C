/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_managewdchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:32:52 by abary             #+#    #+#             */
/*   Updated: 2016/02/02 13:14:45 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <wchar.h>
#include "libft.h"
#include "libftprintf.h"

static char		*ft_while_wide(wchar_t *wide, char *str)
{
	while (*wide)
	{
		if ((*wide & BITS7) == 0)
		{
			if (!(str = ft_widechar(*wide, str)))
				return (NULL);
		}
		else if ((*wide & BITS11) == 0)
		{
			if (!(str = ft_wide11(*wide, str)))
				return (NULL);
		}
		else if ((*wide & BITS16) == 0)
		{
			if (!(str = ft_wide16(*wide, str)))
				return (NULL);
		}
		else
		{
			if (!(str = ft_wide(*wide, str)))
				return (NULL);
		}
		++wide;
	}
	return (str);
}

char			*ft_convert_wide(wchar_t *wide)
{
	char *str;
	char *fr;
	char *strfr;

	fr = NULL;
	strfr = NULL;
	if (!(str = (char *)ft_memalloc(sizeof(char *))))
		return (NULL);
	if (!wide)
	{
		free(str);
		str = ft_strdup("(null)");
		return (str);
	}
	str = ft_while_wide(wide, str);
	return (str);
}
