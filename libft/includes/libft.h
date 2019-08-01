/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:01:35 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 18:45:25 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include "ft_printf.h"

# define BUFF_SIZE	1
# define EOL		'\n'
# define ABS(x)		(x < 0 ? (-x) : x)

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_vector
{
	void			**array;
	size_t			capacity;
	size_t			size;
}					t_vector;

int					ft_strsplit_count(const char **split);
int					ft_split_has_dupl(const char **split);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2,
					const size_t num);
long				ft_atoi(const char *str);
int					ft_isalpha(const int c);
int					ft_isdigit(const int c);
int					ft_isalnum(const int c);
int					ft_isascii(const int c);
int					ft_isprint(const int c);
int					ft_toupper(const int c);
int					ft_tolower(const int c);
int					ft_strisdigit(const char *s);
int					ft_count_words(const char *s, const char c);
int					ft_memcmp(const void *restrict memptr1,
					const void *restrict memptr2, const size_t num);
int					ft_splitdel(char ***split);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, const size_t n);
int					get_next_line(const int fd, char **line);
double				ft_atof(const char *num);
char				*ft_strdup(const char *str);
char				*ft_strstr(const char *str1, const char *str2);
char				*ft_strcpy(char *dest, const char *from);
char				*ft_strcat(char *dest, const char *from);
char				*ft_strncat(char *dest, const char *from, const size_t num);
char				*ft_strncpy(char *dest, const char *from, const size_t num);
char				*ft_strchr(const char *str, const int symbol);
char				*ft_strrchr(const char *str, const int symbol);
char				*ft_strnstr(const char *str1, const char *str2, size_t num);
char				*ft_strnew(const size_t size);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strsub(const char *s, const unsigned int start,
					const size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strs_join_c(const char *str1, const char *str2,
					const char c);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, const char c);
char				*ft_itoa(int n);
char				*ft_strjoinch(const char *s1, const char c);
char				*ft_strrealloc(char *old_buf, const size_t size);
char				**ft_splitrealloc(char **old, const int size);
char				**ft_remove_from_split_c(char **split, char *var, char c);
char				**ft_remove_from_split(char **split, char *var);
char				*ft_replace_substring(const char *str,
					const char *old, const char *new);
char				*ft_split_join_delimiter(const char **split,
					const char *delimiter);
char				*ft_split_join(const char **split);
char				**ft_append_to_split(char **split, char *str);
void				*ft_memcpy(void *restrict destptr,
					const void *restrict srcptr, size_t num);
void				*ft_memccpy(void *restrict destptr,
					const void *restrict srcptr, const int c, size_t n);
void				*ft_memset(void *restrict memptr, const int val,
					const size_t num);
void				*ft_memmove(void *restrict destptr,
					const void *restrict strptr, size_t num);
void				*ft_memchr(const void *restrict memptr,
					const int val, size_t num);
void				*ft_memalloc(const size_t size);
void				ft_bzero(void *restrict memptr, const size_t len);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
void				ft_swapint(int *a, int *b);
void				ft_putchar(const char c);
void				ft_putstr(const char *s);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(const char c, const int fd);
void				ft_putstr_fd(const char *s, const int fd);
void				ft_putendl_fd(const char *s, const int fd);
void				ft_putnbr_fd(int n, const int fd);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *newl);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstrev(t_list **alst);
void				ft_doubleptrdel(void ***ptr);
void				print_split(const char **split);
void				safe_free(void *ptr);
size_t				ft_strnlen(const char *str, const size_t max);
size_t				ft_strlen(const char *str);
size_t				ft_lstcount(t_list *lst);
size_t				ft_strlcat(char *dest, const char *from, const size_t size);
t_list				*ft_lstnew(const void *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				vector_push_back(t_vector *vector, void *data);
void				*vector_get_at(t_vector *vector, size_t index);
bool				ft_is_whitespace(const char c);

#endif
