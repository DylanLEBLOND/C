/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argx2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:46:38 by abary             #+#    #+#             */
/*   Updated: 2016/01/29 15:47:20 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

char	*ft_arg_xz(va_list ap)
{
	char *str;

	str = NULL;
	if ((str = ft_ultoa_base(va_arg(ap, size_t), 16)))
		return (str);
	return (NULL);
}

char	*ft_arg_x(va_list ap)
{
	char	*str;

	str = NULL;
	if (!(str = ft_ultoa_base(va_arg(ap, unsigned int), 16)))
		return (NULL);
	return (str);
}
