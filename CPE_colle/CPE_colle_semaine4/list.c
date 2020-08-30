/*
** list.c for list.c in /home/Rayan/Colle/CPE_colle_semaine4
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue May 17 18:16:11 2016 AKKACHE Kaci
** Last update Tue May 17 19:33:28 2016 AKKACHE Kaci
*/

#include "./include/poke.h"

int	list_len(t_l *l)
{
  int	i;
  t_l	*p;

  p = l;
  while (p != NULL)
    {
      i++;
      p = p->next;
    }
  return (i);
}

t_l	*add_elem(t_l *l, t_poke poke)
{
  t_l	*n;

  if ((n = malloc(sizeof(t_l))) == NULL)
    return (NULL);
  n->next = NULL;
  n->p = poke;
  if (l == NULL)
    {
      n->last = n;
      return (n);
    }
  l->last->next = n;
  l->last = n;
  return (l);
}
