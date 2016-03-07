/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 15:27:56 by dle-blon          #+#    #+#             */
/*   Updated: 2015/11/01 16:13:39 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_getspace(char *str)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0' && str[i] != '#')
	{
		if (str[i] == ' ')
			nb++;
		i++;
	}
	return (nb);
}

int		ft_getnbnode(char **file)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (file[i] != NULL)
	{
		if (ft_getspace(file[i]) == 2)
			nb++;
		i++;
	}
	return (nb);
}

t_node	*ft_createnode(char **file, int *node)
{
	int		len;
	t_node	*tree;

	len = ft_getnbnode(file);
	if (!(tree = (t_node *)malloc(sizeof(t_node) * (len + 1))))
		ft_error('M');
	*node = len;
	return (tree);
}

int		ft_isnum(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	return (ft_atoi(str));
}

void	ft_initnode(t_param *set)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((set->nblemin = ft_isnum(set->file[0])) < 0)
		ft_error('S');
	while (set->file[i] != NULL)
	{
		if (ft_getspace(set->file[i]) == 2)
			set->tree[j].name = ft_getname(set->file[i]);
		if (ft_getspace(set->file[i]) == 2)
			ft_getxy(set->file[i], &set->tree[j], &j, set->node);
		i++;
	}
}
