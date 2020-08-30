/*
** env.c for env.c in /home/Rayan/test/shell
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Apr 10 04:07:00 2016 AKKACHE Kaci
** Last update Tue Apr 12 19:25:07 2016 AKKACHE Kaci
*/

#include "include/shell.h"

t_l	*g_e(char **t, t_l *l)
{
  int	i;

  l = NULL;
  while (t[i] != NULL)
    {
      l = add_elem(t[i], l);
      i++;
    }
  return (l);
}

t_l	*s_e2(t_l *env, char **a)
{
  t_l	*p;
  t_l	*env2;

  p = env;
  env2 = NULL;
  while (my_strncmp(p->s, a[1], my_strlen(a[1]) - 1) != 0)
    {
      env2 = add_elem(p->s, env2);
      p = p->next;
    }
  if (a[2] == NULL)
    env2 = add_elem(sc(a[1], "\0", '='), env2);
  else
    env2 = add_elem(sc(a[1], a[2], '='), env2);
  p = p->next;
  while (p != NULL)
    {
      env2 = add_elem(p->s, env2);
      p = p->next;
    }
  free_list(env);
  return (env2);
}

t_l	*s_e(t_l *env, char *arg)
{
  t_l	*p;
  char	**a;

  a = s_t_w(arg, ' ');
  if (a[1] == NULL)
    {
      show_l(env);
      return (env);
    }
  p = env;
  while (p != NULL && my_strncmp(p->s, a[1], my_strlen(a[1]) - 1) != 0)
    p = p->next;
  if (p == NULL && a[2] == NULL)
    env = add_elem(sc(a[1], "\0", '='), env);
  else if (p == NULL)
    env = add_elem(sc(a[1], a[2], '='), env);
  else
    env = s_e2(env, a);
  return (env);
}

t_l	*us_e(t_l *env, char *arg)
{
  t_l	*p;
  int	i;
  int	j;
  char	**a;

  i = 1;
  a = s_t_w(arg, ' ');
  while (a[i] != NULL)
    {
      p = env;
      j = 0;
      while (p != NULL && my_strncmp(p->s, a[i], my_strlen(a[i]) - 1) != 0)
	{
	  p = p->next;
	  j++;
	}
      if (p != NULL)
	env = sup_elem(env, j);
      i++;
    }
  if (i == 1)
    my_printf("unsetenv: Too few arguments.\n");
  return (env);
}
