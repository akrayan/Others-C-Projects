/*
** my_newenv1.c for my_newenv in /home/vella_c/rendu/Systeme_Unix/PSU_2015_minishell2
**
** Made by VELLA CYRIL
** Login   <Cyril@epitech.net>
**
** Started on  Tue Apr  5 10:05:26 2016 VELLA CYRIL
** Last update Wed Jun  1 15:27:58 2016 VELLA CYRIL
*/

#include "include/minishell.h"

char	**my_setenv2(char **env, char *tab)
{
  int	i;
  int	j;
  char	**newenv;

  i = -1;
  j = -1;

  if ((newenv = malloc(sizeof(char *) * (check_it(env) + 2))) == NULL)
    return (env);
  if (search_line(env, my_strcat(tab, "/")) != -1)
    {
      my_add_env1(env, tab);
      return (newenv);
    }
  while (env[++i] != NULL)
	{
	  j = -1;
	  newenv[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
	  while (env[i][++j] != '\0')
	    newenv[i][j] = env[i][j];
	  newenv[i][j] = '\0';
	}
  newenv[i] = malloc(my_strlen(tab) + 1);
  newenv[i] = my_strcat(tab, "=");
  newenv[i + 1] = NULL;
  return (newenv);
}

char	**my_setenv(char **env, char *name, char *content)
{
  int	i;
  int	j;
  char	**newenv;

  i = -1;
  j = -1;
  newenv = malloc(sizeof(char *) * (check_it(env) + 2));
  if (search_line(env, my_strcat(name, "/")) != -1)
    {
      newenv = my_add_env(env, name, content);
      return (newenv);
    }
  while (env[++i] != NULL)
    {
      j = -1;
      newenv[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
      while (env[i][++j] !='\0')
	newenv[i][j] = env[i][j];
      newenv[i][j] = '\0';
    }
  newenv[i] = malloc(my_strlen(name) + my_strlen(content) + 2);
  newenv[i] = my_strcat(my_strcat(name, "="), content);
  newenv[i + 1] = NULL;
  return (newenv);
}

char	**my_unsetenv(char **env, char *name)
{

  int	i;
  int	j;

  i = -1;
  j = -1;
  name = my_strcat(name, "=");
  while (env[++i] != NULL && env[++j] != NULL)
    {
      if (my_strncmp(env[i], name, my_strlen(name) - 1) == 0)
	i = i + 1;
      env[j] = env[i];
    }
  env[j] = NULL;
  return (env);
}
