/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_station.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 20:47:14 by dle-blon          #+#    #+#             */
/*   Updated: 2016/11/03 15:16:37 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <function.h>
#include <polling.h>

int pid_primaire;
int station_nb;
char *tab_st;
int nb_data_req_rx = 0;
int state = IDLE;

/*
** signal in: DATA_REQ_RX
*/
void emitting_data_request_signal (int signum)
{
	(void)signum;
	
	nb_data_req_rx++;
	kill (-2, DATA_REQ_TX);
	switch (state)
	{
		case IDLE:
			printf ("%sSt%d %s Data_Req_Rx %d\n", tab_st, station_nb, string_idle, nb_data_req_rx);
			state = W_POLL;
			printf ("%sSt%d %s Attente\n", tab_st, station_nb, string_w_poll);
			break;
		case W_POLL:
			printf ("%sSt%d %s Data_Req_Rx %d\n", tab_st, station_nb, string_w_poll, nb_data_req_rx);
			break;
		case SD_DATA:
			printf ("%sSt%d %s Data_Req_Rx %d\n", tab_st, station_nb, string_sd_data, nb_data_req_rx);
			break;
		case W_ACK:
			printf ("%sSt%d %s Data_Req_Rx %d\n", tab_st, station_nb, string_w_ack, nb_data_req_rx);
			break;
		default:		/* should never occur */
			break;
	}
}

/*
** signal in: POLL_RX
*/
void emitting_data_signal (int signum)
{
	(void)signum;
	
	switch (state)
	{
		case W_POLL:
			if (nb_data_req_rx > 0)
			{
				printf ("%sSt%d %s Poll_Rx\n", tab_st, station_nb, string_w_poll);
				kill (pid_primaire, DATA_TX);
				state = SD_DATA;
				printf ("%sSt%d %s\n", tab_st, station_nb, string_sd_data);
				state = ACK_RX;
				printf ("%sSt%d %s\n", tab_st, station_nb, string_w_ack);
			}
		default:
			break;
	}
}

/*
** signal in: ACK_RX
*/
void acknoledge_signal (int signum)
{
	(void)signum;
	
	switch (state)
	{
		case ACK_RX:
			nb_data_req_rx--;
			printf ("%sSt%d %s Ack_Rx %d\n", tab_st, station_nb, string_sd_data, nb_data_req_rx);
			if (nb_data_req_rx > 0)
			{
				state = W_POLL;
				printf ("%sSt%d %s Attente\n", tab_st, station_nb, string_w_poll);
			}
			else
			{
				state = IDLE;
				printf ("%sSt%d %s\n", tab_st, station_nb, string_idle);
			}
			break;
		default:
			break;
	}
}

/*
** signal in: DATA_RX
*/
void receive_data_signal (int signum)
{
	(void)signum;

	switch (state)
	{
		case IDLE:
			printf ("%sSt%d %s Data_Rx\n", tab_st, station_nb, string_idle);
			break;
		case W_POLL:
			printf ("%sSt%d %s Data_Rx\n", tab_st, station_nb, string_w_poll);
			break;
		default:		/* should never occur */
			break;
	}
}

int main (int ac, char **av)
{
	struct sigaction data_req_action;
	struct sigaction poll_action;
	struct sigaction ack_action;
	struct sigaction data_action;

	if (ac != 3)
		basic_error ("invalid parameters numbers secondaire\n");

	station_nb = atoi (av[1]);
	if (station_nb < 0)
		basic_error ("invalid station number\n");

	pid_primaire = atoi (av[2]);
	if (pid_primaire < 0)
		basic_error ("invalid pid primaire\n");

	tab_st = (char *)malloc(sizeof(char) * (3 * station_nb + 1));
	if (tab_st == NULL)
		fatal_error ("malloc failed\n");
	
	tab_st = memset (tab_st, 0, sizeof(char) * (3 * station_nb + 1));
	if (tab_st == NULL)
		fatal_error ("memset failed\n");
	ft_fill_tab (tab_st, 3 * station_nb + 1);

	printf ("%sSt%d %s\n", tab_st, station_nb, string_idle);
	
	data_req_action.sa_handler = emitting_data_request_signal;
	data_req_action.sa_flags = 0;
	sigaction (DATA_REQ_RX, &data_req_action, NULL);

	poll_action.sa_handler = emitting_data_signal;
	poll_action.sa_flags = 0;
	sigaction (POLL_RX, &poll_action, NULL);

	ack_action.sa_handler = acknoledge_signal;
	ack_action.sa_flags = 0;
	sigaction (ACK_RX, &ack_action, NULL);

	data_action.sa_handler = receive_data_signal;
	data_action.sa_flags = 0;
	sigaction (DATA_RX, &data_action, NULL);

	while (TRUE)
	{
		pause();
	}
	return 0;
}
