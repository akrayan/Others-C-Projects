/*
** list.c for list.c in /home/Rayan/Shell/PSU_2015_minishell2
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue Mar 29 16:48:09 2016 AKKACHE Kaci
** Last update Tue Apr 12 18:27:07 2016 AKKACHE Kaci
*/

#include "include/shell.h"

t_l	*add_elem(char *s, t_l *l)
{
  t_l	*n;

  if (l != NULL)
    {
      n = malloc(sizeof(t_l));
      n->next = NULL;
      n->s = my_strdup(s);
      l->last->next = n;
      l->last = n;
    }
  else
    {
      l = malloc(sizeof(t_l));
      l->s = my_strdup(s);
      l->last = l;
      l->next = NULL;
    }
  return (l);
}

void	free_list(t_l *l)
{
  t_l	*p;

  while (l->next != NULL)
    {
      p = l;
      l->next->last = l->last;
      l = l->next;
      free(p->s);
      free(p);
    }
  free(l);
}

t_l	*sup_elem(t_l *l, int i)
{
  t_se	s;

  s.j = 0;
  s.l2 = NULL;
  s.p = l;
  while (s.j < i)
    {
      s.l2 = add_elem(s.p->s, s.l2);
      s.p = s.p->next;
      s.j++;
    }
  s.f = s.p;
  if (s.p->next != NULL)
    {
      s.p = s.p->next;
      while (s.p != NULL)
	{
	  s.l2 = add_elem(s.p->s, s.l2);
	  s.p = s.p->next;
	}
    }
  free(s.f->s);
  free(s.f);
  free_list(l);
  return (s.l2);
}

void	show_l(t_l *l)
{
  t_l	*p;

  p = l;
  while (p != NULL)
    {
      my_printf("%s\n", p->s);
      p = p->next;
    }
}

char	**l_tab(t_l *e)
{
  t_l	*p;
  int	i;
  char	**t;

  i = 0;
  p = e;
  while (p != NULL)
    {
      p = p->next;
      i++;
    }
  t = malloc(sizeof(char *) * (i + 1));
  i = 0;
  p = e;
  while (p != NULL)
    {
      t[i] = p->s;
      p = p->next;
      i++;
    }
  t[i] = NULL;
  return (t);
}
