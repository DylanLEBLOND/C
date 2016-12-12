/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 15:44:30 by dle-blon          #+#    #+#             */
/*   Updated: 2015/04/02 14:13:02 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct		s_val
{
	float	a;
	float	b;
	float	c;
}					t_val;

typedef struct		s_useless
{
	int		len;
	int		zero;
	int		deg;
	int		nul;
	int		pos;
}					t_useless;

typedef	struct		s_compt
{
	int		i;
	int		j;
	int		size;
}					t_compt;

typedef struct		s_puis
{
	int		degre;
	float	nb;
}					t_puis;

typedef struct		s_alex
{
	int		signe;
	int		cd;
	int		sv;
}					t_alex;

int					justnb(char *str);
float				ft_atof(char *str);
int					ft_error(char *str);
void				ft_initint(int *tab, int size);
int					ft_member(int *tab, int nb, int size);
int					*ft_lentritab(int *tab, int *s, int size);
int					test_float(char *str);
float				racine(float nb);
void				useless(void);
int					test_degre(t_puis *tab);
int					ft_reatoi(const char *str, int *exp, int *s);
int					afftab(t_puis *tab, int len);
t_puis				*checktab(t_puis *tab, int *len);
void				test1(char *str, t_puis *tab, t_compt *cpt, int pos);
void				test2(char *str, t_puis *tab, t_compt *cpt, int pos);
void				comput(char *str, char *flag);
void				polyone(t_puis *tab, char *flag, int len);
void				poly(t_puis *tab, char *flag, int len);
void				affzero(float delta, char *flag, t_val x);
void				affsup(float delta, char *flag, t_val x);
void				affneg(float delta, char *flag, t_val x);
#endif
