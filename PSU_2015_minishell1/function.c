/*
** function.c for function.c in /home/Rayan/Systeme_Unix/PSU_2015_minishell1
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Jan 24 21:16:45 2016 AKKACHE Kaci
** Last update Sun Jan 24 22:40:49 2016 AKKACHE Kaci
*/

#include "mini_shell.h"

int	ex_norm(char **arg, char **env)
{
  int	i;
  int	r;

  r = 0;
  i = 0;
  while (r == 0 && arg[0][i] != '\0')
    {
      if (arg[0][i] == '/')
	r = 1;
      i++;
    }
  if (r == 1)
    {
      if (access(arg[0], F_OK) == 0)
	execve(arg[0], arg, env);
      my_putstr("commande inexistante\n");
      kill(getpid(), SIGINT);
    }
}

char	*strcat2(char *s1, char *s2)
{
  char	*res;
  int	i;
  int	j;

  i = 0;
  j = 0;
  res = malloc(my_strlen(s1) + my_strlen(s2) + 1);
  while (i < my_strlen(s1))
    {
      res[i] = s1[i];
      i++;
    }
  while (j < my_strlen(s2))
    {
      res[i] = s2[j];
      i++;
      j++;
    }
  res[i] = '\0';
  return (res);
}

int	is_e(char *s1, char *s2)
{
  int	i;
  int	r;

  r = 1;
  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && r == 1)
    {
      if (s1[i] != s2[i])
	r = 0;
      i++;
    }
  if ((s1[i] == '\0' && s2[i] != '\0') || (s1[i] != '\0' && s2[i] == '\0'))
    r = 0;
  return (r);
}

int	is_ee(char *s1, char *s2)
{
  int	i;
  int	r;

  r = 1;
  i = 0;
  while (s1[i] != '=' && s2[i] != '\0' && r == 1)
    {
      if (s1[i] != s2[i])
	r = 0;
      i++;
    }
  if ((s1[i] == '=' && s2[i] != '\0')
      || (s1[i] != '=' && s2[i] == '\0'))
    r = 0;
  return (r);
}

int	ex_bin(char **arg, char **env)
{
  char	**bin;
  char	*s;
  int	i;
  int	r;

  i = 0;
  r = -1;
  ex_norm(arg, env);
  bin = get_path(env);
  while (bin[i] != NULL && r == -1)
    {
      s = strcat2(strcat2(bin[i], "/"), arg[0]);
      if (access(s, F_OK) == 0)
	execve(s, arg, env);
      i = i + 1;
    }
  if (r == -1)
    {
      my_putstr("commande inexistante\n");
      kill(getpid(), SIGINT);
    }
}
