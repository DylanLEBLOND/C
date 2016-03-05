/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 15:47:14 by dle-blon          #+#    #+#             */
/*   Updated: 2015/05/28 15:47:59 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	coderror(char c)
{
	if (c == 'O')
		perror("open ");
	else if (c == 'C')
		perror("close ");
	else if (c == 'M')
		perror("malloc ");
	else if (c == '1')
		perror("libft (strdup) ");
	exit(0);
}
