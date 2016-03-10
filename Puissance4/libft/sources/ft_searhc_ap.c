/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searhc_ap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 14:00:40 by abary             #+#    #+#             */
/*   Updated: 2016/02/01 16:27:42 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

char	*ft_search_ap(char *format, int d, va_list ap, char letter)
{
	char	*str;
	int		i;
	t_arg	arg[S_TAB_ARG];

	if (!ft_init_t_arg(arg, letter))
		return (NULL);
	i = -1;
	str = NULL;
	*format = letter;
	while (++i < S_TAB_ARG)
	{
		if (ft_strchrstr(format - d, arg[i].arg, letter))
		{
			ft_destruct(arg);
			if ((str = arg[i].p(ap)))
				return (str);
			else
				return (NULL);
		}
	}
	return (NULL);
}
