/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 20:48:20 by dle-blon          #+#    #+#             */
/*   Updated: 2015/10/28 19:36:57 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*ft_getname(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	return (ft_strsub(str, 0, i));
}

void	ft_getxy(char *str, t_node *node, int *pos, int nbnode)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	node->x = ft_atoi(str + i);
	i++;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	node->y = ft_atoi(str + i);
	if (!(node->links = (int *)malloc(sizeof(int) * (nbnode))))
		ft_error('M');
	i = 0;
	while (i < nbnode)
		node->links[i++] = -1;
	node->nblinks = 0;
	*pos += 1;
	node->washere = 0;
}
