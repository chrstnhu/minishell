/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:39:55 by hailuo            #+#    #+#             */
/*   Updated: 2024/04/25 10:42:09 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// libc
int			ft_abs(int i);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strcat(char *dest, char *src);
char		*ft_strcpy(char *dest, char *src);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi(const char *nptr);
long		ft_atol(const char *str);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);
char		*ft_strndup(const char *s, size_t n);
int			ft_isspace(char c);
long long	ft_atoll(const char *str);

// additional
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(const char *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnstr_fd(char *s, int len, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_nbrlen(int n, int base);
int			ft_unbrlen(unsigned long long n, int base);

// bonus
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

typedef struct s_fmt
{
	bool	minus;
	bool	plus;
	bool	space;
	bool	hashtag;
	bool	zero;
	int		width;
	bool	dot;
	int		precision;
	int		len;
	int		upper;
	int		pad;
	int		offset;
	va_list	args;
}	t_fmt;

//ft_printf.c
int			ft_printf(const char *str, ...);

//ft_printf_utils.c
void		print_c(t_fmt *fmt);
void		print_s(t_fmt *fmt);
void		print_p(t_fmt *fmt, int len);
void		print_i(t_fmt *fmt);
void		print_u(char c, int base, t_fmt *fmt);

//libft_utils.c
void		ft_putunbr_base_fd(unsigned long long n, int base, int fd);
void		ft_putfnbr_base_fd(long long n, int base, t_fmt *fmt, int fd);
void		pad_set_i(int base, t_fmt *fmt, int n);
void		pad_set_u(int base, t_fmt *fmt, unsigned int n);

#endif
