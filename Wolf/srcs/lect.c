/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 19:48:05 by dle-blon          #+#    #+#             */
/*   Updated: 2015/06/04 15:36:51 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		createfd(void)
{
	int		fd;

	fd = open("./maps/map01", O_RDONLY);
	if (fd == -1)
		coderror('O');
	return (fd);
}

void	remp2(char *str, t_need *greed, int k)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < BUFF_SIZE)
	{
		while (str[i] == ' ')
			i++;
		if (i < BUFF_SIZE && str[i] != ' ')
			greed->map[k][j++] = ft_atoi(str + i);
		while (i < BUFF_SIZE && str[i] != ' ')
			i++;
	}
}

void	remp(int fd, t_need *greed)
{
	int		k;
	char	*str;

	if (!(greed->map = (int **)malloc(sizeof(int *) * WIDTH)))
		coderror('M');
	if (!(str = ft_strnew(BUFF_SIZE)))
		coderror('M');
	k = 0;
	while (read(fd, str, BUFF_SIZE) > 0)
	{
		if (!(greed->map[k] = (int *)malloc(sizeof(int) * HEIGHT)))
			coderror('M');
		remp2(str, greed, k++);
		if (str)
			free(str);
		if (!(str = ft_strnew(BUFF_SIZE)) && k < HEIGHT)
			coderror('M');
	}
	if (str)
		free(str);
}
