/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:06:13 by dle-blon          #+#    #+#             */
/*   Updated: 2016/02/11 20:58:10 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char	**file;
	t_info	data;

	if (ac != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	file = ft_organize(av[1]);
	ft_getdata(file, &data);
	validtetri(&data);
	algo(data);
	return (0);
}
