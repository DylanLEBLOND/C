#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

/* b/ Le processus s'arrete à la reception du signal SIGUSR1 */
/* c/ Le processus est stoppe à la reception du signal SIGSTOP et il reprend à la reception de SIGCONT */

int		main (int ac, char **av)
{
	(void)ac;
	(void)av;

	printf ("attente de signaux\n");
	pause ();
	
	return 0;
}
