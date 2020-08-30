/*
** affichage.c for  in /home/axel/rendu/malloc_last/PSU_2016_malloc
**
** Made by Axel
** Login   <axel.proust@epitech.eu>
**
** Started on  Sat Feb 11 15:56:55 2017 Axel
** Last update Sun Feb 12 08:40:36 2017 Rayan
*/

# include "list.h"

extern void     *pblock;
extern t_list   *list;
extern t_list   *last;

int     mstrlen(char *s)
{
  int   i;

  i = -1;
  while (s[++i]);
  return (i);
}

void putstr(char *str)
{
  int i;

  i = -1;
  while (str[++i])
    my_putchar(str[i]);
}

void     my_putchar(char c)
{
  write(1, &c, 1);
}

void   my_put_nbr(int nb)
{
  int   mod;

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

void	show_alloc_mem()
{
  t_list	*p;

  p = list;
  putstr("break : ");
  put_hexa((long)sbrk(0));
  putstr("\n");
  while (p != NULL)
    {
      if (p->is_free == 0)
	{
	  put_hexa((long)p->block);
	  putstr(" - ");
	  put_hexa((long)p->block + p->size);
	  putstr(" : ");
	  my_put_nbr((long)p->size);
	  putstr(" bytes\n");
	}
      p = p->next;
    }
}
