/*
** list.c for list.c in /home/rayan/Memory/PSU_2016_malloc
**
** Made by Rayan
** Login   <raihane.akkache@epitech.net>
**
** Started on  Mon Jan 30 11:30:15 2017 Rayan
** Last update Sun Feb 12 08:16:20 2017 Rayan
*/

#include "list.h"

extern void	*pblock;
extern t_list	*list;
extern t_list	*last;

void		add_elem(size_t s, void *pmetadata, void *pdata)
{
  t_list	*new;

  new = pmetadata;
  new = new;
  new->next = NULL;
  new->size = s;
  new->is_free = 0;
  if (list == NULL)
    list = new;
  else
    last->next = new;
  last = new;
  new->block = pdata;
}

void		add_between_elem(size_t s, void *pmetadata,
				 void *pdata, t_list *pos)
{
  t_list	*new;

  new = pmetadata;
  new->next = pos->next;
  new->block = pdata;
  new->size = s;
  new->is_free = 1;
  pos->next = new;
}

void	put_hexa(long nb)
{
  long	i;

  i = 1;
  putstr("0x");
  while (nb / i > 15)
    {
      i = i * 16;
    }
  while (i >= 1)
    {
      if (nb / i > 9)
	my_putchar(nb / i  + 87);
      else
	my_putchar((nb / i) + 48);
      nb = nb % i;
      i = i / 16;
    }
}

void            *split_at_the_end(int s, size_t pagesize)
{
  size_t        size;
  void          *ret;

  last->is_free = 0;
  size = last->size;
  last->size = s;
  ret = last->block;
  if ((((char *)last->block - (char *)pblock) % pagesize)
      + ALLOC_SIZE + sizeof(t_list) + 1 <= pagesize)
    {
      add_elem(size - ALLOC_SIZE,
               (char *)last + ALLOC_SIZE, (char *)last->block + ALLOC_SIZE);
      last->is_free = 1;
    }
  return (ret);
}

t_list                  *fusion(t_list *tmp, t_list *prev)
{
  if (tmp->next != NULL && tmp->next->is_free == 1)
    {
      if (tmp->next == last)
        last = tmp;
      tmp->size = tmp->size + tmp->next->size + sizeof(t_list);
      tmp->next = tmp->next->next;
    }
  if (prev != NULL && prev->is_free == 1)
    {
      if (tmp == last)
        last = prev;
      prev->size = prev->size + tmp->size + sizeof(t_list);
      prev->next = tmp->next;
      tmp = prev;
    }
  return (tmp);
}
