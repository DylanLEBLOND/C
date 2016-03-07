/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:53:06 by dle-blon          #+#    #+#             */
/*   Updated: 2016/03/07 21:17:42 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE	8
# define CST1		0.5
# define CST2		0.5
# define AGR		50
# define PROF		-0.5
# define WIDTH		2000
# define HEIGHT		1250

# include <mlx.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include "./../libft/libft.h"

typedef struct		s_coor
{
	int		x;
	int		y;
	int		z;
	int		c;
	char	etat;
}					t_coor;

typedef struct		s_ix
{
	int		xmin;
	int		xmax;
	int		ymin;
	int		ymax;
	int		zmin;
	int		zmax;
}					t_ix;

typedef struct		s_mlx
{
	void	*mlx;
	void	*new;
	t_ix	dim;
	t_coor	**map;
}					t_mlx;

void				coderror(char c);
char				**tabreal(char **tab, char *newline, int len);
char				**getnext(char *param, int *len);
void				remp(char *str, int y, t_coor *tab, t_ix *dim);
t_coor				*getnbr(char *str, int y, t_ix *dim);
int					get_next_line(int const fd, char **line);
void				initdim(t_ix *dim);
t_coor				**stockmap(char *param, t_ix *dim);
int					key_hook(int keycode, t_mlx *point);
int					expose_hook(t_mlx *point);
void				drtfctx(void *mlx, void *new, t_coor p1, t_coor p2);
void				drtfcty(void *mlx, void *new, t_coor p1, t_coor p2);
void				drt(void *mlx, void *new, t_coor p1, t_coor p2);
void				ft_fdf(t_mlx point);
int					redim(t_ix dim);
void				newcoor(t_coor **map, t_ix dim, int c);
void				mincolor(t_coor *tab, t_ix *dim);
int					colneg(int z, int zmin);
int					colpos(int z, int zmax);
t_coor				**putcolor(t_coor **map, t_ix *dim);
#endif
