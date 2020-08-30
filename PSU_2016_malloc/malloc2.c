/*
** malloc2.c for  in /home/rayan/Memory/PSU_2016_malloc
**
** Made by Rayan
** Login   <raihane.akkache@epitech.net>
**
** Started on  Sat Feb 11 15:19:31 2017 Rayan
** Last update Sat Feb 11 15:36:08 2017 Rayan
*/

#include "list.h"

extern pthread_mutex_t thread;
extern void            *pblock;
extern t_list          *list;
extern t_list          *last;

void            *split_beetwen_block(int s, t_list *tmp)
{
  if ((char *)tmp->block - (char *)pblock + ALLOC_SIZE + 1 <= tmp->size)
    {
      tmp->size = s;
      add_between_elem((char *)(tmp->next) - (char *)(tmp->block) - ALLOC_SIZE,
		       (char *)tmp + ALLOC_SIZE, (char *)(tmp->block)
		       + ALLOC_SIZE, tmp);
    }
  tmp->is_free = 0;
  return (tmp->block);
}

void    free(void *p)
{
  pthread_mutex_lock(&thread);
  free2(p);
  pthread_mutex_unlock(&thread);
}

void            *new_page(int s, size_t pagesize)
{
  void          *ret;

  if (last->is_free == 1)
    {
      if (sbrk((((s - last->size) / pagesize) + 1) * pagesize) == (void *)-1)
	return (NULL);
      last->size = s;
      last->is_free = 0;
    }
  else
    {
      if (sbrk(MULTIPLE_PAGE) == (void *)-1)
	return (NULL);
      add_elem(s, (char *)last->block + last->size, (char *)last->block
	       + last->size + sizeof(t_list));
    }
  ret = last->block;
  if (ALREADY_ALLOC + sizeof(t_list) + 1 <= pagesize)
    {
      add_elem(pagesize - sizeof(t_list) - ALREADY_ALLOC,
	       (char *)last + ALLOC_SIZE, (char *)last->block + ALLOC_SIZE);
      last->is_free = 1;
    }
  return (ret);
}
