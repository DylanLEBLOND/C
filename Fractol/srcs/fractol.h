/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 14:39:52 by dle-blon          #+#    #+#             */
/*   Updated: 2016/03/07 21:32:41 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define ESCAPE     53
# define LEFT       123
# define RIGHT      124
# define UP         126
# define DOWN       125
# define PLUS		69
# define MINUS		78
# define SPACE      49

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <complex.h>
# include <math.h>

# define ZBOUB double complex

typedef struct		s_coor
{
	int		x;
	int		y;
	int		c;
	char	et;
}					t_coor;

typedef struct		s_fract
{
	int		ite;
	double	x1;
	double	y1;
	double	c_r;
	double	c_i;
	int		color;
}					t_fract;

typedef struct		s_mlx
{
	void	*mlx;
	void	*win;
	void	*new;
	char	*img;
	char	*name;
	t_fract	var;
	int		size;
	int		end;
	int		bit;
	double	s;
	double	z;
	int		rol;
	int		lp;
	int		c;
}					t_mlx;

void				*ft_memcpy(void *dest, const void *src, size_t n);
void				mlx_put_pixel_to_img(t_mlx *map, int x, int y, int color);
void				putimg(t_mlx *map);
void				putfrac(t_mlx *map, t_coor *mdl);
void				ft_putendl(char const *s);
int					ft_strcmp(const char *str1, const char *str2);
void				coderror(char c);
char				*ft_strdup(const char *s);
int					color(char *str);

t_coor				ismandl(int x, int y, double zoom, t_fract var);
t_coor				*mandel(int xmax, int ymax, double z, t_fract var);
int					key_mand(int keycode, t_mlx *map);
int					mouse_hook(int button, int x, int y, t_mlx *map);
int					expose_mand(t_mlx *map);
void				init_mand(t_mlx *map, char n, int color);
void				mandelbrot(int c);

t_coor				isjul(int x, int y, double zoom, t_fract var);
t_coor				*julie(int xmax, int ymax, double z, t_fract var);
int					key_jul(int keycode, t_mlx *map);
int					moove_jul(int x, int y, t_mlx *map);
int					expose_jul(t_mlx *map);
void				init_jul(t_mlx *map, char n, int color);
void				julia(int c);

t_coor				isburn(int x, int y, double zoom, t_fract var);
t_coor				*burning(int xmax, int ymax, double z, t_fract var);
int					key_burn(int keycode, t_mlx *map);
int					expose_burn(t_mlx *map);
void				init_burn(t_mlx *map, char n, int color);
void				burningship(int c);

t_coor				isdou(int x, int y, double zoom, t_fract var);
t_coor				*doua(int xmax, int ymax, double z, t_fract var);
int					key_dou(int keycode, t_mlx *map);
int					expose_dou(t_mlx *map);
void				init_dou(t_mlx *map, char n, int color);
void				douady(int c);
#endif
