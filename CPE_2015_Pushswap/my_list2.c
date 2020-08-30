/*
** my_list2.c for my_list2.c in /home/Rayan/Prog Elem/CPE_2015_Pushswap
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Wed Nov 18 14:33:06 2015 AKKACHE Kaci
** Last update Sun Nov 22 16:59:17 2015 AKKACHE Kaci
*/

#include <stdlib.h>
#include "./push_swap.h"
#include "./include/my.h"

t_l	*add_elemv(t_l *list, int nb)
{
  t_l	*nv;

  list = malloc(sizeof(list));
  nv = malloc(sizeof(nv));
  nv->nb = nb;
  nv->suiv = NULL;
  list->first = nv;
  list->last = nv;
  list->t = 1;
  return (list);
}

t_l    *add_elemd(t_l *list, int nb)
{
  t_l  *nv;

  if (list == NULL)
    list = add_elemv(list, nb);
  else
    {
      nv = malloc(sizeof(nv));
      nv->nb = nb;
      nv->suiv = list->first;
      list->first = nv;
      list->t = list->t + 1;
    }
  return (list);
}

t_l    *add_elemf(t_l *list, int nb)
{
  t_l  *nv;

  if (list == NULL)
    list = add_elemv(list, nb);
  else
    {
      nv = malloc(sizeof(nv));
      nv->nb = nb;
      nv->suiv = NULL;
      list->last->suiv = nv;
      list->last = nv;
      list->t = list->t + 1;
    }
  return (list);
}

t_l	*sup_elemf(t_l *list)
{
  t_l *p;

  if (list == NULL || list->t == 1)
    return (NULL);
  else
    {
      p = list->first;
      while (p->suiv != list->last)
	p = p->suiv;
      p->suiv = NULL;
      list->last = p;
      list->t = list->t - 1;
      return (list);
    }
}

t_l    *sup_elemd(t_l *list)
{
  if (list == NULL || list->t == 1)
    return (NULL);
  else
    {
      list->first = list->first->suiv;
      list->t = list->t - 1;
      return (list);
    }
}
