/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_secondary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 20:47:14 by dle-blon          #+#    #+#             */
/*   Updated: 2016/09/30 15:22:59 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <function.h>

void ft_secondary_management (t_parameters *parameters, int station_number)
{
	pid_t pid_primary;
	pid_t pid_traffic;
	char **secondaty_parameters;

	pid_traffic = fork ();
	if (pid_traffic < 0)
		fatal_error ("fork failed");
	if (pid_traffic == 0)
		ft_traffic_management (parameters, station_number);

	pid_primary = getppid ();

	secondaty_parameters = (char **)malloc(sizeof (char *) * 4);
	if (secondaty_parameters == NULL)
		fatal_error ("malloc failed");

	secondaty_parameters[0] = strdup (parameters->secondaire_str);
	secondaty_parameters[1] = ft_itoa (station_number);
	secondaty_parameters[2] = ft_itoa (pid_primary);
	secondaty_parameters[3] = NULL;

	execv (parameters->secondaire_str, secondaty_parameters);
	fatal_error ("execv failed");
}
