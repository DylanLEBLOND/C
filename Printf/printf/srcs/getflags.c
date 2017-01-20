/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getflags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 19:49:08 by dle-blon          #+#    #+#             */
/*   Updated: 2016/01/22 18:36:10 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initflags(t_add *add, int yes)
{
	add->min = -1;
	add->max = -1;
	add->hash = 0;
	add->prflag = 1;
	add->plflag = 0;
	add->modflag = '\0';
	add->space = 0;
	add->caps = 0;
	add->pos = 1;
	if (yes)
		add->cpt = 0;
}

void	ft_getspace(char *str, int *pos, t_add *add)
{
	if (add->space == 0 && str[*pos] == ' ')
		add->space = 1;
	else if (add->hash == 0 && str[*pos] == '#')
		add->hash = 1;
	ft_strtrim(str, *pos, str[*pos]);
	*pos = -1;
}

void	ft_getprec(char *str, int *pos, t_add *add)
{
	if (add->min == -1 && str[*pos] != '.')
		add->min = ft_atoi(str);
	if (add->min < 0)
		add->min = -1;
	if (add->max == -1 && str[*pos] == '.')
		add->max = ft_atoi(str + 1);
	if (add->max < 0)
		add->max = -1;
	ft_trimdigit(str, *pos);
	*pos = -1;
}

void	ft_getprflags(char *str, int *pos, t_add *add)
{
	if (add->prflag == 1 && (str[*pos] == '-' || str[*pos] == '0'))
	{
		if (str[*pos] == '-')
			add->prflag = -1;
		else
			add->prflag = 0;
	}
	else if (add->prflag == 0 && str[*pos] == '-')
		add->prflag = -1;
	else if (add->plflag == 0 && str[*pos] == '+')
		add->plflag = 1;
	ft_strtrim(str, *pos, str[*pos]);
	*pos = -1;
}

void	ft_getmod(char *str, int *pos, t_add *add)
{
	if (add->modflag == 0)
	{
		if (str[*pos] == 'l' && str[*pos + 1] == 'l')
			add->modflag = 'L';
		else if (str[*pos] == 'l')
			add->modflag = 'l';
		else if (str[*pos] == 'h' && str[*pos + 1] == 'h')
			add->modflag = 'H';
		else if (str[*pos] == 'h')
			add->modflag = 'h';
		else if (str[*pos] == 'j')
			add->modflag = 'j';
		else
			add->modflag = 'z';
	}
	ft_strtrim(str, *pos, str[*pos]);
	*pos = -1;
}
