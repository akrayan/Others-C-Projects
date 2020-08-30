/*
** my_list2.c for my_list2.c in /home/Rayan/Prog Elem/CPE_2015_Pushswap
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Wed Nov 18 14:33:06 2015 AKKACHE Kaci
** Last update Sun Nov 29 20:33:02 2015 AKKACHE Kaci
*/

#include <stdlib.h>
#include "./my_ls.h"
#include "./include/my.h"

t_lf	*add_elemv(t_lf *list, char *name)
{
  t_lf	*nv;

  list = malloc(sizeof(list));
  nv = malloc(sizeof(nv));
  nv->name = name;
  nv->index = -1;
  nv->suiv = NULL;
  list->first = nv;
  list->last = nv;
  list->t = 1;
  return (list);
}

t_lf	*add_elemf(t_lf *list, char *name, int id)
{
  t_lf	*nv;

  if (list == NULL)
    list = add_elemv(list, name);
  else
    {
      nv = malloc(sizeof(nv));
      nv->name = name;
      nv->index = id;
      nv->suiv = NULL;
      list->last->suiv = nv;
      list->last = nv;
      list->t = list->t + 1;
    }
  return (list);
}

t_lf	*sup_elemf(t_lf *list)
{
  t_lf	*p;

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

t_lf	*sup_elemd(t_lf *list)
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
