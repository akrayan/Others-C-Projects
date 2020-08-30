/*
** list.c for list.c in /home/rayan/Memory/PSU_2016_malloc
**
** Made by Rayan
** Login   <raihane.akkache@epitech.net>
**
** Started on  Mon Jan 30 11:30:15 2017 Rayan
** Last update Sun Feb  5 16:13:03 2017 Rayan
*/

#include "list.h"

extern void	*pblock;
extern t_list	*list;
extern t_list	*last;

void		add_elem(size_t s, void *pmetadata, void *pdata)
{
  t_list	*new;

  new = pmetadata;
  new->next = NULL;
  new->block = pdata;
  new->size = s;
  new->is_free = 0;
  if (list == NULL)
    {
      last = new;
      list = new;
    }
  last->next = new;
  last = new;
}

void		add_after_elem(size_t s, void *pmetadata, void *pdata, t_list **pos)
{
  t_list	*new;

  new = pmetadata;
  new->next = (*pos)->next;
  new->block = pdata;
  new->size = s;
  new->is_free = 1;
  (*pos)->next = new;
}
/*t_list		*sup_elem(t_list *l)
{
  if (l == NULL)
    return (l);
  brk(l + sizeof(t_list));
  l = l->next;
  sbrk(- sizeof(t_list));
  printf(" %p\n", sbrk (0));
  return (l);
  }*/
/*
t_list		*sup_elem_p(t_list *l, void *p)
{
  t_list	*tmp;

  if (l == NULL)
    return (l);
  if (l->block == p)
    {
      brk(l + sizeof(t_list));
      l = l->next;
      sbrk(- sizeof(t_list));
      return (l);
    }
  tmp = l;
  while (tmp->next != NULL && tmp->next->block != tmp)
    tmp = tmp->next;
  if (tmp->next  == NULL)
    return (l);
  brk(tmp->next + sizeof(t_list));
  tmp->next = tmp->next->next;
  sbrk(- sizeof(t_list));
  return (l);
  }*/

void		show_list(t_list *l)
{
  t_list	*p;

  p = l;
  while (p != NULL)
    {
      printf("%p = %s\n", p, ((char *)p->block));
      p = p->next;
    }
}
