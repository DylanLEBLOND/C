# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <dirent.h>

typedef struct  dirent  t_dir;
typedef struct  stat    t_stat;

int main(void)
{
	DIR		*dir;
	t_dir	*buff;

	if (!(dir = opendir("srcs")))
	{
		printf ("FAILED 1\n");
		exit (0);
	}
	if (!dir)
	{
		printf ("FAILED 2\n");
		exit (0);
	}
	
	while ((buff = readdir(dir)))
	{
		printf ("dir name = %s\n", buff->d_name);
	}

    return (0);
}
