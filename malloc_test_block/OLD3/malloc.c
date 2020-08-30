/*
** malloc.c for malloc.c in /home/rayan/Memory/PSU_2016_malloc
**
** Made by Rayan
** Login   <raihane.akkache@epitech.net>
**
** Started on  Mon Jan 30 12:00:42 2017 Rayan
** Last update Mon Feb  6 15:06:02 2017 Rayan
*/

#include "list.h"

#define ALLOC_SIZE (sizeof(t_list) + s)
#define MULTIPLE_PAGE (((ALLOC_SIZE / pagesize) + 1) * pagesize)

void	*pblock;
t_list	*list = NULL;
t_list	*last = NULL;


int	mstrlen(char *s)
{
  int	i = -1;

  while(s[++i]);
  return (i);
}


int	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_put_nbr(int nb)
{
  int	mod;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb >= 0)
    {
      if (nb >= 10)
	{
	  mod = (nb % 10);
	  nb = (nb - mod) / 10;
	  my_put_nbr(nb);
	  my_putchar(48 + mod);
	}
      else
	my_putchar(48 + nb % 10);
    }
}


void	*malloc_metadata(void *pmetadata, void *pnblock, int pagesize, int s)
{
  if (  !((int)((((char *)pmetadata - (char *)pblock) % pagesize) + ALLOC_SIZE) < pagesize) )
    {
      if (sbrk(MULTIPLE_PAGE) == (void *)-1)
	return (NULL);
    }
  return ((void *)2);
}

void	*malloc_empty(void *pmetadata, int s, int pagesize)
{
  if ((pmetadata = sbrk(0)) == (void *)-1)
    return (NULL);

  pblock = pmetadata;

  if (sbrk(MULTIPLE_PAGE) == (void *)-1)
    return (NULL);

  my_put_nbr(pmetadata);
  my_putchar('\n');
  my_put_nbr((char *)pmetadata + sizeof(t_list));
  my_putchar('\n');
  my_putchar('\n');
  add_elem(s, pmetadata, (char *)pmetadata + sizeof(t_list));
  if ((pmetadata - pblock) % pagesize != 0)
    {
      add_elem(pagesize - (((char *)pmetadata + s - (char *)pblock) % pagesize),
	       (char *)pmetadata + s, (char *)pmetadata + sizeof(t_list) + s);
      last->is_free = 1;
    }
  return (pmetadata);
}

void	*malloc2(size_t s)
{
  void		*pmetadata;
  void		*pdata;
  void		*pnblock;
  t_list	*tmp;
  int		pagesize = getpagesize();


  if (list == NULL)
    {
      if ((pmetadata = malloc_empty(pmetadata, s, pagesize)) == NULL)
	return (NULL);

    }
  else
    {
      tmp = list;
      while (tmp != NULL && !(tmp->is_free == 1 && tmp->size >= s))
	{
	  tmp = tmp->next;
	}
      if (tmp != NULL)
	{
	  pmetadata = tmp->block;
	  if (tmp->size > s && tmp != last)
	    add_between_elem((char *)tmp->next - (char *)pmetadata,
			     (char *)pmetadata + s, (char *)pmetadata + s + sizeof(t_list), tmp); /* ARRENTION /!\ */
	  else if (tmp->size > s && tmp->size > sizeof(t_list)) /* /!\ A OPTIMERISER /!\*/
	    {
	      add_elem(pagesize - ((int)pmetadata % pagesize),
		       (char *)pmetadata + s, (char *)pmetadata + s + sizeof(t_list));
	      tmp->next->is_free = 1;
	    }
	  tmp->size = s;
	  tmp->is_free = 0;
	  return (pmetadata);
	}
      else
	{
	  pmetadata = (char *)last->block + last->size;
	  if (malloc_metadata(pmetadata, pnblock, pagesize, s) == NULL)
	    return (NULL);
	  add_elem(s, pmetadata, (char *)pmetadata + sizeof(t_list));
	  if ((pmetadata - pblock) % pagesize != 0)
	    {
	      add_elem(pagesize - (((char *)pmetadata + s - (char *)pblock) % pagesize),
		       (char *)pmetadata + s, (char *)pmetadata + sizeof(t_list) + s);
	      last->is_free = 1;
	    }
	}
    }
  return ((char *)pmetadata + sizeof(t_list));
}

void		free2(void *p)
{
  t_list	*tmp;

  if (p == NULL)
    return ;
  tmp = list;
  while (tmp != NULL && tmp->block != p)
    tmp = tmp->next;
  if (tmp == NULL)
    return ;

  /*  if ((brk(p + tmp->size)) == -1)
    write(1, "bite\n", mstrlen("bite\n"));
    my_put_nbr(tmp->size);*/
  if ((sbrk(-tmp->size)) == (void*) -1)
    write(1, "chatte\n", mstrlen("chatte\n"));
  tmp->is_free = 1;
  tmp->block = NULL;
  p = NULL;
  //brk(last->block + last->size); /* /!\ ATTENTION !!!! */
}

char	*test2(char *s)
{
  int	i;
  char	*s2;

  i = -1;
  while (s[++i] != 0);
  if ((s2 = malloc2(i + 1)) == NULL)
    printf("wsh kes tu fou !?\n");
  i = -1;
  while (s[++i] != 0)
    s2[i] = s[i];
  s2[i] = 0;
  return (s2);
}

int	main()
{
  int i;
  char	*s;

  i = -1;
  while (++i < 10)
    {
      s = test2("raihanekklklklk\n");
      write(1, s, mstrlen(s));
    }

}
