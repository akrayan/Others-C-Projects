#include "list.h"

extern void     *pblock;
extern t_list   *list;
extern t_list   *last;

int     mstrlen(char *s)
{
  int   i = -1;

  while(s[++i]);
  return (i);
}


void putstr(char *str)
{
  int i = -1;

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


char    *test2(char *s)
{
  int   i;
  char  *s2;

  i = -1;
  while (s[++i] != 0);
  if ((s2 = malloc2(i + 1)) == NULL)
    printf("wsh kes tu fou !?\n");
  i = -1;
  while (s[++i] != 0)
    {
      /*putstr("\ni = ");
      my_put_nbr(i);
      putstr("\nadresse du bug = ");
      my_put_nbr((char *)s2 + i - (char*)pblock);
      putstr("\n");*/
      s2[i] = s[i];
    }
  s2[i] = 0;
  return (s2);
}

void	showlist(t_list *l)
{
  t_list	*p;
  int		i = 0;

  p = l;
  while (p != NULL)
    {
      putstr("nb        ======= ");
      my_put_nbr(i);
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

      i++;
      p = p->next;
    }
  putstr("-----------------------------------------------------------------------------\n");
}
