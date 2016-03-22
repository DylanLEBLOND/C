#include "ft_ls.h"
 
void    ft_affinfo(t_data data)
{
    int i;

    ft_putstr("nb = ");
    ft_putnbr(data.nb);
    ft_putstr(" | options : ");
    ft_putstr(data.option);
    i = -1;
    ft_putstr("\nnames : ");
    while (++i < data.nb)
    {
        ft_putstr(data.names[i]);
        if (i < data.nb -1)
            ft_putstr(" | ");
        else
            ft_putendl("");
    }
}

void    ft_affblock(char *str, char *option)
{
    /*ft_putstr("[Bstart(str = <");
    ft_putstr(str);
    ft_putstr(">)");*/
    if (str && !option && str[0] != '.')
        ft_putstr(str);
    else if (str && option && !ft_strchr(option, 'a') && str[0] != '.')
        ft_putstr(str);
    else if (str && option && ft_strchr(option, 'a'))
        ft_putstr(str);
    //ft_putstr("Bend]");
}

void    ft_putspace(char **pre, char *next, char *option)
{
    if (!pre || !next)
        return ;
    *pre--;
    /*ft_putstr("[Sstart(pre = <");
    ft_putstr(*pre);
    ft_putstr("> | next = <");
    ft_putstr(next);
    ft_putstr(">)<");*/
    if (*pre && next && (!option || (option && !ft_strchr(option, 'a')))
        && *pre[0] != '.' && next[0] != '.')
        ft_putstr("  ");
    else if (*pre && next && option && ft_strchr(option, 'a'))
        ft_putstr("  ");
    *pre++;
    /*ft_putstr(">Send(pre = <");
    ft_putstr(*pre);
    ft_putstr(">)]");*/
}

void    ft_afftab(char **t1, char  **t2, char *option)
{
    int cond;
    int save;
    int start;

    start = 0;
    while (t1 && t2 && *t1 && *t2)
    {
        cond = option && ft_strchr(option, 'r') ? ft_strcmp(*t1, *t2) >= 0
                                                : ft_strcmp(*t1, *t2) <= 0;
        if (start++ != 0)
            ft_putspace(save ? t1 : t2, cond ? *t1 : *t2, option);
        ft_affblock(cond ? *t1++ : *t2++, option);
        save = cond;
    }
    if (start)
        ft_putspace(save ? t1 : t2, cond ? *t1 : *t2, option);
    while (t1 && *t1)
    {
        ft_affblock(*t1++, option);
        ft_putspace(t1, *t1, option);
    }
    while (t2 && *t2)
    {
        ft_affblock(*t2++, option);
        ft_putspace(t2, *t2, option);
    }
}

void    ft_affdefault(t_data data, char *option)
{
    int ord;

    if (option == NULL || !ft_strchr(option, 'r'))
        ord = 1;
    else 
        ord = 0;
    ft_order(data.names, data.nb, ord);
    ft_order(data.files, data.nbf, ord);
    ft_afftab(data.names, data.files, option);
}

void    ft_affall(t_data data, char *option, char *name)
{
    int     i;
    char    *tmp;

    if (option != NULL && ft_strchr(option, 'R'))
    {
        ft_putstr(name);
        ft_putendl(":");
    }
    if (option == NULL || ft_strchr(option, 'a') || ft_strchr(option, 'r'))
        ft_affdefault(data, option);
    ft_putendl("");
}