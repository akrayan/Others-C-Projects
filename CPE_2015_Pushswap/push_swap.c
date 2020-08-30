/*
** push_swap.c for push_swap.c in /home/Rayan/Prog Elem/CPE_2015_Pushswap
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Mon Nov 16 18:02:47 2015 AKKACHE Kaci
** Last update Sun Nov 22 16:43:32 2015 AKKACHE Kaci
*/

#include <stdlib.h>
#include <stdio.h>
#include "./push_swap.h"

t_l	*sa(t_l *list)
{
  int	a;

  a = list->first->nb;
  list->first->nb = list->first->suiv->nb;
  list->first->suiv->nb = a;
  write(1, "sa", 2);
  return (list);
}

t_l	*ra(t_l *list)
{
  list = add_elemf(list, list->first->nb);
  list = sup_elemd(list);
  write(1, "ra", 2);
  return (list);
}

t_l    *rra(t_l *list)
{
  list = add_elemd(list, list->last->nb);
  list = sup_elemf(list);
  write(1, "rra", 3);
  return (list);
}

t_c	*pa(t_c *ll)
{
  ll->la = add_elemd(ll->la, ll->lb->first->nb);
  ll->lb = sup_elemd(ll->lb);
  write(1, "pa", 2);
  return (ll);
}

t_c   *pb(t_c *ll)
{
  ll->lb = add_elemd(ll->lb, ll->la->first->nb);
  ll->la = sup_elemd(ll->la);
  write(1, "pb", 2);
  return (ll);
}
