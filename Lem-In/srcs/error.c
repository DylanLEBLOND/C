/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 15:47:14 by dle-blon          #+#    #+#             */
/*   Updated: 2015/10/28 19:15:15 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_error(char c)
{
	if (c == 'O')
		perror("open ");
	else if (c == 'C')
		perror("close ");
	else if (c == 'M')
		perror("malloc ");
	else if (c == 'V')
		write(2, "file empty\n", 11);
	else if (c == 'N' || c == 'S')
		write(2, "ERROR\n", 6);
	exit(0);
}
