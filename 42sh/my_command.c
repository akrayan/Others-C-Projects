/*
** my_command.c for  in /home/scaduto/PSU_2015_42sh
**
** Made by Scaduto
** Login   <scaduto@epitech.net>
**
** Started on  Mon May 30 09:40:54 2016 Scaduto
** Last update Mon May 30 09:41:05 2016 Scaduto
*/

#include "include/minishell.h"

char	**make_builtins2(char **env, char **cmd)
{
  if (my_strncmp(*cmd, "cd", 2) == 0)
    {
      if (check_it(cmd) > 2)
	{
	  my_putstr("Too many arguments with cd\n");
	  return (env);
	}
      env = my_cd((cmd[1]), env);
    }
  else if (my_strcmp("env", *cmd) == 0)
    board(env);
  return (env);
}

char	**make_builtins(char **env, char **cmd)
{
  if (my_strncmp(*cmd, "setenv", 6) == 0)
    {
      if (check_it(cmd) > 3 || check_it(cmd) == 1)
	{
	  my_putstr("Too many arguments with setenv, USAGE : setenv [Name] [Value]\n");
	  return (env);
	}
      if (check_it(cmd) == 2)
	env = my_setenv2(env, cmd[1]);
      else
	env = my_setenv(env, cmd[1], cmd[2]);
    }
  else if (my_strncmp(*cmd, "unsetenv", 8) == 0)
    {
      if (check_it(cmd) < 2)
	{
	  my_putstr("Too many arguments with unsetev\n");
	  return (env);
	}
      env = my_unsetenv(env, cmd[1]);
    }
  env = make_builtins2(env, cmd);
  return (env);
}
