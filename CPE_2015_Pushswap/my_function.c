/*
** my_function.c for my_function.c in /home/Rayan/Prog Elem/CPE_2015_Pushswap
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Thu Nov 19 05:16:26 2015 AKKACHE Kaci
** Last update Sun Nov 22 16:45:48 2015 AKKACHE Kaci
*/

#include <stdlib.h>
#include "./push_swap.h"
#include "./include/my.h"

t_l	*my_getlist(t_l *list, char **param)
{
  int	i;

  i = 1;
  while (param[i] != NULL)
    {
      list = add_elemf(list, my_getnbr(param[i]));
      i = i + 1;
    }
  return (list);
}

int	check_list(t_l *list)
{
  t_l	*p;
  int	min;

  p = list->first;
  min = p->nb;
  while (p != NULL)
    {
      if (min > p->nb)
	return (0);
      else
	min = p->nb;
      p = p->suiv;
    }
  return (1);
}

int	check_idx(t_l *list)
{
  t_l	*p;
  int	i;
  int	idx;
  int	min;

  p = list->first;
  min = p->nb;
  i = 1;
  idx = 1;
  while (p != NULL)
    {
      if (p->nb < min)
	{
	  min = p->nb;
	  idx = i;
	}
      p = p->suiv;
      i = i + 1;
    }
  return (idx);
}

t_l	*putlb(t_c *ll)
{
  while (ll->lb != NULL)
    {
      ll = pa(ll);
      if (ll->lb != NULL)
	write(1, " ", 1);
    }
  return (ll->la);
}

t_l	*push_swap5(t_c *ll)
{
  int	idx;
  int	r;

  r = check_list(ll->la);
  while (ll->la->t > 1 && r == 0)
    {
      idx = check_idx(ll->la);
      if (idx == 1)
	ll = pb(ll);
      else if (idx == 2)
	ll->la = sa(ll->la);
      else if (idx <= (ll->la->t / 2) + 1)
	ll->la = ra(ll->la);
      else if (idx > (ll->la->t / 2) + 1)
	ll->la = rra(ll->la);
      write(1, " ", 1);
      r = check_list(ll->la);
    }
  ll->la = putlb(ll);
  return (ll->la);
}
