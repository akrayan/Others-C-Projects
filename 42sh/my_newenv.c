/*
** my_newenv.c for my_newenv in /home/vella_c/rendu/Systeme_Unix/PSU_2015_minishell2
**
** Made by VELLA CYRIL
** Login   <Cyril@epitech.net>
**
** Started on  Tue Apr  5 10:00:05 2016 VELLA CYRIL
** Last update Mon May 23 14:49:49 2016 Scaduto
*/

#include "include/minishell.h"

char	**my_add_env(char **env, char *name, char *tab)
{
  int	i;

  i = search_line(env, name);
  env[i] = my_strncat(env[i], tab, my_strlen(name) + 1);
  return (env);
}

char	**my_add_env1(char **env, char *name)
{
  int	i;

  i = search_line(env, name);
  env[i] = my_strcat(name, "=");
  return (env);
}
