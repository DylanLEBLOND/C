/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 18:23:37 by dle-blon          #+#    #+#             */
/*   Updated: 2015/04/03 18:23:38 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int e)
{
	if (e >= 0)
		write(2, "Error\n", 6);
	exit(0);
}

void	ft_check(char *s)
{
	int i;
	int n;

	n = 0;
	i = 0;
	if (s[i] == '-')
		i++;
	else if (s[i] == '+')
		i++;
	while (s[i] == '0')
		i++;
	while (s[i])
	{
		i++;
		n++;
	}
	if (n > 10)
		ft_error(1);
	if (n == 10 && s[0] == '-')
		check_error(s + i - n, 0);
	else if (n == 10)
		check_error(s + i - n, 1);
}

void	check_error(char *s, int c)
{
	if (!c && ft_strcmp("2147483648", s) < 0)
		ft_error(1);
	else if (c && ft_strcmp("2147483647", s) < 0)
		ft_error(1);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
