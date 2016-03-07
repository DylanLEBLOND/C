/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_road.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 19:34:05 by dle-blon          #+#    #+#             */
/*   Updated: 2015/11/01 19:14:17 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_addroad(t_road *tmp, t_road *roads, int *nbroad)
{
	int		i;

	i = 0;
	roads[*nbroad].len = tmp->len;
	if (!(roads[*nbroad].nodes = (int *)malloc(sizeof(int) * tmp->len)))
		ft_error('M');
	while (i < tmp->len)
	{
		roads[*nbroad].nodes[i] = tmp->nodes[i];
		i++;
	}
	*nbroad += 1;
	if (*nbroad >= 100)
		ft_error('S');
}

void	ft_nodelink(t_node *node, t_param *set, t_road *tmproad)
{
	int		i;
	int		j;

	if (ft_strcmp(node->name, set->tree[set->end].name) == 0)
		ft_addroad(tmproad, set->roads, &set->nbroad);
	else
	{
		i = 0;
		j = tmproad->len;
		tmproad->len += 1;
		while (i < node->nblinks)
		{
			node->washere = 1;
			if (!(set->tree[(node->links[i])]).washere)
			{
				tmproad->nodes[j] = node->links[i];
				ft_nodelink(&set->tree[node->links[i]], set, tmproad);
			}
			i++;
		}
		tmproad->len -= 1;
	}
	node->washere = 0;
}

void	ft_getroad(t_param *set)
{
	t_road	tmp;

	if (!(set->roads = (t_road *)malloc(sizeof(t_road) * 100)))
		ft_error('M');
	if (!(tmp.nodes = (int *)malloc(sizeof(int) * (set->node + 1))))
		ft_error('M');
	tmp.nodes[0] = set->start;
	tmp.len = 1;
	ft_nodelink(&set->tree[set->start], set, &tmp);
	if (set->nbroad == 0)
		ft_error('S');
}
