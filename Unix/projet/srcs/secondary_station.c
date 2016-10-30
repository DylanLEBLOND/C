/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_station.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 20:47:14 by dle-blon          #+#    #+#             */
/*   Updated: 2016/09/30 15:16:37 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <function.h>

int station_nb;
int pid;

void receive_request_signal (int signal)
{
	//TEMP
	(void)signal;
}

int main (int ac, char **av)
{
	int i;

	if (ac != 3)
		basic_error ("invalid parameters numbers secondaire\n");

	station_nb = atoi (av[1]);
	if (station_nb < 0)
		basic_error ("invalid station number\n");

	pid = atoi (av[2]);
	if (pid < 0)
		basic_error ("invalid pid\n");

//	signal (POLL_RX, &(receive_request_signal));

	for (i = 0; i < 60; i++)
	{
		printf ("secondaire numero_station %d pid_primaire %d\n", station_nb, pid);
		sleep (1);
	}

	return 0;
}
