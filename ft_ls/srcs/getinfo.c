/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:45:11 by dle-blon          #+#    #+#             */
/*   Updated: 2016/03/22 18:46:13 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_init(t_data *data, int max)
{
	data->nb = 0;
	data->nbf = 0;
	if (max)
	{
		if (!(data->names = (char **)malloc(sizeof(char *) * max)))
			ft_error("Malloc: ", 1);
		data->names[max - 1] = NULL;
	}
	else
		data->names = NULL;
	data->files = NULL;
	data->option = NULL;
}

void	ft_getnames(t_data *data, char *name)
{
	data->names[data->nb] = ft_strdup(name);
	if (!data->names[data->nb])
		ft_error("Malloc", 1);
	data->nb++;
}

void	ft_getoptions(t_data *data, char *name)
{
	int		i;
	char	c;
	char	*tmp;

	if (!data->option)
		data->option = ft_strdup(++name);
	else
	{
		i = 1;
		while ((c = name[i]))
		{
			if (!ft_strchr(data->option, c))
			{
				tmp = ft_strjoin(data->option, &c);
				//if (data->option)
				//free(data->option);
				data->option = ft_strdup(tmp);
			}
			++i;
		}
		//if (tmp)
		//free(tmp);
	}
	if (!data->option)
		ft_error("Malloc", 1);
}
