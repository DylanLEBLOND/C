/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 14:09:45 by dle-blon          #+#    #+#             */
/*   Updated: 2015/04/02 14:18:30 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int		*check(char *str)
{
	int		i;
	int		j;
	int		nb;
	int		*tab;

	i = 0;
	j = 0;
	tab = NULL;
	if (!(tab = (int *)malloc(sizeof(int) * 50)))
		return (NULL);
	ft_initint(tab, 49);
	while (str[i])
	{
		if (str[i] == '^')
		{
			if (j == 50 || ft_error(str + i + 1) || ft_isalpha(str[i + 1])
				|| (ft_atoi(str + i + 1) < 0) || test_float(str + i + 1))
				return (NULL);
			nb = ft_atoi(str + i + 1);
			if (ft_member(tab, nb, 49))
				tab[j++] = nb;
		}
		i++;
	}
	return (tab);
}

void	init(t_puis *tab, int *nb, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		tab[i].degre = nb[i];
		tab[i].nb = 0;
		i++;
	}
}

int		ft_equal(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (0);
}

void	remp(t_puis *tab, char *str, int *coor, int len)
{
	t_compt		cpt;
	int			c;
	int			equal;

	cpt.i = 0;
	cpt.j = 0;
	c = 0;
	equal = ft_equal(str);
	while (c <= len)
	{
		cpt.i = coor[c];
		while (cpt.j < equal)
		{
			test1(str, tab, &cpt, c);
			str[cpt.j + 1] ? cpt.j++ : equal;
		}
		while (str[cpt.j] && cpt.j >= equal)
		{
			test2(str, tab, &cpt, c);
			str[cpt.j] ? cpt.j++ : equal;
		}
		cpt.j = 0;
		c++;
	}
}

void	comput(char *str, char *flag)
{
	t_useless	u;
	int			*coor;
	t_puis		*tab;
	t_puis		*new;

	if ((coor = check(str)) && justnb(str))
	{
		coor = ft_lentritab(coor, &u.len, 50);
		if (!(tab = (t_puis *)malloc(sizeof(t_puis) * u.len)))
			exit(0);
		init(tab, coor, u.len);
		remp(tab, str, coor, u.len);
		u.zero = afftab(tab, u.len);
		tab[0].degre > 2 && tab[0].nb != 0 ? useless() : u.zero;
		new = checktab(tab, &u.len);
		if (new[0].degre == 1)
			polyone(new, flag, u.len);
		if (new[0].degre == 2)
			poly(new, flag, u.len);
		free(new);
		free(coor);
	}
	else
		printf("Wrong Syntaxe\n");
}
