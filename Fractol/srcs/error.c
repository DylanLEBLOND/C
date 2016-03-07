/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 15:05:17 by dle-blon          #+#    #+#             */
/*   Updated: 2015/03/14 19:23:46 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		coderror(char c)
{
	if (c == 'O')
		perror("open ");
	else if (c == 'm')
		perror("minilibx ");
	else if (c == 'C')
		perror("close ");
	else if (c == 'M')
		perror("malloc ");
	exit(0);
}

char		*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void		putfrac(t_mlx *map, t_coor *mdl)
{
	int		i;
	int		c;

	i = 0;
	c = 1;
	while (c)
	{
		mlx_put_pixel_to_img(map, mdl[i].x, mdl[i].y, mdl[i].c);
		if (mdl[i].et == 'F')
			c = 0;
		i++;
	}
}

int			color(char *str)
{
	if (!ft_strcmp(str, "1"))
		return (167116810);
	if (!ft_strcmp(str, "2"))
		return (655360000);
	if (!(ft_strcmp(str, "3")))
		return (10000);
	return (167769610);
}
