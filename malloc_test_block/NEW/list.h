/*
** list.h for list.h in /home/rayan/Memory/malloc_test_sans_heap
**
** Made by Rayan
** Login   <raihane.akkache@epitech.net>
**
** Started on  Thu Feb  2 09:32:00 2017 Rayan
** Last update Wed Feb  8 13:34:02 2017 Axel
*/

#ifndef	LIST_H
# define LIST_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef	struct	s_list
{
  char		is_free;
  size_t	size;
  void		*block;
  struct s_list	*next;
}		t_list;

/*void	*pblock;
t_list	*list = NULL;
t_list	*last = NULL;
*/
void		add_elem(size_t s, void *pmetadata, void *pdata);
void            add_between_elem(size_t s, void *pmetadata, void *pdata, t_list *pos);




void		my_put_nbr(int nb);

void		my_putchar(char c);

int     mstrlen(char *s);

//t_list		*sup_elem(t_list *l);
//t_list		*sup_elem_p(t_list *l, void *p);
void	showlist(t_list *l);
void	test();
void	putstr(char *str);
char    *test2(char *s);

void    *malloc_empty(int s, size_t pagesize);
void    *split_beetwen_block(int s, t_list *tmp);
void    *split_at_the_end(int s, size_t pagesize);

void            *new_page(int s, size_t pagesize);
void            *malloc2(size_t s);
void            *realloc2(void *ptr, size_t size);
  void            free2(void *p);

#endif /* LIST_H */
