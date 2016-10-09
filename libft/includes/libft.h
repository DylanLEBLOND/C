/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 18:29:11 by dle-blon          #+#    #+#             */
/*   Updated: 2016/10/03 19:49:26 by dle-blon         ###   ########.fr       */
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

/* constants pointers */

typedef const void * cpvoid;
typedef const char * cpchar;
typedef const short * cpshort;
typedef const int * cpint;
typedef const long * cplong;

/* debug functions */

void	ft_debug_file ();
void	ft_debug_line ();
void	ft_debug_file_line ();

/* print functions */

void	ft_putchar (char c);
void	ft_putchar_fd (char c, int fd);
void	ft_putnbr (int n);
void	ft_putnbr_fd (int n, int fd);
void	ft_putstr (cpchar s);
void	ft_putstr_fd (cpchar s, int fd);
void	ft_putendl (cpchar s);
void	ft_putendl_fd (cpchar s, int fd);

/* memory functions */

int		ft_memcmp (cpvoid s1, cpvoid s2, size_t n);
void	*ft_memchr (cpvoid s, int c, size_t n);
void	*ft_memcpy (void *dest, cpvoid src, size_t n);
void	*ft_memccpy (void *dest, cpvoid src, int c, size_t n);
void	*ft_memmove (void *dest, cpvoid src, size_t n);
void	*ft_memset (void *s, int c, size_t n);
void	*ft_memalloc (size_t size);
void	ft_memdel (void **ap);
void	ft_bzero (void *s, size_t n);

/* is functions */

int		ft_isprint (int c);
int		ft_isalnum (int c);
int		ft_isdigit (int c);
int		ft_isalpha (int c);
int		ft_isascii (int c);
int		ft_toupper (int c);
int		ft_tolower (int c);

/* converters */

int		ft_atoi (cpchar str);
char	*ft_itoa (int n);

/* string functions */

char	*ft_strchr (cpchar s, int c);
char	*ft_strrchr (cpchar s, int c);
char	*ft_strstr (cpchar str1, cpchar str2);
char	*ft_strnstr (cpchar str1, cpchar str2, size_t n);
int		ft_strcmp (cpchar str1, cpchar str2);
int		ft_strncmp (cpchar str1, cpchar str2, size_t n);
char	*ft_strdup (cpchar s);
char	*ft_strcat (char *dest, cpchar src);
char	*ft_strncat (char *dest, cpchar src, size_t num);
size_t	ft_strlcat (char *dest, cpchar src, size_t dstsize);
char	*ft_strcpy (char *dest, cpchar src);
char	*ft_strncpy (char *dest, cpchar src, size_t num);
size_t	ft_strlen (cpchar s);
char	*ft_strnew (size_t size);
void	ft_strdel (char **as);
void	ft_strclr (char *s);
void	ft_striter (char *s, void  (*f)  (char *));
void	ft_striteri (char *s, void  (*f)  (unsigned int, char*));
char	*ft_strmap (cpchar s, char  (*f) (char));
char	*ft_strmapi (cpchar s, char  (*f) (unsigned int, char));
int		ft_strequ (cpchar s1, cpchar s2);
int		ft_strnequ (cpchar s1, cpchar s2, size_t n);
char	*ft_strsub (cpchar s, unsigned int start, size_t size);
char	*ft_strjoin (cpchar s1, cpchar s2);
char	*ft_strtrim (cpchar s);
char	**ft_strsplit (cpchar s, char c);

#endif
