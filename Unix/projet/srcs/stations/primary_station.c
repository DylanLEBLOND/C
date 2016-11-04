/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary_station.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 20:47:14 by dle-blon          #+#    #+#             */
/*   Updated: 2016/11/03 15:27:09 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <function.h>
#include <polling.h>

int state;
time_t tick;
time_t tock;

void primary_signal (int signum)
{
	(void)signum;
	switch (state)
	{
		case W_REQ:
			state = BC_DATA;
			break;
		default:
			break;
	}
}

int main (int ac, char **av)
{
	struct sigaction new_action;
	int polling_count;
	int delai_polling;
	int station_count;
	int *pids;
	int i;
	int j;
	int k;

	if (ac < 5 || ac > 9)
		basic_error ("invalid parameters numbers primaire\n");

	polling_count = atoi (av[1]);
	if (polling_count < 0)
		basic_error ("invalid polling number\n");

	delai_polling = atoi (av[2]);
	if (delai_polling < 0)
		basic_error ("invalid polling delai\n");

	station_count = atoi (av[3]);
	if (station_count < 1 || station_count > 5)
		basic_error ("invalid secondary station count\n");

	pids = (int *)malloc(sizeof(int) * station_count);
	if (pids == NULL)
		fatal_error ("malloc failed\n");

	for (i = 0; i < station_count; i++)
	{
		pids[i] = atoi (av[4 + i]);
		if (pids[i] < 0)
			basic_error ("invalid secondary station pid\n");
	}

	new_action.sa_handler = primary_signal;
	new_action.sa_flags = 0;
	sigaction (DATA_RX, &new_action, NULL);
	
	for (i = 0; i < polling_count; i++)
	{
		for (j = 0; j < station_count; j++)
		{
			state = W_REQ;
			time (&tick);
			
			printf ("Prim %s St%d %ds\n", string_w_req, j + 1, delai_polling);
			kill (pids[j], POLL_TX);

			do
			{
				time (&tock);
			} while (difftime(tock, tick) < delai_polling);
			
			switch (state)
			{
				case W_REQ:
					printf ("Prim %s St%d No_Data\n", string_w_req, j + 1);
					break;
				case BC_DATA:
					printf ("Prim %s St%d\n", string_bc_data, j + 1);
					for (k = 0; k < station_count; k++)
					{
						if (k != j)
							kill (pids[k], DATA_TX);
					}
					kill (pids[j], ACK_TX);
					break;
				default:		/* should never occur */
					break;
			}
		}
	}
	return 0;
}
