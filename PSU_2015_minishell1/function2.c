/*
** function2.c for function2.c in /home/Rayan/Systeme_Unix/PSU_2015_minishell1
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Jan 24 22:08:19 2016 AKKACHE Kaci
** Last update Sun Jan 24 22:28:31 2016 AKKACHE Kaci
*/

#include "mini_shell.h"

char	**add_elem(char **t, char *s)
{
  int	i;
  char	**r;

  i = 0;
  r = malloc(sizeof(char *) * (nb_arg(t) + 2));
  while (t[i] != NULL)
    {
      r[i] = t[i];
      i++;
    }
  r[i] = s;
  r[i + 1] = NULL;
  return (r);
}

char	**sup_elem(char **t, int k)
{
  int	i;
  int	j;
  char	**r;

  i = 0;
  j = 0;
  r = malloc(sizeof(char *) * (nb_arg(t)));
  while (i < k)
    {
      r[i] = t[j];
      i++;
      j++;
    }
  j++;
  while (t[j] != NULL)
    {
      r[i] = t[j];
      i++;
      j++;
    }
  r[i] = NULL;
  return (r);
}

char	**s_env2(char **env, char **arg, int r)
{
  if (r == 0)
    {
      if (nb_arg(arg) > 2)
	env = (add_elem(env, strcat2(strcat2(arg[1], "="), arg[2])));
      else
	env = (add_elem(env, strcat2(arg[1], "=")));
    }
  return (env);
}

char	**s_env(char **env, char **arg)
{
  int	i;
  int	r;

  if (nb_arg(arg) > 3)
    my_putstr("trop d'argument pour setenv\n");
  i = 0;
  r = 0;
  while (r == 0 && env[i] != NULL)
    {
      if ((r = is_ee(env[i], arg[1])) == 1)
	{
	  if (nb_arg(arg) > 2)
	    env[i] = strcat2(strcat2(arg[1], "="), arg[2]);
	  else
	    env[i] = strcat2(arg[1], "=");
	}
      i = i + 1;
    }
  env = s_env2(env, arg, r);
  return (env);
}

char	**us_env(char **env, char **arg)
{
  int	i;
  int	j;
  int	r;

  if (nb_arg(arg) > 1)
    {
      j = 1;
      while (arg[j] != NULL)
	{
	  i = 0;
	  r = 0;
	  while (r == 0 && env[i] != NULL)
	    {
	      if ((r = is_ee(env[i], arg[j])) == 1)
		env = sup_elem(env, i);
	      i = i + 1;
	    }
	  j = j + 1;
	}
    }
  else
    my_putstr("pas assez d'argument pour unsetenv\n");
  return (env);
}
