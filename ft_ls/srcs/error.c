/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:40:27 by dle-blon          #+#    #+#             */
/*   Updated: 2016/10/28 12:58:35 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <libft.h>

char	**ft_fusion(t_data data)
{
	int		i;
	int		j;
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * (data.nb + data.nbf + 1))))
		return (NULL);
	i = -1;
	while (++i < data.nb)
		tab[i] = ft_strdup(data.names[i]);
	j = 0;
	while (j < data.nbf)
		tab[i++] = ft_strdup(data.files[j++]);
	tab[i] = NULL;
	return (tab);
}

void	ft_free(char **t1, char **t2)
{
	int i;

	if (t1 != NULL)
	{
		i = -1;
		while (t1[++i] != NULL)
			if (t1[i] != NULL)
				free(t1[i]);
		if (t1 != NULL)
			free(t1);
	}
	if (t2 != NULL)
	{
		i = -1;
		while (t2[++i] != NULL)
			if (t2[i] != NULL)
				free(t2[i]);
		if (t2 != NULL)
			free(t2);
	}
}

void	ft_error(char *message, int end)
{
	perror(message);
	if (end)
		exit(0);
}
