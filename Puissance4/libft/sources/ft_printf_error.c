/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:48:47 by abary             #+#    #+#             */
/*   Updated: 2016/02/26 14:54:59 by abary            ###   ########.fr       */
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

int					ft_printf_error(const char *format, ...)
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
	ft_putstr_fd(str, 2);
	free(str);
	free(form);
	va_end(ap);
	return (g_nbr);
}
