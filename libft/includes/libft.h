/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 18:29:11 by dle-blon          #+#    #+#             */
/*   Updated: 2016/10/27 21:02:15 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define TRUE	1
# define FALSE	0

# define PRINT_DEBUG	FALSE

/*
** constants pointer
*/

typedef const void *	t_cpvoid;
typedef const char *	t_cpchar;
typedef const short *	t_cpshort;
typedef const int *		t_cpint;
typedef const long *	t_cplong;

/*
** debug functions
*/

void	ft_debug_file ();
void	ft_debug_line ();
void	ft_debug_file_line ();

/*
** print functions
*/

void	ft_putchar (char c);
void	ft_putchar_fd (char c, int fd);
void	ft_putnbr (int n);
void	ft_putnbr_fd (int n, int fd);
void	ft_putstr (t_cpchar s);
void	ft_putstr_fd (t_cpchar s, int fd);
void	ft_putendl (t_cpchar s);
void	ft_putendl_fd (t_cpchar s, int fd);

/*
** memory functions
*/

int		ft_memcmp (t_cpvoid s1, t_cpvoid s2, size_t n);
void	*ft_memchr (t_cpvoid s, int c, size_t n);
void	*ft_memcpy (void *dest, t_cpvoid src, size_t n);
void	*ft_memccpy (void *dest, t_cpvoid src, int c, size_t n);
void	*ft_memmove (void *dest, t_cpvoid src, size_t n);
void	*ft_memset (void *s, int c, size_t n);
void	*ft_memalloc (size_t size);
void	ft_memdel (void **ap);
void	ft_bzero (void *s, size_t n);

/*
** is functions
*/

int		ft_isprint (int c);
int		ft_isalnum (int c);
int		ft_isdigit (int c);
int		ft_isalpha (int c);
int		ft_isascii (int c);
int		ft_toupper (int c);
int		ft_tolower (int c);

/*
** converters
*/

int		ft_atoi (t_cpchar str);
char	*ft_itoa (int n);

/*
** string functions
*/

char	*ft_strchr (t_cpchar s, int c);
char	*ft_strrchr (t_cpchar s, int c);
char	*ft_strstr (t_cpchar str1, t_cpchar str2);
char	*ft_strnstr (t_cpchar str1, t_cpchar str2, size_t n);
int		ft_strcmp (t_cpchar str1, t_cpchar str2);
int		ft_strncmp (t_cpchar str1, t_cpchar str2, size_t n);
char	*ft_strdup (t_cpchar s);
char	*ft_strcat (char *dest, t_cpchar src);
char	*ft_strncat (char *dest, t_cpchar src, size_t num);
size_t	ft_strlcat (char *dest, t_cpchar src, size_t dstsize);
char	*ft_strt_cpy (char *dest, t_cpchar src);
char	*ft_strnt_cpy (char *dest, t_cpchar src, size_t num);
size_t	ft_strlen (t_cpchar s);
char	*ft_strnew (size_t size);
void	ft_strdel (char **as);
void	ft_strclr (char *s);
void	ft_striter (char *s, void (*f) (char *));
void	ft_striteri (char *s, void (*f) (unsigned int, char*));
char	*ft_strmap (t_cpchar s, char (*f) (char));
char	*ft_strmapi (t_cpchar s, char (*f) (unsigned int, char));
int		ft_strequ (t_cpchar s1, t_cpchar s2);
int		ft_strnequ (t_cpchar s1, t_cpchar s2, size_t n);
char	*ft_strsub (t_cpchar s, unsigned int start, size_t size);
char	*ft_strjoin (t_cpchar s1, t_cpchar s2);
char	*ft_strtrim (t_cpchar s);
char	**ft_strsplit (t_cpchar s, char c);

#endif
