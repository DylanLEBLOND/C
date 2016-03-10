/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_menu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 23:06:03 by abary             #+#    #+#             */
/*   Updated: 2016/02/28 02:46:02 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_display_puissance4(void)
{
	ft_putendl("/----------------------------------------------------------\\");
	ft_putstr("|    ");
	ft_putstr("   ___       _                             ____");
	ft_putendl("       |");
	ft_putstr("|    ");
	ft_putstr("  / _ \\__ __(_)__ ___ ___ ____  _______   / / /");
	ft_putendl("       |");
	ft_putstr("|    ");
	ft_putstr(" / ___/ // / (_-<(_-</ _ `/ _ \\/ __/ -_) /_  _/");
	ft_putendl("       |");
	ft_putstr("|    ");
	ft_putstr("/_/   \\_,_/_/___/___/\\_,_/_//_/\\__/\\__/   /_/  ");
	ft_putendl("       |");
}

void			ft_display_menu(void)
{
	ft_display_puissance4();
	ft_putendl("|                                                          |");
	ft_putendl("|----------------------------------------------------------|");
	ft_putendl("|----------------------------------------------------------|");
	ft_putendl("|                                                          |");
	ft_putendl("|                        Select                            |");
	ft_putendl("|                                                          |");
	ft_putendl("| 1:                                                 Start |");
	ft_putendl("| 2:                                           Change size |");
	ft_putendl("| 3:                                                  Quit |");
	ft_putendl("\\----------------------------------------------------------/");
}

void			ft_display_line(int line)
{
	ft_display_puissance4();
	ft_putendl("|                                                          |");
	ft_putendl("|----------------------------------------------------------|");
	ft_putendl("|----------------------------------------------------------|");
	ft_putendl("|                                                          |");
	if (line)
	{
		ft_putstr("| Change line :                              [enter line]");
		ft_putendl("  |");
	}
	else
	{
		ft_putstr("| Change col :                                [enter col]");
		ft_putendl("  |");
	}
	ft_putendl("|                                                          |");
	ft_putendl("|                                                          |");
	ft_putendl("\\----------------------------------------------------------/");
}
