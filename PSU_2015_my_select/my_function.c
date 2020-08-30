/*
** my_function.c for my_function.c in /home/Rayan/Systeme Unix/PSU_2015_my_select
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue Dec  1 23:40:29 2015 AKKACHE Kaci
** Last update Sun Dec 13 17:01:08 2015 AKKACHE Kaci
*/

#include <stdlib.h>
#include "./include/my.h"
#include "my_select.h"

int	lenmax(char **t)
{
  int	k;
  int	i;

  k = 0;
  i = 1;
  while (t[i] != NULL)
    {
      if (k < my_strlen(t[i]))
	k = my_strlen(t[i]);
      i = i + 1;
    }
  return (k);
}

t_dbl	*rra(t_dbl *list)
{
  list->first = list->first->prev;
  list->last = list->last->prev;
}

t_dbl	*select_e(t_dbl *l, int indx)
{
  int	i;

  i = 0;
  while (i < indx)
    {
      ra(l);
      i = i + 1;
    }
  if (l->first->select == 1)
    l->first->select = 0;
  else
    l->first->select = 1;
  i = 0;
  while (i < indx)
    {
      rra(l);
      i = i + 1;
    }
}

t_dbl	*crsol(t_dbl *l, int indx, int b)
{
  int	i;

  i = 0;
  while (i < indx)
    {
      ra(l);
      i = i + 1;
    }
  l->first->crson = b;
  i = 0;
  while (i < indx)
    {
      rra(l);
      i = i + 1;
    }
}

t_dbl	*delete(t_dbl *l, int indx)
{
  int	i;

  i = 0;
  while (i < indx)
    {
      ra(l);
      i = i + 1;
    }
  PopFront(l);
  l->first->prev = l->last;
  l->last->next = l->first;
  i = 0;
  while (i < indx)
    {
      rra(l);
      i = i + 1;
    }
}
