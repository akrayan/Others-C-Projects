/*
** list.h for list.h in /home/rayan/Memory/malloc_test_sans_heap
**
** Made by Rayan
** Login   <raihane.akkache@epitech.net>
**
** Started on  Thu Feb  2 09:32:00 2017 Rayan
** Last update Mon Feb  6 16:13:27 2017 Axel
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


int		my_put_nbr(int nb);

int		my_putchar(char c);
//t_list		*sup_elem(t_list *l);
//t_list		*sup_elem_p(t_list *l, void *p);
void	show_list(t_list *l);
void	test();

#endif /* LIST_H */
