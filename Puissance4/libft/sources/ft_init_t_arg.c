/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <abary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 06:17:38 by abary             #+#    #+#             */
/*   Updated: 2016/02/02 13:55:17 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdlib.h>

static void	ft_init_t_argu(t_arg *arg)
{
	arg[HH].p = ft_arg_uhh;
	arg[LL].p = ft_arg_ddll;
	arg[H].p = ft_arg_ddh;
	arg[L].p = ft_arg_ddl;
	arg[J].p = ft_arg_ddj;
	arg[Z].p = ft_arg_ddz;
	arg[CON].p = ft_arg_u;
	arg[CON].arg = ft_memset(arg[CON].arg, 'u', 1);
}

static void	ft_init_t_argdd(t_arg *arg)
{
	arg[HH].p = ft_arg_ddhh;
	arg[LL].p = ft_arg_ddll;
	arg[H].p = ft_arg_ddh;
	arg[L].p = ft_arg_ddl;
	arg[J].p = ft_arg_ddj;
	arg[Z].p = ft_arg_ddz;
	arg[CON].p = ft_arg_dd;
	arg[CON].arg = ft_memset(arg[CON].arg, 'D', 1);
}

static void	ft_init_t_argd(t_arg *arg)
{
	arg[HH].p = ft_arg_hh;
	arg[LL].p = ft_arg_ll;
	arg[H].p = ft_arg_h;
	arg[L].p = ft_arg_l;
	arg[J].p = ft_arg_j;
	arg[Z].p = ft_arg_z;
	arg[CON].p = ft_arg_d;
	arg[CON].arg = ft_memset(arg[CON].arg, 'd', 1);
}

static int	ft_init_t_arg_cara(t_arg *arg)
{
	if (!(arg[HH].arg = (char *)ft_memalloc(sizeof(char) * 3)))
		return (0);
	arg[HH].arg = ft_memset(arg[HH].arg, 'h', 2);
	if (!(arg[LL].arg = (char *)ft_memalloc(sizeof(char) * 3)))
		return (0);
	arg[LL].arg = ft_memset(arg[LL].arg, 'l', 2);
	if (!(arg[H].arg = (char *)ft_memalloc(sizeof(char) * 2)))
		return (0);
	arg[H].arg = ft_memset(arg[H].arg, 'h', 1);
	if (!(arg[L].arg = (char *)ft_memalloc(sizeof(char) * 2)))
		return (0);
	arg[L].arg = ft_memset(arg[L].arg, 'l', 1);
	if (!(arg[J].arg = (char *)ft_memalloc(sizeof(char) * 2)))
		return (0);
	arg[J].arg = ft_memset(arg[J].arg, 'j', 1);
	if (!(arg[Z].arg = (char *)ft_memalloc(sizeof(char) * 2)))
		return (0);
	arg[Z].arg = ft_memset(arg[Z].arg, 'z', 1);
	if (!(arg[CON].arg = (char *)ft_memalloc(sizeof(char) * 2)))
		return (0);
	return (1);
}

int			ft_init_t_arg(t_arg *arg, char con)
{
	if (!ft_init_t_arg_cara(arg))
		return (0);
	if (con == 'd')
		ft_init_t_argd(arg);
	else if (con == 's')
		ft_init_t_args(arg);
	else if (con == 'c')
		ft_init_t_args(arg);
	else if (con == 'o')
		ft_init_t_argo(arg);
	else if (con == 'x')
		ft_init_t_argx(arg);
	else if (con == 'u')
		ft_init_t_argu(arg);
	else if (con == 'D')
		ft_init_t_argdd(arg);
	else if (con == 'O')
		ft_init_t_argoo(arg);
	return (1);
}
