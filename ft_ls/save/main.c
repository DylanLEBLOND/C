/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:46:20 by dle-blon          #+#    #+#             */
/*   Updated: 2016/03/22 18:47:20 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

#if 0
void	ft_freedata(t_data *data)
{
}
#endif

int		main(int ac, char **av)
{
	int		i;
	t_data	data;

	i = 1;
	ft_init(&data, ac + 1);
	while (i <= ac - 1)
	{
		if (av[i][0] == '-')
			ft_getoptions(&data, av[i]);
		else
			ft_getnames(&data, av[i]);
		++i;
	}
	if (data.nb == 0)
		data.names[0] = ft_strdup(".");
	if (data.nb == 0)
		data.nb++;
	ft_affinfo(data);
	ft_putendl("Start ft_ls");
	ft_ls(data.names, data.option, data.nb, 1);
	return (0);
}
