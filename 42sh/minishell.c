
/*
1;2802;0c1;2802;0c1;2802;0c** minishell.c for minishell in /home/vella_c/rendu/Systeme_Unix/PSU_2015_minishell2
**
** Made by VELLA CYRIL
** Login   <Cyril@epitech.net>
**
** Started on  Mon Apr  4 09:42:05 2016 VELLA CYRIL
** Last update Fri Jun  3 23:42:17 2016 AKKACHE Kaci
*/

#include "include/minishell.h"

int	check_builtins(char **cmd)
{
  if (my_strncmp(*cmd, "setenv", 6) == 0)
    return (0);
  else if (my_strncmp(*cmd, "unsetenv", 8) == 0)
    return (0);
  else if (my_strncmp(*cmd, "cd", 2) == 0)
    return (0);
  else if (my_strncmp(*cmd, "env", 3) == 0)
    return (0);
  else
    return (1);
}

char	**my_exec(char **env, char **cmd)
{
  char	*path;
  char	**tab;

  if (access(*cmd, F_OK) == 0)
    {
      if (execve(*cmd, cmd, env) == -1)
	return (env);
    }
  if (my_strcmp("env", *cmd) == 0)
    {
      board(env);
      exit(1);
    }
  tab = str_to_wordtab_pathname(env);
  path = check_access(tab, *cmd);
  if (access(path, F_OK) == -1)
    {
      my_putstr(*cmd);
      my_putstr(": command not found\n");
      exit(1);
    }
  if (execve(path, cmd, env) == -1)
    return (env);
  return (env);
}

int	pid_bash(pid_t pid)
{
  int	status;

  status = 0;
  if (pid == -1)
    {
      my_putstr("Error ...\n");
      return (-1);
    }
  else if (pid == 0)
    return (0);
  else
    {
      waitpid(pid, &status, WUNTRACED | WCONTINUED);
      if (WTERMSIG(status))
	{
	  if (WTERMSIG(status) == SIGSEGV)
	    my_putstr("Segmentation fault (core dumped). \n");
	}
    }
  return (1);
}

void		my_shell(char **env)
{
  pid_t		pid;
  char		*ptr;
  t_list	a;
  char		**cmd;

  my_prompt(env);
  a.i = 1;
  while ((ptr = get_next_line(0)))
    {
      epur_str(ptr);
      create_history(ptr);
      check_exit(ptr);
      if (my_strncmp("exit", ptr, 4) == 0)
      exit (0);
      if (ptr != NULL)
	cmd = my_str_to_wordtab(ptr);
      if ((a.i = check_builtins(cmd)) == 0)
	env = make_builtins(env, cmd);
      if (a.i != 0)
	  pid = fork();
      if ((pid_bash(pid)) == 0 && a.i == 1)
	env = my_exec(env, cmd);
      free(cmd);
      my_prompt(env);
    }
}

int	main(int ac, char **av, char **env)
{
  char	**tab;

  av = av;
  if (*env == NULL)
    tab = search_path(env);
  else if (search_line(env, "PATH") == -1)
    tab = search_path(env);
  else if (search_line(env, "PWD") == -1)
    tab = search_path(env);
  else
    tab = my_copy_env(env);
  if (ac != 1)
    {
      my_putstr("bash : No parameter\n");
      return(0);
    }
  signal(SIGINT, SIG_IGN);
  /* signal(SIGSEGV, SIG_IGN); */
  my_shell(tab);
  return (0);
}
