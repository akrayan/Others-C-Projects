/*
** my_cd.c for my_cd in /home/vella_c/rendu/Systeme_Unix/PSU_2015_minishell2
**
** Made by VELLA CYRIL
** Login   <Cyril@epitech.net>
**
** Started on  Tue Mar 29 17:02:09 2016 VELLA CYRIL
** Last update Wed Jun  1 15:15:08 2016 VELLA CYRIL
*/

#include "include/minishell.h"

char	**home(char **env)
{
  int	i;
  int	j;

  i = search_line(env, "HOME");
  if (chdir(env[i] + 5) == -1)
    return (env);
  j = search_line(env, "PWD");
  env = my_setenv(env, "OLDPWD", env[j] + 4);
  env = my_setenv(env, "PWD", env[i] + 5);
  return (env);
}

char	**return_back(char **env)
{
  int	i;
  int	j;
  char	*ptr;

  ptr = (NULL);
  i = search_line(env, "OLDPWD");
  if (chdir(env[i] + 7) == -1)
    return (env);
  j = search_line(env, "PWD");
  env[i] = my_strcat("PWD=", env[i] + 7);
  ptr = my_strcpy(ptr, env[i]);
  env[j] = my_strcat("OLDPWD=", env[i] + 4);
  env[i] = env[j];
  env[j] = ptr;
  return (env);
}

char	**go_somewhere(char **env, char *pathname)
{
  int	i;
  char	*buffer;

  i = 0;
  i = search_line(env, "PWD");
  env = my_setenv(env, "OLDPWD", env[i] + 4);
  if (chdir(pathname) == -1)
    {
      my_putstr("cd: aucun fichier ou dossier de ce type\n");
      return (env);
    }
  i = search_line(env, "PWD");
  if ((buffer = malloc(1024)) == NULL)
    return (env);
  if (getcwd(buffer, 1024) == NULL)
    return (env);
  env[i] = my_strcat("PWD=", buffer);
  return (env);
}

char	**my_cd(char *pathname, char **env)
{
  if (pathname == NULL)
    env = home(env);
  else if (my_strcmp(pathname, "-") == 0)
    env = return_back(env);
  else
    env = go_somewhere(env, pathname);
  return (env);
}
