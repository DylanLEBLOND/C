/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:00:59 by dle-blon          #+#    #+#             */
/*   Updated: 2016/02/11 20:57:21 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/types.h>
# include "./../libft/libft.h"

# define BUFF_SIZE 512

typedef	struct	s_tetri
{
	int			*x;
	int			*y;
	int			nb;
}				t_tetri;

typedef struct	s_info
{
	int		n;
	int		nb;
	t_tetri	*tetris;
}				t_info;

void			ft_error(char c);
void			ft_check(char **file);
char			**ft_organize(char *name);
void			ft_getdata(char **file, t_info *data);
void			validtetri(t_info *data);
void			algo(t_info data);
int				size_min(int nb);
char			**tab_init(int size);
void			aff_solution(char **solution);
void			free_solution(char **solution);
void			init_letter(t_info data);
#endif
