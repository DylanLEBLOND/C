/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:45:11 by dle-blon          #+#    #+#             */
/*   Updated: 2016/10/28 17:47:27 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <libft.h>

void	ft_init(t_data *data, int max)
{
	data->nb = 0;
	data->nbf = 0;
	if (max)
	{
		if (!(data->names = (char **)malloc(sizeof (char *) * max)))
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

	tmp = ft_remove_dash (name);
	if (tmp == NULL)
		;//Invalid Option
	if (!

	if (!data->option)
	{

}
