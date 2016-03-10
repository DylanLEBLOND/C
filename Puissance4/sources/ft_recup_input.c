/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 14:05:47 by abary             #+#    #+#             */
/*   Updated: 2016/02/28 17:47:04 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "puissance4.h"
#include <stdlib.h>

static int	ft_recup_input_norm(char **p4, char *line, long col, int retour)
{
	col = ft_atol(line);
	if (col > 2147483647 || col < -2147483648)
		ft_display_error(-2);
	else if (col < 0)
		ft_display_error(-3);
	else if (col > g_col)
		ft_display_wrong_input(-1);
	else if (col == 0)
		ft_display_wrong_input(-2);
	else if (!ft_check_column(p4, col - 1))
		ft_display_wrong_input(-3);
	else
		retour = col;
	return (retour);
}

int			ft_recup_input(char **p4)
{
	long	col;
	int		retour;
	char	*line;
	int		ret;

	col = 0;
	line = NULL;
	retour = 0;
	while (retour == 0)
	{
		ret = get_next_line(0, &line);
		if (ret == 1)
		{
			if (!(ft_check_value(line)))
				ft_display_error(-1);
			else
				retour = ft_recup_input_norm(p4, line, col, retour);
		}
		ft_free_line(line);
	}
	return (retour);
}
