/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 18:24:49 by dle-blon          #+#    #+#             */
/*   Updated: 2015/04/03 18:24:53 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_var
{
	int i;
	int size;
	int *p_a;
	int *p_b;
	int *tri;
	int c;
	int pivot;
	int t;
	int f;
	int o;
	int oc;
	int on;
	int ov;
}				t_var;

int				ft_strlen(char *s);
void			ft_error(int e);
int				ft_strcmp(const char *s1, const char *s2);
void			check_error(char *s, int c);
void			ft_check(char *s);
int				ft_atoi(const char *str);
void			ft_putchar(char c);
void			ft_putstr(char *s);
void			ft_putnbr(int n);
void			aff_tab(int *tab, int size, int a);
int				*ft_tabdup(int *tab, int size);
int				*pile_a(t_var var, char **av);
int				test(int *tri, int ac);
int				*tri_tab(int *pile_a, int ac, int *t);
void			push_a(t_var *var);
void			push_b(t_var *var);
void			rotate(t_var *var, int *pile, int size, int ra);
void			reverse_rotate(t_var *var, int *pile, int size, int ra);
int				way(t_var *var, int max);
int				way2(t_var *var, int n);
void			remp(t_var *var);
void			remp2(t_var *var);
void			remp_u(t_var *var);
void			swap(t_var *var, int *pile, int pa);
void			algo1(t_var *var);
void			algo3(t_var *var);
void			algo4(t_var *var);
void			algo5(t_var *var);
void			algo_tri(t_var *var);
void			algo_u(t_var *var);
void			var_u(t_var *var, int ac);
void			options(t_var *var, char **av);
int				options_cv(t_var *var, int n);
void			oc(t_var *var, int n);
void			ov(t_var *var, int n);
void			ocv(t_var *var, int n);
#endif
