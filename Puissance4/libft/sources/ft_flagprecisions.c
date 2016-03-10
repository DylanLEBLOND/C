/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagprecisions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 14:51:53 by abary             #+#    #+#             */
/*   Updated: 2016/02/02 16:40:14 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

char		*ft_flag_precisionss(char *format, int d, char *str)
{
	int		c;
	long	i;

	c = d;
	while (*(format - d) != '.')
		--d;
	i = ft_atoi(format - --d);
	str = ft_strndup(str, i);
	str = ft_flag_digit(format, c, str);
	return (str);
}
