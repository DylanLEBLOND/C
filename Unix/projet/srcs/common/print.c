/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 20:47:14 by dle-blon          #+#    #+#             */
/*   Updated: 2016/09/30 15:17:47 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <function.h>

void	ft_fill_tab (char *str, int length)
{
	int i;
	
	i = 0;
	while (i < length - 1)
		str[i++] = '\t';
	str[i] = '\0';
}

void	ft_putstr (char const *s, int eol)
{
	int i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
			write (1, &s[i++], 1);
		if (eol)
			write (1, "\n", 1);
	}
}

void	ft_putstr_fd (char const *s, int fd)
{
	int i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
			write (fd, &s[i++], 1);
	}
}
