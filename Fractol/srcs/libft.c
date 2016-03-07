/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 20:12:27 by dle-blon          #+#    #+#             */
/*   Updated: 2016/03/07 21:41:18 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_putendl(char const *s)
{
	int		i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
			write(1, &s[i++], 1);
		write(1, "\n", 1);
	}
}

int			ft_strcmp(const char *str1, const char *str2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str1[i] && str2[j] && str1[i] == str2[j])
	{
		i++;
		j++;
	}
	if (str1[i] == 0 && str2[j] == 0)
		return (0);
	else if (str1[i] == 0 && str2[j])
		return (-1);
	else if (str2[j] == 0 && str1[i])
		return (1);
	else if (str1[i] < str2[j])
		return (-1);
	else
		return (1);
}

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*tmp_d;
	char	*tmp_s;

	tmp_s = (char*)src;
	tmp_d = (char*)dest;
	while (n)
	{
		*tmp_d = *tmp_s;
		tmp_s++;
		tmp_d++;
		n--;
	}
	return (dest);
}

void		mlx_put_pixel_to_img(t_mlx *map, int x, int y, int color)
{
	ft_memcpy(&map->img[(x * 4) + (y * map->size)], &color, (sizeof(size_t)));
}

void		putimg(t_mlx *map)
{
	t_coor	*frc;

	if (!(ft_strcmp(map->name, "Mand")))
		frc = mandel(540, 600, map->z, map->var);
	else if (!(ft_strcmp(map->name, "Jul")))
		frc = julie(540, 600, map->z, map->var);
	else if (!(ft_strcmp(map->name, "Burn")))
		frc = burning(700, 600, map->z, map->var);
	else if (!(ft_strcmp(map->name, "Dou")))
		frc = doua(540, 600, map->z, map->var);
	else
		frc = NULL;
	if (!frc)
		coderror('F');
	putfrac(map, frc);
	mlx_put_image_to_window(map->mlx, map->win, map->new, 0, 0);
}
