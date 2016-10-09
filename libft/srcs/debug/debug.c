/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c  	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 19:59:49 by dle-blon          #+#    #+#             */
/*   Updated: 2016/10/09 20:00:06 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_debug_file (cpchar file)
{
	ft_putstr ("file:");
	ft_putendl (file);
}

void	ft_debug_line (int line)
{
	ft_putstr ("line:");
	ft_putnbr (line);
	ft_putchar ('\n');
}

void	ft_debug_file_line (cpchar file, int line)
{
	ft_putstr ("file:");
	ft_putstr (file);
	ft_putstr (" line:");
	ft_putnbr (line);
	ft_putchar ('\n');
}
