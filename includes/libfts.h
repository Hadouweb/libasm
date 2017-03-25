#ifndef LIBFTS_H
# define LIBFTS_H

#include <stdio.h>

# define PTR_NODE(ptr, t, member) (t*) ((char*)ptr - (char*)&((t*)0)->member)

typedef struct		s_link
{
	struct s_link	*prev;
	struct s_link	*next;
}					t_link;

typedef struct		s_list
{
	t_link			link;
	t_link			*head;
	t_link			*tail;
	unsigned long	size;
}					t_list;

void				ft_bzero(void *s, size_t n);
char 				*ft_strcat(char *s1, const char *s2);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_puts(const char *s);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *str, size_t n);
char				*ft_strdup(const char *s1);
void				ft_cat(int fd);

/*
**	BONUS
*/
void				ft_list_push_back(t_list *list, t_link *link);
void				ft_list_push_front(t_list *list, t_link *link);
void				ft_list_push_after_node(t_list *list, t_link *node,
						t_link *new_node);
void				ft_list_push_before_node(t_list *list, t_link *node,
						t_link *new_node);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);

#endif
