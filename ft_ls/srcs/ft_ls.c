#include "ft_ls.h"

t_dir   **ft_getcontain(t_dir **container, t_dir *info, int nb)
{
    int     i;
    t_dir   **tmp;

    if (!(tmp = (t_dir**)malloc(sizeof(t_dir *) * (nb + 1))))
        ft_error("Malloc", 1);
    i = -1;
    while (++i < nb - 1)
    {
        tmp[i] = container[i];
        //if (container[i])
            //free(container[i]);
    }
    //if (container)
        //free(container);
    tmp[i] = info;
    //if (info)
        //free(info);
    return (tmp);
}

void    ft_write(char **name, t_dir **container, int dir)
{
    int i;
    int j;
    int bol;

    i = 0;
    j = 0;
    while(container[i])
    {
        if (dir)
            bol = container[i]->d_type == DT_DIR;
        else
            bol = container[i]->d_type != DT_DIR;
        if (bol)
            name[j++] = ft_strdup(container[i]->d_name);
        ++i;
    }
}

void    ft_config(t_data *data, t_dir **container)
{
    int     i;

    if (!container)
        return ;
    i = 0;
    ft_init(data, 0);
    while (container[i])
    {
        if (container[i]->d_type == DT_DIR)
            ++data->nb;
        else
            ++data->nbf;
        ++i;
    }
    if (data->nb && !(data->names = (char**)malloc(sizeof(char*) * ++data->nb)))
        return ;
    if (data->nb)   data->names[--data->nb] = NULL;
    if (data->nbf
        && !(data->files = (char**)malloc(sizeof(char*) * ++data->nbf)))
        return ;
    if (data->nbf)  data->files[--data->nbf] = NULL;
    ft_write(data->names, container, 1);
    ft_write(data->files, container, 0);
}

void    ft_loopdir(char *name, char *option)
{
    int     i;
    t_data  tmp;
    t_dir   *info;
    t_dir   **container;
    DIR     *dir;

    if (!(dir = opendir(name)))
        ft_error("Opendir", 0);
    if (!dir)
        return ;
    i = 1;
    container = NULL;
    while ((info = readdir(dir)))
    {
        container = ft_getcontain(container, info, i);
        ++i;
    }
    ft_config(&tmp, container);
    ft_affall(tmp, option, name);
    ft_norme(name, tmp.names);
    if (ft_checkname(tmp.names) && option && ft_strchr(option, 'R'))
        ft_ls(tmp.names, option, tmp.nb, 0);
    if (closedir(dir) == -1)
        ft_error("Closedir", 0);
    //ft_freeall(name, tmp, container);
}

void    ft_ls(char **names, char *option, int nb, int start)
{
    int     i;

    i = 0;
    while (i < nb)
    {
        if (start)
            ft_loopdir(names[i], option);
        if (!start && ft_checkcurrent(names[i]))
            ft_loopdir(names[i], option);
        ++i;
    }
}