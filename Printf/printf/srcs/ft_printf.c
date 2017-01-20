/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:33:38 by dle-blon          #+#    #+#             */
/*   Updated: 2016/02/01 18:33:49 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rectflag(t_add *add)
{
	if (add->prflag == 0 && add->max != -1)
		add->prflag = 1;
	if (add->space == 1 && add->plflag == 1)
		add->space = 0;
}

void	ft_getflags(char *str, t_add *add)
{
	int		i;

	i = 0;
	while (str[i] && !ft_strchr("idDoOuUxXfFcCsSpbBZ", str[i]))
	{
		if (str[i] == ' ' || str[i] == '#')
			ft_getspace(str, &i, add);
		else if (ft_strchr("lhjz", str[i]))
			ft_getmod(str, &i, add);
		else if (ft_strchr("-0+", str[i]))
			ft_getprflags(str, &i, add);
		else if (ft_isdigit(str[i]) || str[i] == '.')
			ft_getprec(str, &i, add);
		i++;
	}
	ft_rectflag(add);
}

char	*ft_getconv(char *str, va_list *ap, t_add *flags)
{
	initflags(flags, 0);
	if (*str == '%')
		ft_putchar(*str, flags);
	if (*str == '%')
		return ((char *)++str);
	ft_getflags(str, flags);
	if (!*str)
		return (str);
	else if (!ft_strchr("idDuUoOfFxXbBZcCsSp", *str))
		return (str);
	else if (ft_strchr("idDuU", *str))
		base_int(flags, ap, *str);
	else if (ft_strchr("poOxXbBZ", *str))
		base_oh(flags, ap, *str);
	else if (ft_strchr("cCsS", *str))
		base_char(flags, ap, *str);
	return ((char *)++str);
}

int		ft_printf(char const *str, ...)
{
	int		i;
	char	*tmp;
	t_add	flags;
	va_list	ap;

	i = 0;
	initflags(&flags, 1);
	if (!(tmp = ft_strdup(str)))
		return (-1);
	va_start(ap, str);
	while (*tmp)
	{
		if (*tmp == '%')
			tmp = ft_getconv((char *)++tmp, &ap, &flags);
		else
			ft_putchar(*tmp++, &flags);
	}
	va_end(ap);
	return (flags.cpt);
}
