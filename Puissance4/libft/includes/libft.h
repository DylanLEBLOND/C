/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:28:56 by abary             #+#    #+#             */
/*   Updated: 2016/02/26 21:42:03 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdint.h>
# define N_LIST t_list
# define LIST_CHAR content
# define BUFF_SIZE 10

union			u_db
{
	unsigned long	uint;
	double			udb;

};

size_t			ft_strlen(const char *s);
char			*ft_strchrstr(const char *s1, const char *s2, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s1);
char			*ft_strcat(char *s1, const char *s2);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_toupper(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			*ft_strnew(size_t size);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_ltoa(long long n);
char			*ft_imtoa(intmax_t n);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char const *s, int fd);
char			*ft_strtoupper(char *str);
void			ft_putnbr_base(int nbr, int base);
typedef struct	s_list
{
	void					*content;
	size_t					content_size;
	struct s_list			*next;
}				t_list;
t_list			*ft_lstnew(void const *content, size_t content_size);
int				ft_strequ(char const *s1, char const *s2);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lst_addtri_char(N_LIST **begin, N_LIST *elem);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstadd_end(t_list **alst, t_list *new);
int				ft_abs(int nb);
char			*ft_strrev(char *str);
void			ft_printbit(unsigned char byte);
char			*ft_strndup(const char *s1, size_t len);
char			*ft_strnjoin(const char *s1, const char *s2, size_t len);
void			ft_lstclean(t_list **begin);
char			*ft_itoa_base(int n, int base);
char			*ft_utoa_base(unsigned int n, int base);
void			ft_putdouble(double nb);
void			ft_puthexfloat(float nb);
int				ft_power(int nbr, int power);
int				ft_printf(const char *format, ...);
int				ft_printf_error(const char *format, ...);
char			*ft_ultoa_base(unsigned long long n, int base);
char			*ft_ltoa_base(long long n, int base);
char			*ft_utoa(int n);
char			*ft_ultoa(unsigned long long n);
char			*ft_binary_double(double db);
void			ft_lst_swap(N_LIST **e_lst1, N_LIST **e_lst2, N_LIST **pre);
int				get_next_line(int const fd, char **line);
long			ft_atol(const char *str);
#endif
