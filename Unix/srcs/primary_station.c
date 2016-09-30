/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary_station.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 20:47:14 by dle-blon          #+#    #+#             */
/*   Updated: 2016/09/30 15:27:09 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <function.h>

void send_signal (int polling_count, int delai_polling, int station_count, int *pids)
{
	//TEMP
	(void)polling_count;
	(void)delai_polling;
	(void)station_count;
	(void)pids;
}

int main (int ac, char **av)
{
	int polling_count;
	int delai_polling;
	int station_count;
	int *pids;
	int i;
	int j;

	if (ac < 5 || ac > 9)
		basic_error ("invalid parameters numbers primaire\n");

	polling_count = atoi (av[0]);
	if (polling_count < 0)
		basic_error ("invalid polling number\n");

	delai_polling = atoi (av[1]);
	if (delai_polling < 0)
		basic_error ("invalid polling delai\n");

	station_count = atoi (av[2]);
	if (station_count < 1 || station_count > 5)
		basic_error ("invalid secondary station count\n");

	pids = (int *)malloc(sizeof(int) * station_count);
	if (pids == NULL)
		fatal_error ("malloc failed\n");

	for (i = 0; i < station_count; i++)
	{
		pids[i] = atoi (av[2 + i]);
		if (pids[i] < 0)
			basic_error ("invalid secondary station pid\n");
	}

	send_signal (polling_count, delai_polling, station_count, pids);

	for (i = 0; i < 60; i++)
	{
		printf ("primaire nb_polling %d delai_polling %d n %d ", polling_count, delai_polling, station_count);
		for (j = 0; j < station_count; j++)
		{
			if (j < station_count - 1)
				printf ("pid_st%d %d ", j, pids[j]);
			else
				printf ("pid_st%d %d\n", j, pids[j]);
		}
		sleep (1);
	}

	return 0;
}
