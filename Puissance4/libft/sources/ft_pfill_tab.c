/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfill_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 17:07:36 by abary             #+#    #+#             */
/*   Updated: 2016/02/03 14:11:27 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

static	int	ft_skip(char **format)
{
	int vrai;

	vrai = 0;
	--*format;
	if ((*(*format) == 'h' && *(*format + 1) == 'h') ||
			((**format) == 'l' && *(*format + 1) == 'l'))
	{
		vrai = 1;
		*format += 2;
	}
	else if (**format == 'h' || **format == 'l' ||
			**format == 'j' || **format == 'z')
	{
		vrai = 1;
		++*format;
	}
	return (vrai);
}

static void	ft_norme(int *vrai, char *(*f_tab[S_TAB_FLAG])
			(char *, int, char *), int i, t_flag *flag)
{
	*vrai = 1;
	f_tab[i] = flag[i].p;
}

static int	ft_undefined_behavior(char *(*f_tab[S_TAB_FLAG])
			(char *, int, char *), char **format, t_flag *flag)
{
	int f;
	int i;
	int vrai;

	vrai = 0;
	f = 1;
	while (**format && f)
	{
		f = 0;
		i = -1;
		while (++i < S_TAB_FLAG && !f)
			if (flag[i].cara == **format && (f = 1))
				ft_norme(&vrai, f_tab, i, flag);
		if (ft_isdigit(**format) && (f = 1) && **format != '0')
		{
			while (ft_isdigit(**format))
				++*format;
			--*format;
			f_tab[5] = flag[5].p;
			vrai = 1;
		}
		++*format;
	}
	return (vrai);
}

char		*ft_fill_f_tab(char *(*f_tab[S_TAB_FLAG])(char *, int, char *),
		char *format, t_flag *flag)
{
	int i;
	int f;
	int test;

	test = 0;
	f = 1;
	i = 1;
	ft_init_f_tab(f_tab);
	f = ft_undefined_behavior(f_tab, &format, flag);
	i = ft_skip(&format);
	if (f || i)
	{
		f = ft_undefined_behavior(f_tab, &format, flag);
		i = ft_skip(&format);
	}
	return (format);
}
