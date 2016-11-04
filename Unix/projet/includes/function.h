/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 20:47:14 by dle-blon          #+#    #+#             */
/*   Updated: 2016/09/30 15:10:43 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <time.h>

# define bool	char
# define TRUE	1
# define FALSE	0

typedef struct	s_parameters
{
	char *primaire_str;
	char *secondaire_str;
	char *trafic_str;
	int station_count;
	int polling_count;
	int polling_delay;
	int delay_min;
	int delay_max;
	char *file_name;

}				t_parameters;

#define T_PARAMETERS_STRUCT_CLEAR(target)		\
{												\
	(target).primaire_str = NULL;				\
	(target).secondaire_str = NULL;				\
	(target).trafic_str = NULL;					\
	(target).station_count = 0;					\
	(target).polling_count = 0;					\
	(target).polling_delay = 0;					\
	(target).delay_min = 0;						\
	(target).delay_max = 0;						\
	(target).file_name = 0;						\
}

/* error functions */
void			basic_error (char *str);
void			fatal_error (char *str);

/* print functions */
void			ft_putstr (char const *s, int eol);
void			ft_putstr_fd (char const *s, int fd);

/* string functions */
char			*ft_itoa (int n);
void			ft_fill_tab (char *str, int length);

/* interfaces function */
void 			ft_primary_management (t_parameters *parameters);
void 			ft_secondary_management (t_parameters *parameters, int station_number);
void 			ft_traffic_management (t_parameters *parameters, int station_number);

#endif
