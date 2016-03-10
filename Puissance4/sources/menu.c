/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 22:51:08 by abary             #+#    #+#             */
/*   Updated: 2016/02/28 20:07:30 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"
#include "libft.h"
#include <stdlib.h>

static int	ft_input_line_norm(long col, int retour, int ligne, char *line)
{
	col = ft_atol(line);
	if (col > 100 || col < -2147483648)
		ft_display_error(-2);
	else if (col < 0)
		ft_display_error(-3);
	else if (ligne == 6 && col < 6)
		ft_display_error(-4);
	else if (ligne == 7 && col < 7)
		ft_display_error(-5);
	else
		retour = col;
	return (retour);
}

static int	ft_input_line(int ligne)
{
	int		retour;
	int		col;
	char	*line;
	int		ret;

	retour = 0;
	col = 0;
	line = NULL;
	while (retour == 0)
	{
		ret = get_next_line(0, &line);
		if (ret == 1)
		{
			if (!(ft_check_value(line)))
				ft_display_error(-1);
			else
				retour = ft_input_line_norm(col, retour, ligne, line);
		}
		ft_free_line(line);
	}
	return (retour);
}

static char	**ft_change_size(void)
{
	char	**p4;
	int		i;

	i = 0;
	system("clear");
	ft_display_line(1);
	g_line = ft_input_line(6);
	system("clear");
	ft_display_line(0);
	g_col = ft_input_line(7);
	if (!(p4 = (char **)ft_memalloc(sizeof(char *) * (g_line + 1))))
		return (NULL);
	while (i < g_line)
	{
		if (!(*(p4 + i) = (char *)ft_memalloc(sizeof(char) * (g_col + 1))))
			return (NULL);
		++i;
	}
	*(p4 + i) = NULL;
	system("clear");
	return (p4);
}

void		ft_menu(char **puissance)
{
	int		ok;
	char	*line;
	int		ret;

	ok = 0;
	line = NULL;
	while (ok != 3)
	{
		ft_display_menu();
		ret = get_next_line(0, &line);
		if (ret == 1)
		{
			ok = ft_atoi(line);
			if (ok == 1)
				ft_puissance4(puissance);
			else if (ok == 2)
				if (!(puissance = ft_change_size()))
					ok = 3;
		}
		puissance = ft_create_board(puissance);
		ft_free_line(line);
	}
	if (puissance)
		ft_destruct_board(puissance);
}
