/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 18:23:27 by dle-blon          #+#    #+#             */
/*   Updated: 2015/04/03 18:23:30 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_tri(t_var *var)
{
	int i;

	i = 0;
	while (i < var->size)
	{
		var->p_b[i] = 0;
		i++;
	}
	while (var->size - var->i >= 0)
		remp(var);
	while (var->i > 1)
		remp2(var);
}

void	algo1(t_var *var)
{
	if (var->p_a[var->size - 1] > var->p_a[var->size - 2])
		swap(var, var->p_a, 1);
	else if (var->p_a[0] < var->p_a[1])
	{
		reverse_rotate(var, var->p_a, var->size - var->i + 1, 1);
		reverse_rotate(var, var->p_a, var->size - var->i + 1, 1);
		swap(var, var->p_a, 1);
		rotate(var, var->p_a, var->size - var->i + 1, 1);
		rotate(var, var->p_a, var->size - var->i + 1, 1);
	}
	else
	{
		while (var->p_a[var->size - 1] < var->p_a[var->size - 2])
			rotate(var, var->p_a, var->size - var->i + 1, 1);
		swap(var, var->p_a, 1);
		while (var->p_a[0] != var->tri[0])
			rotate(var, var->p_a, var->size - var->i + 1, 1);
	}
}

void	algo3(t_var *var)
{
	if (var->p_a[1] == var->tri[0])
		reverse_rotate(var, var->p_a, var->size - var->i + 1, 1);
	else if (var->p_a[2] == var->tri[0])
		rotate(var, var->p_a, var->size - var->i + 1, 1);
	if (var->p_a[1] < var->p_a[2])
		swap(var, var->p_a, 1);
}

void	algo4(t_var *var)
{
	int i;

	i = 0;
	while (var->p_a[i] != var->tri[3])
		i++;
	while (var->p_a[3] != var->tri[3])
	{
		if (i < 2)
			reverse_rotate(var, var->p_a, var->size - var->i + 1, 1);
		else
			rotate(var, var->p_a, var->size - var->i + 1, 1);
	}
	push_b(var);
	var->i += 1;
	algo3(var);
	push_a(var);
	var->i -= 1;
}

void	algo5(t_var *var)
{
	int i;

	i = 0;
	while (var->p_a[i] != var->tri[4])
		i++;
	while (var->p_a[4] != var->tri[4])
	{
		if (i < 2)
			reverse_rotate(var, var->p_a, var->size - var->i + 1, 1);
		else
			rotate(var, var->p_a, var->size - var->i + 1, 1);
	}
	push_b(var);
	var->i += 1;
	algo4(var);
	push_a(var);
	var->i -= 1;
}
