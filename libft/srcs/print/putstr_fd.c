/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 18:32:58 by dle-blon          #+#    #+#             */
/*   Updated: 2014/11/12 07:48:11 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(t_cpchar s, int fd)
{
	int i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
			write(fd, &s[i++], 1);
	}
}