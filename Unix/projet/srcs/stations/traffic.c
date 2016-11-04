/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traffic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 20:47:14 by dle-blon          #+#    #+#             */
/*   Updated: 2016/11/03 15:21:01 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <function.h>
#include <polling.h>


int main (int ac, char **av)
{
	int station_pid ;
	int delai_moyen;
	int delai_min;
	int delai_max;
	int station_index;
	time_t tick;
	time_t tock;

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

	srand (time(NULL));
	delai_moyen = rand() % (delai_max - delai_min + 1) + delai_min;
	
	while (TRUE)
	{
		time (&tick);
		do
		{
			time (&tock);
		} while (difftime(tock, tick) < delai_moyen);
		kill (station_pid, DATA_REQ_TX);
	}

	return 0;
}