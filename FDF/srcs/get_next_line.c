/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:01:07 by dle-blon          #+#    #+#             */
/*   Updated: 2015/02/10 19:05:10 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_backslash(char *str)
{
	int		i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (-2);
	return (i);
}

static int	get_next_save(char **str, char **line)
{
	int		pos;
	char	*tmp;

	if (!(tmp = ft_strdup(*str)))
		return (-1);
	ft_strclr(*str);
	ft_strdel(str);
	if ((pos = ft_backslash(tmp)) == -1)
		return (-1);
	if (pos == -2)
	{
		*line = ft_strdup(tmp);
		ft_strclr(tmp);
		ft_strdel(&tmp);
		return (*line ? 0 : -1);
	}
	else
	{
		*line = ft_strsub(tmp, 0, pos);
		*str = ft_strsub(tmp, pos + 1, ft_strlen(tmp));
		ft_strclr(tmp);
		ft_strdel(&tmp);
		return ((*line && *str) ? 1 : -1);
	}
	return (-1);
}

static int	ft_justtest(char **line, char **str, char **buff, int pos)
{
	if (!(*line = ft_strjoin(*line, ft_strsub(*buff, 0, pos))))
		return (-1);
	if (!(*str = ft_strsub(*buff, pos + 1, BUFF_SIZE)))
		return (-1);
	ft_strclr(*buff);
	ft_strdel(buff);
	return (1);
}

static int	get_next_try(int const fd, char **str, char **line)
{
	int		chr;
	int		pos;
	char	*buff;

	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((chr = read(fd, buff, BUFF_SIZE)))
	{
		if (chr < 0 || (pos = ft_backslash(buff)) == -1)
			return (-1);
		if (pos == -2)
		{
			if (!(*line = ft_strjoin(*line, buff)))
				return (-1);
		}
		else
			return (ft_justtest(line, str, &buff, pos));
		ft_strclr(buff);
	}
	ft_strdel(&buff);
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char	*str;
	int			ret;

	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	ret = 0;
	if (*line)
		ft_strclr(*line);
	if (str)
		ret = get_next_save(&str, line);
	if (ret != 0)
		return (ret);
	else
		ret = get_next_try(fd, &str, line);
	if (ret == 0)
		ft_strclr(str);
	if (ret == 0)
		ft_strdel(&str);
	return (ret);
}
