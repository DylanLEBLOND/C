/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pdescrut_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 13:25:13 by abary             #+#    #+#             */
/*   Updated: 2016/02/02 13:28:36 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

void	ft_destruct(t_arg *arg)
{
	free(arg[HH].arg);
	free(arg[LL].arg);
	free(arg[H].arg);
	free(arg[L].arg);
	free(arg[J].arg);
	free(arg[Z].arg);
	free(arg[CON].arg);
}
