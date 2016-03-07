/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 18:24:31 by dle-blon          #+#    #+#             */
/*   Updated: 2015/04/03 18:24:33 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		way(t_var *var, int max)
{
	int i;

	i = 0;
	while (i < var->size - var->i)
	{
		if (var->p_a[var->size - var->i - i - 1] <= max)
			return (1);
		if (var->p_a[i] <= max)
			return (0);
		i++;
	}
	return (1);
}

int		way2(t_var *var, int n)
{
	int i;

	i = 0;
	while (i < var->i - 1)
	{
		if (var->p_b[var->i - i - 3] == n)
			return (1);
		if (var->p_b[i] == n)
			return (0);
		i++;
	}
	return (1);
}

void	remp(t_var *var)
{
	int n;
	int w;
	int max;

	if (var->size - var->i >= var->pivot)
	{
		max = var->tri[var->size - var->i - var->pivot + 1];
		n = var->pivot;
		while (n != 0)
		{
			w = way(var, max);
			while (var->p_a[var->size - var->i] > max)
				w ? rotate(var, var->p_a, var->size - var->i + 1, 1)
					: reverse_rotate(var, var->p_a, var->size - var->i + 1, 1);
			push_b(var);
			var->i += 1;
			n--;
		}
	}
	else
		remp_u(var);
}

void	remp2(t_var *var)
{
	int n;
	int w;

	n = var->tri[var->size - var->i + 1];
	if (var->p_b[var->i - 2] != n)
	{
		w = way2(var, n);
		while (var->p_b[var->i - 2] != n)
		{
			if (w)
				rotate(var, var->p_b, var->i - 1, 0);
			else
				reverse_rotate(var, var->p_b, var->i - 1, 0);
		}
	}
	push_a(var);
	var->i -= 1;
}

int		main(int ac, char **av)
{
	t_var var;

	if (ac == 1)
		return (0);
	var_u(&var, ac);
	options(&var, av);
	var.size = var.size - var.o;
	var.pivot = var.size / 20;
	if (var.pivot == 0)
		var.pivot = 1;
	var.p_a = pile_a(var, av);
	var.tri = tri_tab(var.p_a, var.size, &var.t);
	algo_u(&var);
	write(1, "\n", 1);
	if (var.on)
	{
		write(1, "nombre de coups : ", 18);
		ft_putnbr(var.c);
		write(1, "\n", 1);
	}
	free(var.p_a);
	free(var.p_b);
	free(var.tri);
	return (0);
}
