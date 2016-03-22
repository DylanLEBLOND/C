#include "ft_ls.h"

void    ft_error(char *message, int end)
{
    perror(message);
    if (end)
        exit(0);
}