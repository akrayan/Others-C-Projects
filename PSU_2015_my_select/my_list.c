/*
** my_list.c for my_list.c in /home/Rayan/Systeme_Unix/PSU_2015_my_select
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Dec 13 16:49:29 2015 AKKACHE Kaci
** Last update Sun Dec 13 17:19:42 2015 AKKACHE Kaci
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_select.h"

t_dbl	*ra(t_dbl *list)
{
  list->first = list->first->next;
  list->last = list->last->next;
}

void	Init(t_dbl *l)
{
  l->first = NULL;
  l->last = NULL;
}

void	PushBack(t_dbl *l, char *val, int crson, int select)
{
  t_e   *nouv;

  nouv = malloc(sizeof(t_e));
  if (!nouv)
    exit(EXIT_FAILURE);
  nouv->select = select;
  nouv->crson = crson;
  nouv->val = val;
  nouv->prev = l->last;
  nouv->next = NULL;
  if (l->last)
    l->last->next = nouv;
  else
    {
      l->first = nouv;
      l->t = 0;
    }
  l->t = l->t + 1;
  l->last = nouv;
}

char	*PopFront(t_dbl *l)
{
  t_e	*tmp;
  char	*val;

  tmp = l->first;
  if (!tmp)
    return ("error");
  val = tmp->val;
  l->first = tmp->next;
  if (l->first)
    l->first->prev = NULL;
  else
    l->last = NULL;
  free (tmp);
  l->t = l->t - 1;
  return val;
}

void	getlist(t_dbl *list, char **t)
{
  int	i;

  i = 1;
  Init(list);
  while (t[i])
    {
      PushBack(list, t[i], 0, 0);
      i = i + 1;
    }
  list->first->prev = list->last;
  list->last->next = list->first;
}
