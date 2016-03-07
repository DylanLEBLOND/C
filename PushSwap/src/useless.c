/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useless.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 18:25:01 by dle-blon          #+#    #+#             */
/*   Updated: 2015/04/03 18:25:05 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remp_u(t_var *var)
{
	while (var->size - var->i >= 0)
	{
		push_b(var);
		var->i += 1;
	}
}

void	algo_u(t_var *var)
{
	if (!(var->p_b = malloc(sizeof(int) * var->size)))
		ft_error(3);
	if (var->t == 0)
	{
		if (var->on && var->size)
			ft_putstr("nombre de coups : 0\n");
		exit(0);
	}
	else if (var->t == 1 && var->size != 3)
		algo1(var);
	else if (var->size == 3)
		algo3(var);
	else if (var->size == 4)
		algo4(var);
	else if (var->size == 5)
		algo5(var);
	else
		algo_tri(var);
}

void	var_u(t_var *var, int ac)
{
	var->f = 0;
	var->c = 0;
	var->i = 1;
	var->o = 0;
	var->oc = 0;
	var->on = 0;
	var->ov = 0;
	var->size = ac - 1;
}

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}
