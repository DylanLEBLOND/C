#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

void	ignore_user_signal (int sig)
{
	(void)sig;
}

int		main (int ac, char **av)
{
	(void)ac;
	(void)av;
	
	signal (10, &(ignore_user_signal));
	signal (11, &(ignore_user_signal));
	signal (12, &(ignore_user_signal));
	signal (16, &(ignore_user_signal));
	signal (17, &(ignore_user_signal));
	signal (22, &(ignore_user_signal));
	signal (30, &(ignore_user_signal));

	pause ();
	return 0;
}
