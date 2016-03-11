#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

int     main(int ac, char **av)
{
    int i;
    DIR *dir;
    struct dirent *container;
    
    if (ac != 2)
        return (0);
    if ((dir = opendir(av[1])))
    {
        i = 0;
        while ((container = readdir(dir)))
            printf("name %d = %s\n", i++, container->d_name);
        if (closedir(dir) == -1)
            printf("Close Error\n");
    }
    else
        printf("Open Error\n");
    return (0);
}
