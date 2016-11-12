/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_primary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 20:47:14 by dle-blon          #+#    #+#             */
/*   Updated: 2016/09/30 15:22:46 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <function.h>

void ft_primary_management (t_parameters *parameters)
{
	pid_t *secondary_pids;
	int nb_parameters;
	char **primary_parameters;
	int i;

	secondary_pids = (pid_t *)malloc(sizeof (pid_t) * (parameters->station_count));
	if (secondary_pids == NULL)
		fatal_error ("malloc failed");

	for (i = 0; i < parameters->station_count; i++)
	{
		secondary_pids[i] = (pid_t)fork ();
		if (secondary_pids[i] < 0)
			fatal_error ("fork failed");
		if (secondary_pids[i] == 0)
			ft_secondary_management (parameters, i + 1);
	}

	nb_parameters = 5 + parameters->station_count;
	if (parameters->file_name != NULL)
		nb_parameters++;

	primary_parameters = (char **)malloc(sizeof (char *) * nb_parameters);
	if (primary_parameters == NULL)
		fatal_error ("malloc failed");

	primary_parameters[0] = strdup (parameters->primaire_str);
	primary_parameters[1] = ft_itoa (parameters->polling_count);
	primary_parameters[2] = ft_itoa (parameters->polling_delay);
	primary_parameters[3] = ft_itoa (parameters->station_count);
	for (i = 0; i < parameters->station_count; i++)
	{
		primary_parameters[i + 4] = ft_itoa (secondary_pids[i]);
	}
	if (parameters->file_name != NULL)
		primary_parameters[i + 4] = strdup (parameters->file_name);
	primary_parameters[nb_parameters - 1] = NULL;

	execv (parameters->primaire_str, primary_parameters);
	fatal_error ("execv failed");
}
