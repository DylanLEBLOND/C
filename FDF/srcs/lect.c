/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:34:56 by dle-blon          #+#    #+#             */
/*   Updated: 2015/02/20 16:45:36 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**tabreal(char **tab, char *newline, int len)
{
	int				i;
	char			**realtab;

	i = 0;
	if (!newline)
		return (tab);
	if (!(realtab = (char **)malloc(sizeof(char *) * (len + 2))))
		coderror('M');
	while (len != 0 && i < len)
	{
		(realtab[i] = ft_strdup(tab[i])) ? i : coderror('1');
		ft_strclr(tab[i]);
		free(tab[i]);
		i++;
	}
	(realtab[i] = ft_strdup(newline)) ? i : coderror('1');
	realtab[i + 1] = NULL;
	return (realtab);
}

char	**getnext(char *param, int *len)
{
	int		fd;
	int		ret;
	char	*str;
	char	**tab;

	if ((fd = open(param, O_RDONLY)) == -1)
		coderror('O');
	ret = 1;
	tab = NULL;
	while (ret != 0)
	{
		ret = get_next_line(fd, &str);
		if (ret == -1)
			coderror('G');
		tab = tabreal(tab, str, (*len)++);
		if (str)
			ft_strclr(str);
	}
	if ((close(fd)) == -1)
		coderror('C');
	ft_strdel(&str);
	return (tab);
}

void	initdim(t_ix *dim)
{
	dim->xmin = 2147483647;
	dim->xmax = -2147483648;
	dim->ymin = 2147483647;
	dim->ymax = -2147483648;
	dim->zmin = 2147483647;
	dim->zmax = -2147483648;
}

t_coor	**stockmap(char *param, t_ix *dim)
{
	int		i;
	int		j;
	int		len;
	char	**tab;
	t_coor	**map;

	len = 0;
	if (!(tab = getnext(param, &len)))
		coderror('N');
	if (!(map = (t_coor **)malloc(sizeof(t_coor *) * (len + 1))))
		coderror('M');
	i = 0;
	j = 0;
	initdim(dim);
	while (i < len)
	{
		if (ft_strlen(tab[i]))
		{
			map[j] = getnbr(tab[i], j, dim);
			j++;
		}
		i++;
	}
	map[j] = NULL;
	return (map = putcolor(map, dim));
}
