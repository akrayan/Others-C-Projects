/*
** list.c for list.c in /home/Rayan/CPE_colle_semaine1
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue Apr 26 18:24:29 2016 AKKACHE Kaci
** Last update Tue Apr 26 18:50:17 2016 AKKACHE Kaci
*/

#include "./include/maze.h"

t_h	*add_elem(char v, t_h *h)
{
  t_h	*n;

  if ((n = malloc(sizeof(t_h))) == NULL)
    return (NULL);
  n->p = v;
  n->next = h;
  return (n);
}

t_h	*sup_elem(t_h *h)
{
  t_h	*n;

  n = h;
  h = h->next;
  free(n);
  return (h);
}
