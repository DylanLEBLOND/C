/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <abary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 01:30:36 by abary             #+#    #+#             */
/*   Updated: 2016/01/31 18:54:49 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtoupper(char *str)
{
	char *d;

	d = str;
	while (*str)
	{
		*str = ft_toupper(*str);
		++str;
	}
	return (str - (str - d));
}
