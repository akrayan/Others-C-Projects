/*
** malloc.c for malloc.c in /home/rayan/Memory/PSU_2016_malloc
**
** Made by Rayan
** Login   <raihane.akkache@epitech.net>
**
** Started on  Mon Jan 30 12:00:42 2017 Rayan
** Last update Mon Feb  6 10:37:55 2017 Rayan
*/

#include "list.h"

#define ALLOC_SIZE (sizeof(t_list) + s)
#define MULTIPLE_PAGE ((ALLOC_SIZE / pagesize) + 1) * pagesize)

void	*pblock;
t_list	*list = NULL;
t_list	*last = NULL;


/* char	*test2(char *s) */
/* { */
/*   int	i; */
/*   char	*s2; */

/*   i = -1; */
/*   while (s[++i] != 0); */
/*   if ((s2 = malloc2(i + 1)) == NULL) */
/*     printf("wsh kes tu fou !?\n"); */
/*   i = -1; */
/*   while (s[++i] != 0) */
/*     s2[i] = s[i]; */
/*   s2[i] = 0; */
/*   return (s2); */
/* } */

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

void	*malloc_metadata(void *pmetadata, int pagesize, int s)
{
  if (!((int)((((char *)pmetadata - (char *)pblock) % pagesize) + ALLOC_SIZE) < pagesize))
    {
      write(1, "Depasse pagesize\n", mstrlen("Depasse pagesize\n"));
      if (sbrk(MULTIPLE_4096) == (void *)-1)
	return (NULL);
    }
  return ((void *)2);
}

void	*malloc2(size_t s)
{
  void	*pmetadata;
  void	*pdata;
  void	*pnblock;
  int	pagesize = getpagesize();

  if (list == NULL)
    {
      if ((pmetadata = sbrk(0)) == (void *)-1) /*sbrk(0)*/
	return (NULL);
      pblock = pmetadata; /* global = point de depart */
      if (sbrk((MULTIPLE_4096 == (void *)-1) /* alloc du multiple e 4096p plus proche*/
	return (NULL);
      add_elem(s, pmetadata, (char *)pmetadata + sizeof(t_list)); /* ajout de l'emplacement dans la liste.*/
        }
  else
    {
      pmetadata = (char *)last->block + last->size;
      if (malloc_metadata(pmetadata, pagesize, s) == NULL)/* pnblock sert a rien */
	return (NULL);
      add_elem(s, pmetadata, (char *)pmetadata + sizeof(t_list)); /* ajout de l'emplacement dans la liste.*/
    }
  return ((char *)pmetadata + sizeof(t_list)); /* return la pos ?*/
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
      write(1, "bite\n", strlen("bite\n"));
      my_put_nbr(tmp->size);*/
  if ((sbrk(-tmp->size)) == (void*) -1)
    write(1, "chatte\n", mstrlen("chatte\n"));
  tmp->is_free = 1;
  tmp->block = NULL;
  p = NULL;
  //brk(last->block + last->size); /* /!\ ATTENTION !!!! */
}

int main()
{
  char       *str;
  char       *tab[100];
  int        k = 1;
  int        i = 0;
  t_list	*tmp;

  while (i++ < 100)
    {
      tab[i] = malloc2(++k);
      memset(tab[i], 'e', k - 1);
      tab[i][k] = 0;
    }
  while (--i > 0)
    {
      write(1, tab[i], k--);
      free2(tab[i]);
      write(1, "\n", 1);
    }
  tmp = list;
  i = 0;
  while (tmp && tmp != last)
    {
      my_put_nbr(i);
      /* printf("%p\n", tmp->block); */
      write (1, "\n", mstrlen("\n"));
      tmp = tmp->next;
      i++;
    }
}

/* int	main() */
/* { */
/*   int i; */
/*   char	*s; */

/*   i = -1; */
/*   while (++i < 1000) */
/*     { */
/*       s = test2("Raihane la folle\n"); */
/*       write(1, s, strlen(s)); */
/*     } */
/*   free2(s); */
/*   write(1, s, strlen(s)); */
/* } */
