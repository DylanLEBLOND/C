/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 17:11:20 by dle-blon          #+#    #+#             */
/*   Updated: 2015/04/01 14:20:37 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int			test_float(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ')
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

int			*ft_lentritab(int *tab, int *s, int size)
{
	int		i;
	int		j;
	int		nb;

	i = 0;
	*s = 0;
	while (*s < size && tab[*s] != -1)
		*s += 1;
	while (i < size)
	{
		j = size - 1;
		while (j)
		{
			if (tab[j] > tab[j - 1])
			{
				nb = tab[j];
				tab[j] = tab[j - 1];
				tab[j - 1] = nb;
			}
			j--;
		}
		i++;
	}
	return (tab);
}

int			ft_lennbr(int nb)
{
	int		i;

	i = 0;
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

void		test1(char *str, t_puis *tab, t_compt *cpt, int pos)
{
	t_alex	al;

	al.signe = 1;
	al.cd = 0;
	al.sv = 0;
	cpt->j == 0 && str[cpt->j] >= '0' && str[cpt->j] <= '9' ? al.cd = 1 : al.sv;
	if (str[cpt->j] >= '0' && str[cpt->j] <= '9' && str[cpt->j - 1] != '^')
	{
		al.sv = cpt->j;
		while (cpt->j && str[cpt->j] >= '0' && str[cpt->j] <= '9')
			cpt->j -= 1;
		if ((str[cpt->j] == '-') || (cpt->j > 1 && str[cpt->j - 1] == '-'))
			al.signe = -1;
		cpt->j != '^' ? al.cd = 1 : al.sv;
		cpt->j = al.sv;
	}
	if (al.cd)
	{
		al.sv = cpt->j;
		while (str[cpt->j] && str[cpt->j] != '^')
			cpt->j += 1;
		if (ft_atoi(str + cpt->j + 1) == cpt->i)
			tab[pos].nb = tab[pos].nb + ft_atof(str + al.sv) * al.signe;
		cpt->j += ft_lennbr(ft_atoi(str + cpt->j + 1));
	}
}

void		test2(char *str, t_puis *tab, t_compt *cpt, int pos)
{
	int		save;
	int		cond;
	int		signe;

	cond = 0;
	signe = 1;
	if (str[cpt->j] >= '0' && str[cpt->j] <= '9' && str[cpt->j - 1] != '^')
	{
		save = cpt->j;
		while (str[cpt->j] && str[cpt->j] >= '0' && str[cpt->j] <= '9')
			cpt->j -= 1;
		if ((str[cpt->j] == '-') || (cpt->j > 1 && str[cpt->j - 1] == '-'))
			signe = -1;
		cpt->j != '^' ? cond = 1 : signe;
		cpt->j = save;
	}
	if (cond)
	{
		save = cpt->j;
		while (str[cpt->j] && str[cpt->j] != '^')
			cpt->j += 1;
		if (ft_atoi(str + cpt->j + 1) == cpt->i)
			tab[pos].nb = tab[pos].nb + (ft_atof(str + save) * -signe);
		cpt->j += ft_lennbr(ft_atoi(str + cpt->j + 1));
	}
}
