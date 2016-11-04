/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 20:47:14 by dle-blon          #+#    #+#             */
/*   Updated: 2016/09/30 10:03:53 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <function.h>

void	basic_error (char *str)
{
	if (str)
		ft_putstr_fd (str, 2);
	exit (EXIT_FAILURE);
}

void	fatal_error (char *str)
{
	if (str)
		perror (str);
	exit (EXIT_FAILURE);
}
