#include "ft_ls.h"
#include <stdio.h>
void    ft_order(char **tab, int len, int ord)
{
    int     i;
    int     j;
    int     cd;
    char    *tmp;

    i = -1;
    while (tab && tab[++i])
    {
        j = len;
        while (--j > i)
        {
            cd = ord ?
            ft_strcmp(tab[i], tab[j]) > 0 : ft_strcmp(tab[i], tab[j]) < 0;
            if (cd)
            {
                tmp = ft_strdup(tab[i]);
                free(tab[i]);
                tab[i] = ft_strdup(tab[j]);
                free(tab[j]);
                tab[j] = ft_strdup(tmp);
                free(tmp);
            }
        }
    }
}