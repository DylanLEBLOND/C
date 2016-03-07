/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 15:05:17 by dle-blon          #+#    #+#             */
/*   Updated: 2015/02/23 15:59:06 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	coderror(char c)
{
	if (c == 'O')
		perror("open ");
	else if (c == 'm')
		perror("minilibx ");
	else if (c == 'N')
		ft_putendl_fd("Map Vide", 2);
	else if (c == 'C')
		perror("close ");
	else if (c == 'M')
		perror("malloc ");
	else if (c == 'G')
		perror("get_next_line ");
	else if (c == '1')
		perror("libft (strdup) ");
	exit(0);
}
