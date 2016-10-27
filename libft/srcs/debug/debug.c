/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nezdebug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 20:58:50 by dle-blon          #+#    #+#             */
/*   Updated: 2016/10/27 21:00:49 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_debug_file(t_cpchar file)
{
	ft_putstr("file:");
	ft_putendl(file);
}

void	ft_debug_line(int line)
{
	ft_putstr("line:");
	ft_putnbr(line);
	ft_putchar('\n');
}

void	ft_debug_file_line(t_cpchar file, int line)
{
	ft_putstr("file:");
	ft_putstr(file);
	ft_putstr(" line:");
	ft_putnbr(line);
	ft_putchar('\n');
}
