/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 17:56:02 by abary             #+#    #+#             */
/*   Updated: 2016/02/25 22:13:06 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static	char		*ft_get_line(char *next, char *line)
{
	int		nbr;
	char	*str;

	if (ft_strchr(next, '\n') != 0)
		nbr = ft_strlen(next) - ft_strlen(ft_strchr(next, '\n'));
	else
		nbr = ft_strlen(next);
	str = ft_strndup(next, nbr);
	line = ft_strdup(str);
	free(str);
	str = NULL;
	return (line);
}

t_list				*ft_search_fd(t_list **begin, int fd)
{
	t_list	*next;

	next = *begin;
	if (!next)
	{
		next = ft_lstnew("\0", 1);
		next->content_size = fd;
		ft_lstadd(begin, next);
		return (next);
	}
	else
	{
		while (next)
		{
			if (next->content_size == (size_t)fd)
				return (next);
			next = next->next;
		}
		next = ft_lstnew("\0", 1);
		next->content_size = fd;
		ft_lstadd(begin, next);
		return (next);
	}
}

char				*ft_skype_n(char *next)
{
	while (*next != '\n' && *next)
		++next;
	++next;
	return (next);
}

static char			*ft_passkip(char *next, char *buf, int nbr)
{
	char *d;

	d = next;
	next = ft_strnjoin(next, buf, nbr);
	free(d);
	return (next);
}

int					get_next_line(int const fd, char **line)
{
	static t_list	*next = NULL;
	t_list			*begin;
	char			buf[BUFF_SIZE];
	int				nbr;
	char			*d;

	d = NULL;
	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (next)
		begin = next;
	else
		begin = NULL;
	next = ft_search_fd(&begin, fd);
	while ((nbr = read(fd, buf, BUFF_SIZE)) > 0 && !(ft_strchr(buf, '\n')))
		next->content = ft_passkip((next->content), buf, nbr);
	next->content = ft_passkip((next->content), buf, nbr);
	*line = ft_get_line(next->content, *line);
	if (!*((char *)next->content) && (next = begin))
		return (0);
	d = next->content;
	next->content = ft_strdup(ft_skype_n(next->content));
	free(d);
	next = begin;
	return (1);
}
