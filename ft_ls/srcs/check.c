/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:39:15 by dle-blon          #+#    #+#             */
/*   Updated: 2016/04/04 20:02:58 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_checkcurrent(char *name)
{
	int len;

	len = ft_strlen(name);
	if (len < 3)
		return (1);
	if (name[len - 1] == '.' && name[len - 2] == '/')
		return (0);
	if (name[len - 1] == '.' && name[len - 2] == '.' && name[len - 3] == '/')
		return (0);
	return (1);
}

int		ft_checkname(char **names)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (names[i])
	{
		if (!(ft_checkcurrent(names[i])))
			++nb;
		++i;
	}
	return (nb);
}

void	ft_norme(char *name, char **directories)
{
	int		i;
	char	*tmp;

	i = 0;
	ft_putendl("IM IN");
	if (!directories)
		return ;
	while (directories[i])
	{
		ft_putstr("<i = ");
		ft_putnbr(i);
		ft_putendl(">");
		tmp = ft_strjoin(ft_strjoin(name, "/"), directories[i]);
		if (directories[i])
			free(directories[i]);
		directories[i] = tmp;
		if (tmp)
			free(tmp);
		++i;
	}
	ft_putendl("IM OUT");
}
