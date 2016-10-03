/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:44:10 by dle-blon          #+#    #+#             */
/*   Updated: 2016/04/11 13:53:53 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <stdio.h>
# include <dirent.h>
# include <libft.h>

typedef struct	s_data
{
	int		nb;
	int		nbf;
	char	**names;
	char	**files;
	char	*option;
}				t_data;

typedef struct	dirent	t_dir;
typedef struct	stat	t_stat;

typedef struct	s_info
{
	char	**names;
	t_stat	*container;
}				t_info;

void			ft_order(char **tab, int ord, int len);
char			**ft_fusion(t_data data);
void			ft_free(char **t1, char **t2);
void			ft_init(t_data *data, int max);
void			ft_affinfo(t_data data);
void			ft_affall(t_data data, char *option, char *name);
void			ft_ls(char **names, char *option, int nb, int start);
int				ft_checkcurrent(char *name);
int				ft_checkname(char **names);
void			ft_norme(char *name, char **directories);
void			ft_error(char *message, int end);
void			ft_init(t_data *data, int max);
void			ft_getnames(t_data *data, char *name);
void			ft_getoptions(t_data *data, char *name);

#endif