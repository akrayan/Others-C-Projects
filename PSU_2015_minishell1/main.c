/*
** main.c for main.c in /home/Rayan/Systeme_Unix/PSU_2015_minishell1
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Wed Jan 20 23:13:08 2016 AKKACHE Kaci
** Last update Sun Jan 24 22:52:29 2016 AKKACHE Kaci
*/

#include "./mini_shell.h"

char	*cp_dump(char *s)
{
  char	*r;
  int	i;

  i = 5;
  r = malloc(my_strlen(s));
  while (s[i] != '\0')
    {
      r[i - 5] = s[i];
      i = i + 1;
    }
  r[i - 5] = '\0';
  return (r);
}

int	cd(char **arg, char **env)
{
  int	i;
  int	r;
  char	*s1;

  i = 0;
  r = 0;
  if (nb_arg(arg) > 1)
    chdir(arg[1]);
  else
    {
      while (r == 0 && env[i] != NULL)
	{
	  if ((r = is_ee(env[i], "HOME")) == 1)
	    chdir(cp_dump(env[i]));
	  i = i + 1;
	}
    }
}

char	**process_pere(char **env, char *s)
{
  char	**arg;

  arg = tab_for_shell(s);
  if (is_e(arg[0], "cd") == 1)
    cd(arg, env);
  else if ((is_e(arg[0], "env") == 1)
	   || (is_e(arg[0], "setenv") == 1 && nb_arg(arg) == 1))
    s_wt(env);
  else if (is_e(arg[0], "setenv") == 1)
    env = s_env(env, arg);
  else if (is_e(arg[0], "unsetenv") == 1)
    env = us_env(env, arg);
  else if (is_e(arg[0], "exit") == 1)
    kill(getpid(), SIGINT);
  my_putstr("$> ");
  return (env);
}

int	main(int ac, char **av, char **env)
{
  pid_t	pid;
  char	*s;
  int	status;

  my_putstr("$> ");
  s = read_st(0);
  while (42)
    {
      pid = fork();
      if (pid == 0)
	{
	  ex_cmd(s, env);
	  kill(getpid(), SIGINT);
	}
      else
	{
	  wait(&status);
	  env = process_pere(env, s);
	  s = read_st(0);
	}
    }
}
