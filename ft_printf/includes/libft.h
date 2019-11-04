/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:49:11 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/11 13:41:09 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include "get_next_line.h"

/*
** ============
**  STRUCTURES
** ============
*/

typedef enum		e_bool
{
	FALSE = 0,
	TRUE = 1
}					t_bool;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** ===========
**  FUNCTIONS
** ===========
*/

/*
*************************************
**        MEMORY MANAGEMENT        **
*************************************
*/
void				*ft_memset(void *dest, int ch, size_t count);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t count);
void				*ft_memccpy(void *dest, const void *src, int c,
						size_t count);
void				*ft_memmove(void *dest, const void *src, size_t count);
void				*ft_memchr(const void *ptr, int ch, size_t count);
int					ft_memcmp(const void *lhs, const void *rhs, size_t count);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);


/*
*************************************
**         CHAR OPERATIONS         **
*************************************
*/
t_bool				ft_isspace(int c);
t_bool				ft_isupper(int c);
t_bool				ft_islower(int c);
t_bool				ft_isalpha(int ch);
t_bool				ft_isdigit(int ch);
t_bool				ft_isalnum(int ch);
t_bool				ft_isascii(int ch);
t_bool				ft_isprint(int ch);
int					ft_toupper(int ch);
int					ft_tolower(int ch);


/*
*************************************
**        STRING OPERATIONS        **
*************************************
*/
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t count);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t count);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *str, int ch);
char				*ft_strrchr(const char *str, int ch);
char				*ft_strstr(const char *str, const char *substr);
char				*ft_strnstr(const char *str, const char *substr,
						size_t size);
int					ft_strcmp(const char *lhs, const char *rhs);
int					ft_strncmp(const char *lhs, const char *rhs, size_t count);
int					ft_atoi(const char *str);
long				ft_atol(const char *str);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, int base);
char				*ft_ntoa_base(unsigned long int nb, int base);
char				*ft_dtoa(double nb, size_t preci);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char 				**ft_splitwhite(char const *s);
void				ft_freetabsplit(char **tab);
t_bool				ft_str_is_alpha(const char *s);
t_bool				ft_str_is_numeric(const char *s);
t_bool				ft_str_is_lowercase(const char *s);
t_bool				ft_str_is_uppercase(const char *s);
char				*ft_strupcase(char *s);
char				*ft_strlowcase(char *s);
char				*ft_strndup(const char *str, size_t n);
char				*ft_strcapitalize(char *s);
char				*ft_str_addi_front(char c, char *s, size_t iter);
char				*ft_str_addi_back(char c, char *s, size_t iter);
t_bool				ft_str_contains(const char *str, char c);


/*
*************************************
**          DISPLAY TOOLS          **
*************************************
*/
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);


/*
*************************************
**         LIST OPERATIONS         **
*************************************
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstpushback(t_list **alst, t_list *new);

/*
*************************************
**    NUMBER AND TAB OPERATIONS    **
*************************************
*/
void				ft_tabiter_int(int *tab, size_t size, void (*f)(int));
void				ft_print_tab_int(int *tab, size_t size);
int					ft_sqrt(int nb);
int					ft_imin(int lhs, int rhs);
int					ft_imax(int lhs, int rhs);
int					ft_iabs(int nb);

#endif
