/*
** malloc.c for  in /home/axel/malloc_test_block/NEW
**
** Made by Axel
** Login   <axel.proust@epitech.eu>
**
** Started on  Mon Feb  6 17:37:09 2017 Axel
** Last update Thu Feb  9 12:12:27 2017 Axel
*/

#include "list.h"

#define ALLOC_SIZE (sizeof(t_list) + s)
#define MULTIPLE_PAGE (((ALLOC_SIZE / pagesize) + 1) * pagesize)
#define ALREADY_ALLOC (((char *)last->block - (char *)pblock + last->size) % pagesize)

void		*pblock;
t_list		*list = NULL;
t_list		*last = NULL;

void		*split_at_the_end(int s, size_t pagesize)
{
  size_t	size;
  void		*ret;
  
  last->is_free = 0;
  size = last->size;
  last->size = s;
  ret = last->block;
  if ((((char *)last->block - (char *)pblock) % pagesize) + ALLOC_SIZE + sizeof(t_list) + 1 <= pagesize)
    {
      add_elem(size - ALLOC_SIZE,
  	       (char *)last + ALLOC_SIZE, (char *)last->block + ALLOC_SIZE);
      last->is_free = 1;
    }
  return (ret);
}

void		*split_beetwen_block(int s, t_list *tmp)
{
  if ((char *)tmp->block - (char *)pblock + ALLOC_SIZE + 1 <= tmp->size)
    {
      tmp->size = s;
      add_between_elem((char *)(tmp->next) - (char *)(tmp->block) - ALLOC_SIZE,
		       (char *)tmp + ALLOC_SIZE, (char *)(tmp->block) + ALLOC_SIZE, tmp);
    }
  tmp->is_free = 0;
  return (tmp->block);
}


void		*new_page(int s, size_t pagesize)
{
  void		*ret;
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
      add_elem(s, (char *)last->block + last->size, (char *)last->block + last->size + sizeof(t_list));
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

void		*malloc_empty(int s, size_t pagesize)
{
  void		*pmetadata;
  
  if ((pmetadata = sbrk(0)) == (void *)-1)
    return (NULL);
  pblock = pmetadata;
  if (sbrk(MULTIPLE_PAGE) == (void *)-1)
    return (NULL);
  add_elem(s, pmetadata, (char *)pmetadata + sizeof(t_list));
  if (ALREADY_ALLOC + sizeof(t_list) + 1 <= pagesize)
    {
      add_elem(pagesize - sizeof(t_list) - ALREADY_ALLOC,
               (char *)pmetadata + ALLOC_SIZE, (char *)pmetadata + sizeof(t_list) + ALLOC_SIZE);
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

void		*malloc(size_t s)
{
  t_list	*tmp;
  size_t       	pagesize;
  void		*ret;

  //s = getpower(s);
  
  s = ((s / 16) + 1) * 16;
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
    {
      ret = new_page(s, pagesize);
    }
  //  showlist(list);
  return (ret);
}

void		free(void *p)
{
  t_list	*tmp;
  t_list	*prev;

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
    }
  tmp->is_free = 1;
  if (tmp == pblock)
    {
      brk((char*)(tmp->block) + getpagesize());
      tmp->size = getpagesize();
    }
  return ;
}

void		*realloc(void *ptr, size_t size)
{
  t_list	*tmp;
  size_t	 i = 0;
  void		*p;

  if (ptr == NULL)
    {
      return (malloc(size));
    }
  else if (size == 0)
      return (sbrk(0));
  tmp = list;
  while (tmp != NULL && tmp->block != ptr)
      tmp = tmp->next;
  if (!tmp)
    {
      return (malloc(size));
    }
  if (tmp->size <= size)
    {
      p = malloc(size);
    }
  p = malloc(size);
  while (i < size)
    {
      ((char *)p)[i] = ((char *)ptr)[i];
      i++;
    }
  free(ptr);
  return (p);
}

void	affpoint(void *ptr)
{
  t_list *p;
  
  p = list;
  while (p != NULL && p->block != ptr)
    p = p->next;
  putstr("+++++++++++++++++++++++++++++++++++++\n");
  if (p != NULL)
    {
      putstr("\npmetadata ======= ");
      my_put_nbr((char *)p - (char *)pblock);
      putstr("\npdata     ======= ");
      my_put_nbr((char*)(p->block) - (char*)pblock);
      putstr("\nsize      ======= ");
      my_put_nbr(p->size);
      putstr("\nis_free   ======= ");
      my_put_nbr(p->is_free);
      putstr("\npnext     ======= ");
      my_put_nbr((char *)p->block + p->size - (char *)pblock);
      my_putchar('\n');
      my_putchar('\n');
    }
  
}

int		 main()
{
  char		*str;
  int k = -1;
  /* int i = 0; */
  while (42)
    {
      write(1, "\n", 1);
      my_put_nbr(++k);
      str = malloc2(k);
      memset(str, 0, k);
      if (random() % 2)
	free2(str);
      str = realloc2(str, k + 2);
    }
  /* write(1, "\n", 1); */
  /* affpoint(str); */
  /* write(1, "memset\n", strlen("memset\n")); */
  /* showlist(list); */
  /* write(1, "memset2\n", strlen("memset2\n")); */
  /* i += k; */
  /* my_put_nbr(i); */
  /*  s = test2("fluuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuflu\n");
  write(1, s, mstrlen(s));
  s = realloc2(s, 34);
  write(1, s, mstrlen(s));
  s = test2("blah\n");
  write(1, s, mstrlen(s));
  s = test2("op\n");
  write(1, s, mstrlen(s));
  showlist(list);
  free2(s);
  showlist(list);*/
  /*while (++i < 3)
    {
    showlist(list);
      
      write(1, s, mstrlen(s));
      showlist(list);
      free2(s);
      }
      showlist(list);*/
}

  /* str = malloc2(4096); */
  /* memset(str, 0, 4096); */
  /* showlist(list); */
  /* str = malloc2(3000); */
  /* showlist(list); */
  /* str = malloc2(4096); */
  /* memset(str, 0, 4096); */
  /* showlist(list); */
  /* str = malloc2(3000); */
  /* showlist(list); */
