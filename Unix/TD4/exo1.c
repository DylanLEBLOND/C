#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <stdio.h>

/* b/ Le processus destinataire s'il peut interpreter le signal envoye s'interonmp pour pouvoir le traiter */

int		main (int ac, char **av)
{
	pid_t pid;
	int sig;
	int result;

	(void)ac;
	(void)av;
		
	pid = 0;
	sig = 0;
	result = kill(pid, sig);
	if (result < 0)
	{
		perror ("kill failed:");
		exit (EXIT_FAILURE);
	}
	
	return 0;
}
