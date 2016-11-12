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
char *filename;
char message[40];
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
			sprintf (message, "%sSt%d %s Data_Req_Rx %d\n", tab_st, station_nb, string_idle, nb_data_req_rx);
			print_message (message, filename);
			state = W_POLL;
			sprintf (message, "%sSt%d %s Attente\n", tab_st, station_nb, string_w_poll);
			break;
		case W_POLL:
			sprintf (message, "%sSt%d %s Data_Req_Rx %d\n", tab_st, station_nb, string_w_poll, nb_data_req_rx);
			print_message (message, filename);
			break;
		case SD_DATA:
			sprintf (message, "%sSt%d %s Data_Req_Rx %d\n", tab_st, station_nb, string_sd_data, nb_data_req_rx);
			print_message (message, filename);
			break;
		case W_ACK:
			sprintf (message, "%sSt%d %s Data_Req_Rx %d\n", tab_st, station_nb, string_w_ack, nb_data_req_rx);
			print_message (message, filename);
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
				sprintf (message, "%sSt%d %s Poll_Rx\n", tab_st, station_nb, string_w_poll);
				print_message (message, filename);
				kill (pid_primaire, DATA_TX);
				state = SD_DATA;
				sprintf (message, "%sSt%d %s\n", tab_st, station_nb, string_sd_data);
				print_message (message, filename);
				state = ACK_RX;
				sprintf (message, "%sSt%d %s\n", tab_st, station_nb, string_w_ack);
				print_message (message, filename);
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
			sprintf (message, "%sSt%d %s Ack_Rx %d\n", tab_st, station_nb, string_sd_data, nb_data_req_rx);
			print_message (message, filename);
			if (nb_data_req_rx > 0)
			{
				state = W_POLL;
				sprintf (message, "%sSt%d %s Attente\n", tab_st, station_nb, string_w_poll);
				print_message (message, filename);
			}
			else
			{
				state = IDLE;
				sprintf (message, "%sSt%d %s\n", tab_st, station_nb, string_idle);
				print_message (message, filename);
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
			sprintf (message, "%sSt%d %s Data_Rx\n", tab_st, station_nb, string_idle);
			print_message (message, filename);
			break;
		case W_POLL:
			sprintf (message, "%sSt%d %s Data_Rx\n", tab_st, station_nb, string_w_poll);
			print_message (message, filename);
			break;
		default:		/* should never occur */
			break;
	}
}

int main (int ac, char **av)
{
	int length;
	struct sigaction data_req_action;
	struct sigaction poll_action;
	struct sigaction ack_action;
	struct sigaction data_action;

	if (ac < 3 || ac > 4)
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

	filename = NULL;
	if (ac == 4)
	{
		length = strlen (av[ac - 1]) + 5;
		filename = (char *)malloc(sizeof(char) * length);
		if (filename == NULL)
			fatal_error ("strdup failed\n");

		filename = strcpy (filename, av[ac - 1]);
		if (filename == NULL)
			fatal_error ("strcpy failed\n");

		filename = strcat (filename, "_st");
		if (filename == NULL)
			fatal_error ("strcat failed\n");

		filename = strcat (filename, ft_itoa (station_nb));
		if (filename == NULL)
			fatal_error ("itoa failed\n");

		filename[length - 1] = '\0';
	}

	sprintf (message, "%sSt%d %s\n", tab_st, station_nb, string_idle);
	print_message (message, filename);

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
