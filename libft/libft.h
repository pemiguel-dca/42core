/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:24:06 by pemiguel          #+#    #+#             */
/*   Updated: 2022/11/08 19:43:45 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//INCLUDES
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

//mem
char	*ft_strdup(char *src);
void	*ft_calloc(size_t nitems, size_t size);
void	ft_bzero(void *s, size_t n);
//void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *src, int c, size_t n);

//str
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
//char	*ft_strcpy(char *dest, char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlcat(char *dest, char *src, size_t size);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
//basic
int		ft_tolower(int ch);
int		ft_toupper(int ch);
int		ft_isalnum(int arg);
int		ft_isalpha(int arg);
int		ft_isascii(int ch);
int		ft_isdigit(int arg);
int		ft_isprint(int arg);

//tam e nb
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
//int		ft_abs(int x);
char	*ft_itoa(int n);

//func param
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

//put
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
//void	ft_putnbr(int nb);
//void	ft_putchar(char a);

//struct
typedef struct s_list
{
	struct s_list	*next;
	void			*content;
}	t_list;

//bonus
t_list	*ft_lstnew(void	*content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	*ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif
