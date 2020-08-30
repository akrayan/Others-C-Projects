/*
** malloc.c for  in /home/axel/malloc_test_block/NEW
**
** Made by Axel
** Login   <axel.proust@epitech.eu>
**
** Started on  Mon Feb  6 17:37:09 2017 Axel
** Last update Sat Feb 11 16:33:56 2017 Rayan
*/

#include "list.h"

extern pthread_mutex_t thread;
extern void            *pblock;
extern t_list          *list;
extern t_list          *last;

t_list			*final_free(t_list *tmp, size_t pagesize)
{
  if (tmp == pblock && tmp == last)
    {
      sbrk(-(((tmp->size / pagesize) + 1) * pagesize));
      tmp = NULL;
      list = NULL;
      last = NULL;
    }
  else if (tmp == last && tmp->size > pagesize)
    {
      sbrk(-((tmp->size / pagesize) * pagesize));
      tmp->size = tmp->size - ((tmp->size / pagesize) * pagesize);
    }
  return (tmp);
}

void			free2(void *p)
{
  t_list		*tmp;
  t_list		*prev;
  size_t		pagesize;

  if (p == NULL)
    return ;
  tmp = list;
  prev = NULL;
  while (tmp != NULL && tmp->block != p)
    {
      prev = tmp;
      tmp = tmp->next;
    }
  if (tmp == NULL)
    return ;
  pagesize = getpagesize();
  tmp->is_free = 1;
  tmp = fusion(tmp, prev);
  tmp = final_free(tmp, pagesize);
  return ;
}

void		*realloc_check(void *ptr, size_t size)
{
  if (ptr == NULL && size == 0)
    return (NULL);
  else if (ptr == NULL)
    return (malloc2(size));
  else if (size == 0)
    {
      free2(ptr);
      return (NULL);
    }
  return (NULL);
}

void		*realloc2(void *ptr, size_t size)
{
  t_list	*tmp;
  size_t	 i;
  void		*p;

  if (ptr == NULL || size == 0)
    return (realloc_check(ptr, size));
  tmp = list;
  while (tmp != NULL && tmp->block != ptr)
    tmp = tmp->next;
  if (tmp == NULL)
    return (NULL);
  if (tmp->size < size)
    p = malloc2(size);
  else if (tmp != last)
    return (split_beetwen_block(size, tmp));
  else
    return (split_at_the_end(size, getpagesize()));
  i = -1;
  while (++i < tmp->size)
    ((char *)p)[i] = ((char *)ptr)[i];
  free2(ptr);
  return (p);
}

void*   realloc(void *ptr, size_t size)
{
  void	*p;

  pthread_mutex_lock(&thread);
  if ((long int)size < 0)
    return (NULL);
  p = realloc2(ptr, size);
  pthread_mutex_unlock(&thread);
  return (p);
}
