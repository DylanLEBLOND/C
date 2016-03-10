/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 13:58:40 by abary             #+#    #+#             */
/*   Updated: 2016/02/03 14:13:18 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	ft_init_t_flag(t_flag *flag)
{
	flag[HASH].cara = '#';
	flag[HASH].p = ft_flag_hash;
	flag[ZERO].cara = '0';
	flag[ZERO].p = ft_flag_0;
	flag[MINUS].cara = '-';
	flag[MINUS].p = ft_flag_minus;
	flag[PLUS].cara = '+';
	flag[PLUS].p = ft_flag_plus;
	flag[SPACE].cara = ' ';
	flag[SPACE].p = ft_flag_space;
	flag[DIGIT].p = ft_flag_digit;
	flag[PRECISION].cara = '.';
	flag[PRECISION].p = ft_flag_precision;
}

void	ft_init_f_clear(char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	if (f_tab[MINUS])
		f_tab[ZERO] = NULL;
	if (f_tab[PRECISION])
	{
		f_tab[DIGIT] = NULL;
		f_tab[ZERO] = NULL;
	}
}

void	ft_init_f_tab(char *(*f_tab[S_TAB_FLAG])(char *, int, char *))
{
	int i;

	i = -1;
	while (++i < S_TAB_FLAG)
		f_tab[i] = NULL;
}
