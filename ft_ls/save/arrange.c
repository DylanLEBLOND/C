/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:38:37 by dle-blon          #+#    #+#             */
/*   Updated: 2016/04/04 18:51:52 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_order(char **tab, int ord, int len)
{
	int     i;
	int     j;
	int     cd;
	char    *tmp;

	i = -1;
	while (tab && tab[++i])
	{
		j = len;
		while (--j > i)
		{
			cd = ord ?
				ft_strcmp(tab[i], tab[j]) > 0 : ft_strcmp(tab[i], tab[j]) < 0;
			if (cd)
			{
				tmp = ft_strdup(tab[i]);
				free(tab[i]);
				tab[i] = ft_strdup(tab[j]);
				free(tab[j]);
				tab[j] = ft_strdup(tmp);
				free(tmp);
			}
		}
	}
}
