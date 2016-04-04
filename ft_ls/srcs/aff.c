/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:35:22 by dle-blon          #+#    #+#             */
/*   Updated: 2016/04/04 19:57:17 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_affinfo(t_data data)
{
	int i;

	ft_putstr("nb = ");
	ft_putnbr(data.nb);
	ft_putstr(" | options : ");
	ft_putstr(data.option);
	i = -1;
	ft_putstr("\nnames : ");
	while (++i < data.nb)
	{
		ft_putstr(data.names[i]);
		if (i < data.nb - 1)
			ft_putstr(" | ");
		else
			ft_putendl("");
    }
}

void	ft_afftab(char **elem, char *option)
{
	int		i;

	i = 0;
	while (option && ft_strchr(option, 'a') && elem[i])
	{
		ft_putstr(elem[i]);
		if (elem[++i] != NULL)
			ft_putstr("  ");
		++i;
	}
	while (elem[i])
	{
		if (elem[i][0] != '.')
			ft_putstr(elem[i]);
		if (elem[i + 1] != NULL && elem[i][0] != '.' && elem[i + 1][0] != '.')
			ft_putstr("  ");
		++i;
	}
}

void	ft_affdefault(char **elem, char *option, int len)
{
	int ord;

	if (option == NULL || !ft_strchr(option, 'r'))
		ord = 1;
	else 
		ord = 0;
	ft_order(elem, ord, len);
	ft_afftab(elem, option);
}

void	ft_affall(t_data data, char *option, char *name)
{
    int		i;
    char	**tmp;

	if (!(tmp = ft_fusion(data)))
		ft_error("Malloc", 1);
	if (option != NULL && ft_strchr(option, 'R'))
	{
		ft_putstr(name);
		ft_putendl(":");
	}
	if (option == NULL || ft_strchr(option, 'a') || ft_strchr(option, 'r'))
		ft_affdefault(tmp, option, data.nb + data.nbf);
	ft_putendl("");
//	ft_free(tmp, data.files);
}
