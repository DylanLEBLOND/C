/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_result.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 02:04:15 by abary             #+#    #+#             */
/*   Updated: 2016/02/28 02:38:15 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_display_you_loose(void)
{
	ft_putstr("       ");
	ft_putendl("                         __                    ");
	ft_putstr("       ");
	ft_putendl("   __  ______  __  __   / /___  ____  ________ ");
	ft_putstr("       ");
	ft_putendl("  / / / / __ \\/ / / /  / / __ \\/ __ \\/ ___/ _ \\");
	ft_putstr("       ");
	ft_putendl(" / /_/ / /_/ / /_/ /  / / /_/ / /_/ (__  )  __/");
	ft_putstr("       ");
	ft_putendl(" \\__, /\\____/\\__,_/  /_/\\____/\\____/____/\\___/ ");
	ft_putstr("       ");
	ft_putendl("/____/                                         ");
}

void	ft_display_you_won(void)
{
	ft_putstr("       ");
	ft_putendl("                         _       __          ");
	ft_putstr("       ");
	ft_putendl("   __  ______  __  __   | |     / /___  ____ ");
	ft_putstr("       ");
	ft_putendl("  / / / / __ \\/ / / /   | | /| / / __ \\/ __ \\");
	ft_putstr("       ");
	ft_putendl(" / /_/ / /_/ / /_/ /    | |/ |/ / /_/ / / / /");
	ft_putstr("       ");
	ft_putendl(" \\__, /\\____/\\__,_/     |__/|__/\\____/_/ /_/ ");
	ft_putstr("       ");
	ft_putendl("/____/                                       ");
}

void	ft_display_null(void)
{
	ft_putstr("              ");
	ft_putendl("    _   ____  ____    __ ");
	ft_putstr("              ");
	ft_putendl("   / | / / / / / /   / / ");
	ft_putstr("              ");
	ft_putendl("  /  |/ / / / / /   / /  ");
	ft_putstr("              ");
	ft_putendl(" / /|  / /_/ / /___/ /___");
	ft_putstr("              ");
	ft_putendl("/_/ |_/\\____/_____/_____/");
}
