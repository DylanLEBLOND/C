/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 15:52:29 by abary             #+#    #+#             */
/*   Updated: 2016/02/04 15:08:16 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"
#include "libft.h"
#include <stdlib.h>

static	t_con_arg	ft_init_t_con_arg(t_con_arg con_arg)
{
	ft_init_t_con(con_arg.con);
	ft_init_t_flag(con_arg.flag);
	return (con_arg);
}

int					ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*str;
	char		*form;
	t_con_arg	con_arg;

	str = NULL;
	form = NULL;
	g_nbr = 0;
	con_arg = ft_init_t_con_arg(con_arg);
	va_start(ap, format);
	if (!(str = ft_memalloc(sizeof(char) * 1)))
		return (-1);
	if (!(form = ft_strdup(format)))
		return (-1);
	if (!(str = ft_recover_flags(str, ap, con_arg, form)))
		return (-1);
	ft_putstr(str);
	free(str);
	free(form);
	va_end(ap);
	return (g_nbr);
}
