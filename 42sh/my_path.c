/*
** my_path.c for my_path in /home/vella_c/rendu/Systeme_Unix/PSU_2015_minishell2
**
** Made by VELLA CYRIL
** Login   <Cyril@epitech.net>
**
** Started on  Mon Apr  4 14:25:30 2016 VELLA CYRIL
** Last update Wed Jun  1 10:02:21 2016 VELLA CYRIL
*/

#include "include/minishell.h"

char	**my_pwd(char **env)
{
  char	*buffer;

  if ((buffer = malloc(1024)) == NULL)
    return (NULL);
  if (getcwd(buffer, 1024) == NULL)
    return (NULL);
  env = my_setenv(env, "PWD", buffer);
  return (env);
}

char	**search_path(char **env)
{
  t_list	a;
  char		*ptr;

  a.i = -1;
  if ((a.r = open("/etc/profile", O_RDONLY)) == -1)
    return (NULL);
  while (my_strncmp((ptr = get_next_line(a.r)), "PATH", 4) != 0 && ptr != NULL);
  a.r = -1;
  while (ptr[++a.r])
    {
      if (ptr[a.r] == '"')
	a.r = a.r + 1;
      ptr[++a.i] = ptr[a.r];
  }
  ptr[a.i] = 0;
  env = my_setenv(env, "PATH", ptr + 5);
  env = my_pwd(env);
  board(env);
 return (env);
}
