/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 15:59:45 by dle-blon          #+#    #+#             */
/*   Updated: 2015/11/01 20:24:57 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_getdash(char *str)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	if (!ft_strcmp("##start", str))
		return (-2);
	if (!ft_strcmp("##end", str))
		return (-3);
	while (str[i] != '\0' && str[0] != '#')
	{
		if (str[i] == '-' && nb)
			return (-1);
		if (str[i] == '-' && !nb)
			nb = i;
		i++;
	}
	if (nb)
		return (nb);
	return (-1);
}

void	ft_addlink(t_node *node1, int nb1, t_node *node2, int nb2)
{
	int		i;

	i = 0;
	while (i < node1->nblinks && node1->links[i] != nb2)
		i++;
	if (i != node1->nblinks)
		return ;
	node1->links[node1->nblinks] = nb2;
	node1->nblinks += 1;
	node2->links[node2->nblinks] = nb1;
	node2->nblinks += 1;
}

void	ft_confignode(t_node *tree, char *str, int nbnode, int dash)
{
	int		i;
	int		j;
	char	*n1;
	char	*n2;

	n1 = NULL;
	n2 = NULL;
	if (!(n1 = ft_strsub(str, 0, dash)))
		ft_error('M');
	if (!(n2 = ft_strsub(str, dash + 1, ft_strlen(str) - dash)))
		ft_error('M');
	i = 0;
	j = 0;
	while (i < nbnode && ft_strcmp(n1, tree[i].name) != 0)
		i++;
	while (j < nbnode && ft_strcmp(n2, tree[j].name) != 0)
		j++;
	ft_addlink(&tree[i], i, &tree[j], j);
	if (n1)
		free(n1);
	if (n2)
		free(n2);
}

int		ft_wall(char **tab, int ind, t_node *tree, int nbnode)
{
	int		i;
	int		dash;
	char	*name;

	i = ind + 1;
	while (i < nbnode && tab[i][0] == '#' && tab[i][1] != '#')
		i++;
	if ((dash = ft_getspace(tab[i])) != 2)
		return (-1);
	if (!(name = ft_strsub(tab[i], 0, dash - 1)))
		ft_error('M');
	i = 0;
	while (i < nbnode && ft_strcmp(name, tree[i].name) != 0)
		i++;
	if (name)
		free(name);
	if (i == nbnode)
		return (-1);
	return (i);
}

void	ft_initlinks(t_param *set)
{
	int		i;
	int		dash;

	i = 0;
	set->start = -1;
	set->end = -1;
	while (set->file[i] != NULL)
	{
		if ((dash = ft_getdash(set->file[i])) > -1)
			ft_confignode(set->tree, set->file[i], set->node, dash);
		else if ((dash == -2 && set->start != -1)
				|| (dash == -3 && set->end != -1))
			ft_error('S');
		else if (dash == -2)
			set->start = ft_wall(set->file, i, set->tree, set->node);
		else if (dash == -3 && set->end == -1)
			set->end = ft_wall(set->file, i, set->tree, set->node);
		i++;
	}
	if (set->start < 0 || set->end < 0)
		ft_error('S');
}
