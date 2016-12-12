/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 17:07:18 by dle-blon          #+#    #+#             */
/*   Updated: 2015/04/01 20:07:17 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	affpoly(t_puis *tab, int nb, t_useless *d)
{
	if (nb == 0)
		printf("%g * X^%d ", tab[nb].nb, tab[nb].degre);
	else
	{
		if (tab[nb].nb >= 0)
			printf("+ %g * X^%d ", tab[nb].nb, tab[nb].degre);
		else
			printf("- %g * X^%d ", tab[nb].nb * -1, tab[nb].degre);
	}
	tab[nb].nb != 0 ? d->nul = 1 : nb;
	if (tab[nb].nb != 0 && !d->deg)
		d->pos = nb;
	if (tab[nb].nb != 0 && !d->deg)
		d->deg = tab[nb].degre;
}

int		afftab(t_puis *tab, int len)
{
	int			i;
	t_useless	d;

	i = 0;
	d.nul = 0;
	d.deg = 0;
	d.pos = 0;
	printf("Reduced form: ");
	while (i < len)
		affpoly(tab, i++, &d);
	printf("= 0");
	if (!d.nul || d.deg == 0)
	{
		printf("\nPolynomial degree: %d\n", d.deg);
		if (tab[d.pos].nb == 0)
			printf("The solution is |R\n");
		else
			printf("No solution (%g != 0)\n", tab[d.pos].nb);
		return (-1);
	}
	else
		printf("\nPolynomial degree: %d\n", d.deg);
	return (0);
}

void	affzero(float delta, char *flag, t_val x)
{
	float	sol;

	sol = (-1 * x.b) / (2 * x.a);
	!sol ? sol = 0 : delta;
	printf("Discriminant is equal to zero, ");
	if (!ft_strcmp(flag, "-d"))
		printf("the solution is: -b / 2 * a\n%g * %g = %g\n",\
				-1 * x.b, 2 * x.a, sol);
	else
		printf("the solution is:\n%g\n", sol);
}

void	affsup(float delta, char *flag, t_val x)
{
	float	sol1;
	float	sol2;
	float	rac;

	rac = racine(delta);
	sol1 = (-1 * x.b - rac) / (2 * x.a);
	sol2 = (-1 * x.b + rac) / (2 * x.a);
	printf("Discriminant is strictly positive, the two solution are:");
	if (!ft_strcmp(flag, "-d"))
	{
		printf("\n(-b - racine(delta)) / (2 * a)");
		printf("\n(-b + racine(delta)) / (2 * a)");
		printf("\n(%g - %g) / (2 * %g)", 1 * x.b, rac, x.a);
		printf("\n(%g + %g) / (2 * %g)", 1 * x.b, rac, x.a);
	}
	printf("\n%g\n%g\n", sol1, sol2);
}

void	affneg(float delta, char *flag, t_val x)
{
	float	sol1;
	float	sol2;
	float	rac;

	rac = racine(-1 * delta);
	sol1 = (-1 * x.b) / (2 * x.a);
	sol2 = rac / (2 * x.a);
	printf("Discriminant is strictly negative, the two complex solutions are:");
	if (!ft_strcmp(flag, "-d"))
	{
		printf("\n(-b - i * racine(delta)) / (2 * a)");
		printf("\n(-b + i * racine(delta)) / (2 * a)");
		printf("\n(%g - i * %g) / (2 * %g)", -1 * x.b, rac, x.a);
		printf("\n(%g + i * %g) / (2 * %g)", -1 * x.b, rac, x.a);
	}
	printf("\n%g + i * %g\n%g - i * %g\n", sol1, sol2, sol1, sol2);
}
