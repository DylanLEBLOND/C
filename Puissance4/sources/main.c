/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:32:14 by abary             #+#    #+#             */
/*   Updated: 2016/02/28 19:47:13 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "puissance4.h"
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int		ret;
	char	**puissance4;

	if (argc != 3)
	{
		ft_putendl("Error: Wrong number of arguments");
		return (0);
	}
	else if ((ret = ft_check_args(argv)) != 1)
	{
		ft_display_error(ret);
		return (0);
	}
	if (!(puissance4 = ft_init_board(argv)))
	{
		ft_display_error(-10);
		return (0);
	}
	system("clear");
	ft_menu(puissance4);
	return (0);
}
