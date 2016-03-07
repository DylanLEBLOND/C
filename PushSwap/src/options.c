/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 18:24:12 by dle-blon          #+#    #+#             */
/*   Updated: 2015/04/03 18:24:20 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	options(t_var *var, char **av)
{
	int i;
	int j;

	j = 1;
	while (av[j] && av[j][0] == '-' &&
		(av[j][1] == 'c' || av[j][1] == 'v' || av[j][1] == 'n'))
	{
		i = 1;
		while (av[j][i] == 'c' || av[j][i] == 'v' || av[j][i] == 'n')
		{
			if (av[j][i] == 'c')
				var->oc = 1;
			else if (av[j][i] == 'v')
				var->ov = 1;
			else if (av[j][i] == 'n')
				var->on = 1;
			i++;
		}
		if (av[j][i])
			ft_error(4);
		var->o += 1;
		j++;
	}
}

int		options_cv(t_var *var, int n)
{
	if (!var->oc && !var->ov)
		return (n % 2);
	else if (!var->oc && var->ov)
		ov(var, n);
	else if (var->oc && var->ov)
		ocv(var, n);
	else
		oc(var, n);
	return (2);
}

void	oc(t_var *var, int n)
{
	if (var->f)
		write(1, " ", 1);
	else
		var->f = 1;
	if (n == -1)
		ft_putstr("\033[31mpa\033[37m");
	else if (n == 1)
		ft_putstr("\033[32mpb\033[37m");
	else if (n == 2)
		ft_putstr("\033[33mrb\033[37m");
	else if (n == 3)
		ft_putstr("\033[34mra\033[37m");
	else if (n == 4)
		ft_putstr("\033[35mrrb\033[37m");
	else if (n == 5)
		ft_putstr("\033[36mrra\033[37m");
	else if (n == 6)
		write (1, "sb", 2);
	else if (n == 7)
		write (1, "sa", 2);
}

void	ov(t_var *var, int n)
{
	if (var->f)
		write(1, "\n", 1);
	else
		var->f = 1;
	if (n == -1)
		write (1, "pa", 2);
	else if (n == 1)
		write (1, "pb", 2);
	else if (n == 2)
		write (1, "rb", 2);
	else if (n == 3)
		write (1, "ra", 2);
	else if (n == 4)
		write (1, "rrb", 3);
	else if (n == 5)
		write (1, "rra", 3);
	else if (n == 6)
		write (1, "sb", 2);
	else if (n == 7)
		write (1, "sa", 2);
	(n != -1 && n != 1) ? n = 0 : n;
	aff_tab(var->p_a, var->size - var->i + 1 - n, 1);
	aff_tab(var->p_b, var->i - 1 + n, 0);
}

void	ocv(t_var *var, int n)
{
	if (var->f)
		write(1, "\n", 1);
	else
		var->f = 1;
	if (n == -1)
		ft_putstr("\033[31mpa\033[37m");
	else if (n == 1)
		ft_putstr("\033[32mpb\033[37m");
	else if (n == 2)
		ft_putstr("\033[33mrb\033[37m");
	else if (n == 3)
		ft_putstr("\033[34mra\033[37m");
	else if (n == 4)
		ft_putstr("\033[35mrrb\033[37m");
	else if (n == 5)
		ft_putstr("\033[36mrra\033[37m");
	else if (n == 6)
		write (1, "sb", 2);
	else if (n == 7)
		write (1, "sa", 2);
	(n != -1 && n != 1) ? n = 0 : n;
	aff_tab(var->p_a, var->size - var->i + 1 - n, 1);
	aff_tab(var->p_b, var->i - 1 + n, 0);
}
