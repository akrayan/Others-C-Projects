/*
** read.c for read.c in /home/Rayan/Systeme_Unix/PSU_2015_minishell1
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Jan 24 19:21:14 2016 AKKACHE Kaci
** Last update Sun Jan 24 22:14:48 2016 AKKACHE Kaci
*/

#include "./mini_shell.h"

int	ex_cmd(char *cmd, char **env)
{
  char	**arg;
  char	*s;
  int	i;
  int	r;

  i = 0;
  r = -1;
  arg = tab_for_shell(cmd);
  if ((is_e(arg[0], "cd") + is_e(arg[0], "env")
       + is_e(arg[0], "setenv") + is_e(arg[0], "unsetenv")
       + is_e(arg[0], "exit")) == 1)
    return (0);
  ex_bin(arg, env);
}

char	*new_copy(char *str)
{
  int	i;
  char	*copy;

  i = 0;
  while (str[i++] != '\n');
  copy = malloc(sizeof(char) * i);
  i = 0;
  while (str[i] != '\n')
    {
      copy[i] = str[i];
      i = i + 1;
    }
  copy[i] = '\0';
  return (copy);
}

char	*read_st(const int fd)
{
  char	buffer[4096];
  char	*result;
  int	i;
  int	ret;

  i = 0;
  ret = read(fd, buffer, 4096);
  result = new_copy(buffer);
  return (result);
}

int	nb_arg(char **arg)
{
  int	i;

  i = 0;
  while (arg[i] != NULL)
    i++;
  return (i);
}

int	s_wt(char **t)
{
  int	i;

  i = 0;
  while (t[i] != NULL)
    {
      my_putstr(t[i]);
      my_putstr("\n");
      i = i + 1;
    }
}
