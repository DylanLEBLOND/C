/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 18:24:05 by dle-blon          #+#    #+#             */
/*   Updated: 2015/04/03 18:24:06 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_var *var)
{
	var->p_a[var->size - var->i + 1] = var->p_b[var->i - 2];
	if (options_cv(var, -1) != 2)
		write(1, " pa", 3);
	var->c += 1;
}

void	push_b(t_var *var)
{
	var->p_b[var->i - 1] = var->p_a[var->size - var->i];
	if (options_cv(var, 1) != 2)
	{
		if (var->f)
			write(1, " pb", 3);
		else
		{
			write(1, "pb", 2);
			var->f = 1;
		}
	}
	var->c += 1;
}

void	rotate(t_var *var, int *pile, int size, int ra)
{
	int j;
	int t;

	j = size - 1;
	t = pile[j];
	while (j > 0)
	{
		pile[j] = pile[j - 1];
		j--;
	}
	pile[0] = t;
	ra = options_cv(var, ra + 2);
	if (ra == 1)
	{
		if (var->f)
			write(1, " ra", 3);
		else
		{
			write(1, "ra", 2);
			var->f = 1;
		}
	}
	else if (!ra)
		write(1, " rb", 3);
	var->c += 1;
}

void	reverse_rotate(t_var *var, int *pile, int size, int ra)
{
	int j;
	int t;

	j = 0;
	t = pile[0];
	while (j < size - 1)
	{
		pile[j] = pile[j + 1];
		j++;
	}
	pile[size - 1] = t;
	ra = options_cv(var, ra + 4);
	if (ra == 1)
	{
		if (var->f)
			write(1, " rra", 4);
		else
		{
			write(1, "rra", 3);
			var->f = 1;
		}
	}
	else if (!ra)
		write(1, " rrb", 4);
	var->c += 1;
}

void	swap(t_var *var, int *pile, int pa)
{
	int swap;

	swap = pile[var->size - var->i];
	pile[var->size - var->i] = pile[var->size - var->i - 1];
	pile[var->size - var->i - 1] = swap;
	pa = options_cv(var, pa + 6);
	if (pa == 1)
	{
		if (var->f)
			write(1, " sa", 3);
		else
		{
			write(1, "sa", 2);
			var->f = 1;
		}
	}
	var->c += 1;
}
