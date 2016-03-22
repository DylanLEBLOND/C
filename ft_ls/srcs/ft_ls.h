#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <errno.h>
# include <dirent.h>
# include "../libft/libft.h"

typedef struct  s_data
{
    int     nb;
    int     nbf;
    char    **names;
    char    **files;
    char    *option;
}               t_data;

typedef struct  dirent t_dir;

void            ft_order(char **tab, int len, int ord);
void            ft_init(t_data *data, int max);
void            ft_affinfo(t_data data);
void            ft_affall(t_data data, char *option, char *name);
void            ft_ls(char **names, char *option, int nb, int start);
int             ft_checkcurrent(char *name);
int             ft_checkname(char **names);
void            ft_norme(char *name, char **directories);
void            ft_error(char *message, int end);
void            ft_init(t_data *data, int max);
void            ft_getnames(t_data *data, char *name);
void            ft_getoptions(t_data *data, char *name);

#endif