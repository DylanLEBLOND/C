/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynome.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 17:15:34 by dle-blon          #+#    #+#             */
/*   Updated: 2015/04/01 18:43:47 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

float		racine(float nb)
{
	int		i;
	float	max;
	float	var;

	i = 0;
	while (i * i < nb)
		i++;
	var = 0.5;
	max = i;
	while (var > 0.000001)
	{
		if (max * max > nb)
			max -= var;
		else if (max * max < nb)
		{
			var *= 1.5;
			max += var;
		}
		var /= 2;
	}
	return (max);
}

void		initvaleur(t_puis *tab, t_val *x, int len)
{
	x->a = tab[0].nb;
	len == 3 ? x->b = tab[1].nb : len;
	len == 3 ? x->c = tab[2].nb : len;
	len == 2 && tab[1].degre == 1 ? x->b = tab[1].nb : len;
	len == 2 && tab[1].degre == 1 ? x->c = 0 : len;
	len == 2 && tab[1].degre == 0 ? x->b = 0 : len;
	len == 2 && tab[1].degre == 0 ? x->c = tab[1].nb : len;
}

void		polyone(t_puis *tab, char *flag, int len)
{
	float	sol;
	int		s;

	if (len == 2)
	{
		s = -1;
		tab[1].nb == 0 ? s = 1 : s;
		sol = (s * tab[1].nb) / tab[0].nb;
		if (!ft_strcmp(flag, "-d"))
			printf("solution = -b / a = %g / %g\n", s * tab[1].nb, tab[0].nb);
		printf("The solution is:\n%g\n", sol);
	}
	else
		printf("The solution is:\n%g\n", 0.0);
}

void		poly(t_puis *tab, char *flag, int len)
{
	t_val	x;
	float	delta;

	if (len == 1)
		printf("The solution is:\n%g\n", 0.0);
	else
	{
		initvaleur(tab, &x, len);
		delta = x.b * x.b - 4 * x.a * x.c;
		if (!ft_strcmp(flag, "-d"))
		{
			printf("The discriminant is: b^2 - 4 * a * c\n");
			printf("%g - 4 * %g * %g = %g\n", x.b * x.b, x.a, x.c, delta);
		}
		if (delta == 0)
			affzero(delta, flag, x);
		else if (delta > 0)
			affsup(delta, flag, x);
		else
			affneg(delta, flag, x);
	}
}
