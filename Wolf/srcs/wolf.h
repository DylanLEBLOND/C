/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 19:42:17 by dle-blon          #+#    #+#             */
/*   Updated: 2015/06/04 19:19:58 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# define BUFF_SIZE	104
# define HEIGHT		52
# define WIDTH		52
# define HMAP		812
# define WMAP		1080
# define HMINI		156
# define WMINI		208
# define ROT		69
# define ESCAPE		53
# define LEFT		123
# define RIGHT		124
# define UP			126
# define DOWN		125
# define SPACE		49

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "./../libft/libft.h"

typedef struct	s_ray
{
	int		zone;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lheight;
	int		drwstart;
	int		save;
	int		drwend;
	int		color;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	plax;
	double	play;
	double	camx;
	double	camy;
	double	raypx;
	double	raypy;
	double	raydx;
	double	raydy;
	double	sidedx;
	double	sidedy;
	double	dltdx;
	double	dltdy;
	double	perpwd;
}				t_ray;

typedef struct	s_need
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*new;
	void	*new_mnp;
	void	*img_mnp;
	int		bt;
	int		sz;
	int		end;
	int		bt_mini;
	int		sz_mini;
	int		end_mini;
	int		**map;
	t_ray	inf;
}				t_need;

void			freetab(int **map);
void			afftab(int **map);
void			remp(int fd, t_need *greed);
int				createfd(void);
void			createminimap(t_need *greed);
void			modifmini(t_need *greed);
void			initfirst(t_ray *inf, int x);
void			initsecond(t_ray *inf);
void			loopone(t_ray *inf, int **map);
void			looptwo(t_ray *inf, t_need *greed, int x);
void			loopthree(t_ray *inf, t_need *greed, int x);
void			wolfhere(t_need *greed);
void			moveup(int **map, t_ray *inf);
void			movedown(int **map, t_ray *inf);
void			moveright(t_ray *inf);
void			moveleft(t_ray *inf);
void			putcolor(int x, t_ray *inf, t_need *greed);
void			wolf(void);
void			coderror(char c);
void			mlx_put_pixel_to_img(t_need *greed, int x, int y, int color);
void			mlx_put_pixel_to_mini(t_need *greed, int x, int y, int color);
#endif
