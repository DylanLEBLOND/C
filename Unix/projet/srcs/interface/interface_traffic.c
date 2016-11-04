/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_traffic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 20:47:14 by dle-blon          #+#    #+#             */
/*   Updated: 2016/09/30 15:22:59 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <function.h>

void ft_traffic_management (t_parameters *parameters, int station_number)
{
	pid_t pid_secondary;
	char **traffic_parameters;

	pid_secondary = getppid ();

	traffic_parameters = (char **)malloc(sizeof (char *) * 6);
	if (traffic_parameters == NULL)
		fatal_error ("malloc failed");

	traffic_parameters[0] = strdup (parameters->trafic_str);
	traffic_parameters[1] = ft_itoa (station_number);
	traffic_parameters[2] = ft_itoa (pid_secondary);
	traffic_parameters[3] = ft_itoa (parameters->delay_min);
	traffic_parameters[4] = ft_itoa (parameters->delay_max);
	traffic_parameters[5] = NULL;

	execv (parameters->trafic_str, traffic_parameters);
	fatal_error ("execv failed");
}
