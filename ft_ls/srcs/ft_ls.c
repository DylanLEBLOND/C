/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:40:46 by dle-blon          #+#    #+#             */
/*   Updated: 2016/04/11 14:39:54 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info	ft_getcontain(t_info *info, t_dir *buff, int nb, char *name)
{
	int		i;
	char	*path;
	t_info	new;
	t_stat	tmp;
	

	if (!(new.names = (char **)malloc(sizeof(char *) * (nb + 2))))
		ft_error("Malloc", 1);
	if (!(new.container = (t_stat *)malloc(sizeof(t_stat) * (nb + 1))))
		ft_error("Malloc", 1);
	if (!(path = ft_strjoin(ft_strjoin(name, "/"), buff->d_name)))
		ft_error("Malloc", 1);
	i = -1;
	while (++i < nb - 1)
	{
		new.names[i] = info->names[i];
		new.container[i] = info->container[i];
	}
	new.names[i] = ft_strdup(buff->d_name);
	new.names[i + 1] = NULL;
	if (stat(path, &tmp) == -1)
		ft_error("Stat", 0);
	new.container[i] = tmp;
	return (new);
}

void	ft_write(char **name, t_info info, int dir)
{
	int i;
	int j;
	int bol;

	i = 0;
	j = 0;
	while (info.names[i])
	{
		if (dir)
			bol = S_ISDIR(info.container[i].st_mode);
		else
			bol = !S_ISDIR(info.container[i].st_mode);
		if (bol)
			name[j++] = ft_strdup(info.names[i]);
		++i;
	}
}

void	ft_config(t_data *data, t_info info)
{
	int i;

	if (!info.names)
		return ;
	i = 0;
	while (info.names[i])
	{
		if (S_ISDIR(info.container[i].st_mode))
			++data->nb;
		else
			++data->nbf;
		++i;
	}
	if (data->nb && !(data->names = (char**)malloc(sizeof(char*) * ++data->nb)))
		return ;
	if (data->nb)
		data->names[--data->nb] = NULL;
	if (data->nbf
		&& !(data->files = (char**)malloc(sizeof(char*) * ++data->nbf)))
		return ;
	if (data->nbf)
		data->files[--data->nbf] = NULL;
	ft_write(data->names, info, 1);
	ft_write(data->files, info, 0);
	return ;
}

void	ft_loopdir(char *name, char *option)
{
	int		i;
	t_data	tmp;
	t_dir	*buff;
	t_info	info;
	DIR		*dir;

	if (!(dir = opendir(name)))
		ft_error("Opendir", 0);
	if (!dir)
		return ;
	i = 1;
	ft_init(&tmp, 0);
	while ((buff = readdir(dir)))
	{
		info = ft_getcontain(&info, buff, i, name);
		++i;
	}
	ft_config(&tmp, info);
	ft_affall(tmp, option, name);
	ft_norme(name, tmp.names);
	if (ft_checkname(tmp.names) && option && ft_strchr(option, 'R'))
		ft_ls(tmp.names, option, tmp.nb, 0);
	if (closedir(dir) == -1)
		ft_error("Closedir", 0);
	//ft_freeall(name, tmp, container);
}

void	ft_ls(char **names, char *option, int nb, int start)
{
	int i;

	i = 0;
	while (i < nb)
	{
		if (start)
			ft_loopdir(names[i], option);
		if (!start && ft_checkcurrent(names[i]))
			ft_loopdir(names[i], option);
		++i;
	}
}
