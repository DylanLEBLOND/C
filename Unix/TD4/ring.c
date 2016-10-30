#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* b/ Il faudrait stocker le pid du pere et envoyer au pere le signal */

void    ignore_user_signal (int sig)
{
	(void)sig;
}

int		main (int ac, char **av)
{
	int i;
	pid_t son_pid;
	pid_t father_pid;
	int processus_count;
	int sequence_count;
	struct sigaction action;

	if (ac != 3)
	{
		printf ("Invalid argument number\n");
		exit (EXIT_FAILURE);
	}

	processus_count = atoi (av[1]);
	if (processus_count < 0)
	{
		printf ("Invalid proccessus count\n");
		exit (EXIT_FAILURE);
	}

	sequence_count = atoi (av[2]);
	if (sequence_count < 0)
	{
		printf ("Invalid sequence count\n");
		exit (EXIT_FAILURE);
	}

	printf ("processus count = %d | sequence count %d\n", processus_count, sequence_count);

	pid = 0;
	action.sa_handler = 10;
	i = 0;
	while (i < processus_count)
	{
		pid = fork ();
		if (pid < 0)
		{
			perror ("fork failed:");
			exit (EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			break;
		}
		else
		{
			pid = 0;
			i++;
		}
	}

	printf ("Im the processus %d and my son is the processus %d\n", getpid(), pid);
	i = 0;
	while (i < sequence_count)
	{
		if (pid != 0)
			kill (pid, 10);
		sigaction (10, );
		pause ();
		i++;
	}

	return 0;
}
