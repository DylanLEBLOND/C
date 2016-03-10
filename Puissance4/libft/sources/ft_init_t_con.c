/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_con.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:03:53 by abary             #+#    #+#             */
/*   Updated: 2016/02/03 19:02:15 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_init_t_con1(t_con *con)
{
	con[10].cara = 'U';
	con[10].p = ft_con_uu;
	con[11].cara = 'x';
	con[11].p = ft_con_x;
	con[12].cara = 'X';
	con[12].p = ft_con_xx;
	con[13].cara = '%';
	con[13].p = ft_con_prct;
	con[14].cara = 'S';
	con[14].p = ft_con_ss;
	con[15].cara = 'a';
	con[15].p = ft_con_a;
}

void		ft_init_t_con(t_con *con)
{
	con[0].cara = 'd';
	con[0].p = ft_con_d;
	con[1].cara = 'i';
	con[1].p = ft_con_d;
	con[2].cara = 'p';
	con[2].p = ft_con_p;
	con[3].cara = 's';
	con[3].p = ft_con_s;
	con[4].cara = 'D';
	con[4].p = ft_con_dd;
	con[5].cara = 'c';
	con[5].p = ft_con_c;
	con[6].cara = 'C';
	con[6].p = ft_con_cc;
	con[7].cara = 'o';
	con[7].p = ft_con_o;
	con[8].cara = 'O';
	con[8].p = ft_con_oo;
	con[9].cara = 'u';
	con[9].p = ft_con_u;
	ft_init_t_con1(con);
}
