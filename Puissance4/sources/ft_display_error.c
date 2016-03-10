/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:56:22 by abary             #+#    #+#             */
/*   Updated: 2016/02/28 02:48:48 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_display_error(int error)
{
	ft_putstr("Error: ");
	if (error == -1)
		ft_putendl("Argument given is not a number");
	if (error == -10)
		ft_putendl("allocation failed");
	if (error == -2)
		ft_putendl("number too big");
	if (error == -3)
		ft_putendl("number must be positif");
	if (error == -4)
		ft_putendl("Size of the line must be at least 6");
	if (error == -5)
		ft_putendl("Size of the column must be at least 7");
}

void	ft_display_wrong_input(int error)
{
	ft_putstr("Error: ");
	if (error == -1)
		ft_putendl("Wrong size of the col");
	else if (error == -2)
		ft_putendl("Can't be Null");
	else if (error == -3)
		ft_putendl("The column is full");
	else if (error == -4)
		ft_putendl("Wrong size of the line");
}
