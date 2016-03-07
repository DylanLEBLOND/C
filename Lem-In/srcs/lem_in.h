/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 15:20:00 by dle-blon          #+#    #+#             */
/*   Updated: 2015/11/01 20:04:42 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./../libft/libft.h"

# define BUFF_SIZE	512

typedef struct		s_node
{
	char			*name;
	int				x;
	int				y;
	int				washere;
	int				nblinks;
	int				*links;
}					t_node;

typedef struct		s_road
{
	int				len;
	int				*nodes;
}					t_road;

typedef struct		s_param
{
	char			**file;
	t_node			*tree;
	t_road			*roads;
	int				*best;
	int				start;
	int				end;
	int				node;
	int				nbroad;
	int				nblemin;
}					t_param;

void				ft_error(char c);
char				**ft_organize(void);
t_node				*ft_createnode(char **file, int *node);
void				ft_initnode(t_param *set);
int					ft_getspace(char *str);
char				*ft_getname(char *str);
int					ft_getdash(char *str);
void				ft_getxy(char *str, t_node *node, int *pos, int nbnode);
void				ft_initlinks(t_param *set);
void				ft_getroad(t_param *set);
int					*ft_getbestway(t_param *set);
void				ft_moove(t_param *set);
#endif
