/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 17:27:04 by dle-blon          #+#    #+#             */
/*   Updated: 2015/11/01 20:09:24 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_backline(const char *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '\n' && str[i + 1] != '\n')
			|| (str[i] == '\n' && str[i + 1] != '\0'))
			len++;
		if ((str[i] == '\n' && str[i + 1] == '\n')
			|| (str[i] == '\n' && str[i + 1] == '\0'))
			return (len);
		i++;
	}
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

char	*ft_readfile(void)
{
	int		fd;
	char	*buff;
	char	*str;

	str = NULL;
	fd = 0;
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

char	**ft_organize(void)
{
	int		i;
	int		nbl;
	char	*strfile;
	char	**file;

	if (!(strfile = ft_readfile()))
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
	return (file);
}
