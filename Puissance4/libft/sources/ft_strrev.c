/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:05:20 by abary             #+#    #+#             */
/*   Updated: 2016/01/10 14:55:36 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		length;
	int		nbr;
	int		middle;
	char	swap;

	length = 0;
	if (str)
		length = ft_strlen(str);
	if (length == 0)
		return (NULL);
	middle = length / 2;
	nbr = 0;
	while (length > middle)
	{
		swap = *(str + nbr);
		*(str + nbr) = *(str + length - 1);
		*(str + length - 1) = swap;
		nbr++;
		length--;
	}
	return (str);
}
