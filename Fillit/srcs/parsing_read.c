/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 17:27:04 by dle-blon          #+#    #+#             */
/*   Updated: 2016/01/27 21:21:16 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_backline(const char *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\n' && str[i] != '.' && str[i] != '#')
			ft_error('T');
		if (str[i] == '\n')
			len++;
		if (i > 0 && str[i] != '\0' && str[i - 1] == '\n'
			&& str[i] == '\n' && str[i + 1] == '\n')
			ft_error('S');
		i++;
	}
	if (len % 5 != 4)
		ft_error('S');
	return (len);
}

char	*ft_concat(char *str, char *buff)
{
	char	*newstr;

	newstr = NULL;
	if (!str)
		newstr = ft_strdup(buff);
	else
	{
		newstr = ft_strjoin(str, buff);
		if (str)
			free(str);
	}
	return (newstr);
}

char	*ft_readfile(char *name)
{
	int		fd;
	char	*buff;
	char	*str;

	str = NULL;
	if ((fd = open(name, O_RDONLY)) < 0)
		ft_error('O');
	if (!(buff = ft_strnew(BUFF_SIZE)))
		ft_error('M');
	while (read(fd, buff, BUFF_SIZE) > 0)
	{
		if (!(str = ft_concat(str, buff)))
			ft_error('M');
		if (buff)
			free(buff);
		if (!(buff = ft_strnew(BUFF_SIZE)))
			ft_error('M');
	}
	if (!str)
		ft_error('V');
	return (str);
}

char	*ft_getline(const char *str, int pos)
{
	int		i;
	int		nb;
	int		start;
	int		first;
	char	*newstr;

	i = 0;
	nb = 0;
	start = 0;
	first = 0;
	while (str[i] && nb <= pos)
	{
		if (str[i] == '\n')
			nb++;
		if (nb == pos && !first && i != 0)
			start = i + 1;
		if (nb == pos && !first)
			first++;
		i++;
	}
	if (!(newstr = ft_strsub(str + start, 0, i - (start + 1))))
		ft_error('M');
	return (newstr);
}

char	**ft_organize(char *name)
{
	int		i;
	int		nbl;
	char	*strfile;
	char	**file;

	if (!(strfile = ft_readfile(name)))
		ft_error('M');
	nbl = ft_backline(strfile);
	if (!(file = (char **)malloc(sizeof(char *) * (nbl + 1))))
		ft_error('M');
	i = 0;
	while (i < nbl)
	{
		file[i] = ft_getline(strfile, i);
		i++;
	}
	file[i] = NULL;
	ft_check(file);
	return (file);
}
