/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traffic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 20:47:14 by dle-blon          #+#    #+#             */
/*   Updated: 2016/09/30 15:21:01 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <function.h>

int station_index;
int station_pid;
int delai_min;
int delai_max;

void receive_data_signal (int signal)
{
	//TEMP
	(void)signal;
}

int main (int ac, char **av)
{
	int i;

	if (ac != 5)
		basic_error ("invalid parameters numbers trafic\n");

	station_index = atoi (av[1]);
	if (station_index < 0)
		basic_error ("invalid polling number\n");

	station_pid = atoi (av[2]);
	if (station_pid < 0)
		basic_error ("invalid polling delai\n");

	delai_min = atoi (av[3]);
	if (delai_min < 0)
		basic_error ("invalid secondary station number\n");

	delai_max = atoi (av[4]);
	if (delai_max < 0)
		basic_error ("invalid secondary station number\n");

	if (delai_max < delai_min)
		basic_error ("delai max < delai min\n");

//	signal (POLL_RX, &(receive_data_signal));

	for (i = 0; i< 60; i++)
	{
		printf ("trafic i %d pid_Sti %d delai_min_requete %d delai_max_requete %d\n", station_index, station_pid, delai_min, delai_max);
		sleep (1);
	}

	return 0;
}
