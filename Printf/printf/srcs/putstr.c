/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 18:32:32 by dle-blon          #+#    #+#             */
/*   Updated: 2016/01/22 20:18:04 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(t_add *flag, char const *s)
{
	int			i;
	char		*str;

	if (!s)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(s);
	i = 0;
	if (flag->max < 0 && flag->prflag != -1)
		while ((int)ft_strlen(str) < flag->min--)
			ft_putchar(' ', flag);
	else if (flag->prflag != -1)
		while (flag->max < flag->min--)
			ft_putchar(' ', flag);
	if (flag->max < 0)
		flag->max = ft_strlen(str);
	while (str[i] != '\0' && i < flag->max)
		ft_putchar(str[i++], flag);
	if (flag->prflag == -1 || i < ++flag->min)
		while (i++ < flag->min)
			ft_putchar(' ', flag);
}

void	ft_putwstr(t_add *flag, wchar_t const *s)
{
	int			i;
	wchar_t		*str;

	if (!s)
		str = ft_strwdup(L"(null)");
	else
		str = ft_strwdup(s);
	i = 0;
	if (flag->max < 0 && flag->prflag != -1)
		while ((int)ft_strwlen(str) < flag->min--)
			ft_putwchar(L' ', flag);
	else if (flag->prflag != -1)
		while (flag->max < flag->min--)
			ft_putwchar(L' ', flag);
	if (flag->max < 0)
		flag->max = ft_strwlen(str);
	while (str[i] != L'\0' && i < flag->max)
		ft_putwchar(str[i++], flag);
	if (flag->prflag == -1 || i < ++flag->min)
		while (i++ < flag->min)
			ft_putwchar(L' ', flag);
}
