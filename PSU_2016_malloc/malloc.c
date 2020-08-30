/*
** malloc.c for  in /home/axel/malloc3_test_block/NEW
**
** Made by Axel
** Login   <axel.proust@epitech.eu>
**
** Started on  Mon Feb  6 17:37:09 2017 Axel
** Last update Sun Feb 12 08:42:24 2017 Rayan
*/

#include "list.h"

pthread_mutex_t thread = PTHREAD_MUTEX_INITIALIZER;
void		*pblock;
t_list		*list = NULL;
t_list		*last = NULL;

void		*malloc_empty(int s, size_t pagesize)
{
  void		*pmetadata;

  if ((pmetadata = sbrk(0)) == (void *) - 1)
    return (NULL);
  pblock = pmetadata;
  if (sbrk(MULTIPLE_PAGE) == (void *) - 1)
    return (NULL);
  add_elem(s, pmetadata, (char *)pmetadata + sizeof(t_list));
  if (ALREADY_ALLOC + sizeof(t_list) + 1 <= pagesize)
    {
      add_elem(pagesize - sizeof(t_list) - ALREADY_ALLOC,
               (char *)pmetadata + ALLOC_SIZE, (char *)pmetadata
	       + sizeof(t_list) + ALLOC_SIZE);
      last->is_free = 1;
    }
  return ((char *)pmetadata + sizeof(t_list));
}

size_t		getpower(size_t s)
{
  size_t	pow;

  pow = 1;
  while (pow < s)
    pow = pow * 2;
  return (pow);
}

t_list		*find_best_block(size_t s)
{
  t_list	*ret;
  t_list	*tmp;

  ret = NULL;
  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->is_free == 1 && tmp->size >= s &&
	  (ret == NULL || ret->size < tmp->size))
	ret = tmp;
      tmp = tmp->next;
    }
  return (ret);
}

void		*malloc2(size_t s)
{
  t_list	*tmp;
  size_t       	pagesize;
  void		*ret;

  if ((long int)s < 0)
    return (NULL);
  if (s == 0)
    return (NULL);
  s = ((s / 16) + 1) * 16;
  s = s * 1100;
  tmp = list;
  while (tmp != NULL && !(tmp->is_free == 1 && tmp->size >= s))
    tmp = tmp->next;
  pagesize = getpagesize();
  if (list == NULL)
    ret = malloc_empty(s, pagesize);
  else if (tmp != NULL && tmp != last)
    ret = split_beetwen_block(s, tmp);
  else if (tmp != NULL)
    ret = split_at_the_end(s, pagesize);
  else if (tmp == NULL)
    ret = new_page(s, pagesize);
  return (ret);
}

void		*malloc(size_t s)
{
  void *p;

  pthread_mutex_lock(&thread);
  p = malloc2(s);
  pthread_mutex_unlock(&thread);
  return (p);
}
