/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 22:47:48 by abary             #+#    #+#             */
/*   Updated: 2016/02/28 01:00:48 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>

/*
**	renvoie 1 si joueur commence 0 si IA
*/

int		ft_select_player(void)
{
	int player;

	player = 0;
	srand(time(NULL));
	player = rand();
	if (player % 2)
		return (1);
	else
		return (0);
}
