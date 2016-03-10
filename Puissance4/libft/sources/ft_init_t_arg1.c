/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_arg1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 13:17:57 by abary             #+#    #+#             */
/*   Updated: 2016/02/02 13:29:38 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	ft_init_t_argc(t_arg *arg)
{
	arg[HH].p = ft_arg_c;
	arg[LL].p = ft_arg_c;
	arg[H].p = ft_arg_c;
	arg[L].p = ft_arg_lc;
	arg[J].p = ft_arg_c;
	arg[Z].p = ft_arg_c;
	arg[CON].p = ft_arg_c;
	arg[CON].arg = ft_memset(arg[CON].arg, 'c', 1);
}

void	ft_init_t_args(t_arg *arg)
{
	arg[HH].p = ft_arg_s;
	arg[LL].p = ft_arg_s;
	arg[H].p = ft_arg_s;
	arg[L].p = ft_arg_ls;
	arg[J].p = ft_arg_s;
	arg[Z].p = ft_arg_s;
	arg[CON].p = ft_arg_s;
	arg[CON].arg = ft_memset(arg[CON].arg, 's', 1);
}

void	ft_init_t_argo(t_arg *arg)
{
	arg[HH].p = ft_arg_ohh;
	arg[LL].p = ft_arg_oll;
	arg[H].p = ft_arg_oh;
	arg[L].p = ft_arg_ol;
	arg[J].p = ft_arg_oj;
	arg[Z].p = ft_arg_oz;
	arg[CON].p = ft_arg_o;
	arg[CON].arg = ft_memset(arg[CON].arg, 'o', 1);
}

void	ft_init_t_argoo(t_arg *arg)
{
	arg[HH].p = ft_arg_oohh;
	arg[LL].p = ft_arg_oll;
	arg[H].p = ft_arg_oh;
	arg[L].p = ft_arg_ol;
	arg[J].p = ft_arg_oj;
	arg[Z].p = ft_arg_oz;
	arg[CON].p = ft_arg_oo;
	arg[CON].arg = ft_memset(arg[CON].arg, 'O', 1);
}

void	ft_init_t_argx(t_arg *arg)
{
	arg[HH].p = ft_arg_xhh;
	arg[LL].p = ft_arg_xll;
	arg[H].p = ft_arg_xh;
	arg[L].p = ft_arg_xl;
	arg[J].p = ft_arg_xj;
	arg[Z].p = ft_arg_xz;
	arg[CON].p = ft_arg_x;
	arg[CON].arg = ft_memset(arg[CON].arg, 'x', 1);
}
