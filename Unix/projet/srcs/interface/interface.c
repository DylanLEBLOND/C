/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 20:47:14 by dle-blon          #+#    #+#             */
/*   Updated: 2016/11/03 15:23:59 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <function.h>

void ft_fill_parameters (t_parameters *parameters, int ac, char **av)
{
	parameters->primaire_str = strdup (av[1]);
	if (parameters->primaire_str == NULL)
		fatal_error ("strdup failed");

	parameters->secondaire_str = strdup (av[2]);
	if (parameters->secondaire_str == NULL)
		fatal_error ("strdup failed");

	parameters->trafic_str = strdup (av[3]);
	if (parameters->trafic_str == NULL)
		fatal_error ("strdup failed");

	parameters->station_count = atoi (av[4]);
	if (parameters->station_count < 1 || parameters->station_count > 50)
		basic_error ("station count invalid\n");

	parameters->polling_count = atoi (av[5]);
	if (parameters->polling_count < 0)
		basic_error ("polling count invalid\n");

	parameters->polling_delay = atoi (av[6]);
	if (parameters->polling_delay < 0)
		basic_error ("polling delay invalid\n");

	parameters->delay_min = atoi (av[7]);
	if (parameters->delay_min < 0)
		basic_error ("delay min request invalid\n");

	parameters->delay_max = atoi (av[8]);
	if (parameters->delay_max < 0)
		basic_error ("delay max request invalid\n");

	if (ac == 10)
	{
		parameters->file_name = strdup (av[9]);
		if (parameters->file_name == NULL)
			fatal_error ("strdup failed");
	}
}

int main (int ac, char **av)
{
	t_parameters parameters;
	pid_t pid_primary;

	if (ac != 9 && ac != 10)
		basic_error ("invalid parameters numbers\n");

	if (strcmp (av[1], "primaire") != 0)
		basic_error ("first parameter invalid\n");

	if (strcmp (av[2], "secondaire") != 0)
		basic_error ("second parameter invalid\n");

	if (strcmp (av[3], "trafic") != 0)
		basic_error ("third parameter invalid\n");

	T_PARAMETERS_STRUCT_CLEAR (parameters);
	ft_fill_parameters (&parameters, ac, av);

	pid_primary = fork ();
	if (pid_primary == 0)
		ft_primary_management (&parameters);

	waitpid (pid_primary, NULL, 0);

	return 0;
}
