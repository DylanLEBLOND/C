/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 15:43:29 by dle-blon          #+#    #+#             */
/*   Updated: 2015/04/01 16:29:37 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	useless(void)
{
	printf("The polynomial degree is stricly ");
	printf("greater than 2, I can't solve.\n");
}

int		main(int ac, char **av)
{
	if (ac == 2)
		comput(av[1], "N");
	else if (ac == 3 && !ft_strcmp(av[1], "-d"))
		comput(av[2], av[1]);
	else if (ac == 3)
		ft_putendl("invalid argument 2 : -d to detail");
	else if (ac < 2)
		ft_putendl("not enough arguments (need 1)");
	else
		ft_putendl("too many arguments (need 1)");
	return (0);
}
