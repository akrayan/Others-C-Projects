/*
** f4.c for f4.c in /home/Rayan/Shell/PSU_2015_minishell2
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue Apr 12 20:36:06 2016 AKKACHE Kaci
** Last update Wed Apr 13 12:12:13 2016 AKKACHE Kaci
*/

#include "./include/shell.h"

t_main		m7(t_main m)
{
  if (error_c(m.d.path, m.cmd[m.i]) == 0)
    m.d.s = do_dchva(m.cmd[m.i], m.cmd[m.i + 2], m.d);
  m.i = m.i + 3;
  if (m.cmd[m.i] != NULL)
    {
      if (m.cmd[m.i][0] == ';')
	{
	  my_printf("%s", m.d.s);
	  m.d.s[0] = '\0';
	}
      m.i++;
    }
  return (m);
}

t_main		m8(t_main m)
{
  if (error_c(m.d.path, m.cmd[m.i]) == 0)
    m.d.s = do_cmd(m.cmd[m.i], m.d);
  m.i++;
  if (m.cmd[m.i] != NULL && m.cmd[m.i][0] == ';')
    m.i++;
  return (m);
}

t_main		m9(t_main m)
{
  if (my_strncmp(m.cmd[m.i], "setenv", 5) == 0 &&
      (m.cmd[m.i][6] == '\0' || m.cmd[m.i][6] == ' '))
    m = m2(m);
  else if ((my_strncmp(m.cmd[m.i], "unsetenv", 7) == 0 &&
	    (m.cmd[m.i][8] == '\0' || m.cmd[m.i][8] == ' ')) ||
	   (my_strncmp(m.cmd[m.i], "env", 2) == 0 &&
	    (m.cmd[m.i][3] == '\0' || m.cmd[m.i][3] == ' ')))
    m = m3(m);
  else if ((m.cmd[m.i + 1] != NULL && m.cmd[m.i + 1][0] == '|') ||
	   (m.cmd[m.i + 1] != NULL && m.cmd[m.i + 1][0] == '>' &&
	    m.cmd[m.i + 1][1] == '\0'))
    m = m4(m);
  else if (m.cmd[m.i + 1] != NULL && m.cmd[m.i + 1][0] == '>' &&
	   m.cmd[m.i + 1][1] == '>')
    m = m5(m);
  else if (m.cmd[m.i + 1] != NULL && m.cmd[m.i + 1][0] == '<' &&
	   m.cmd[m.i + 1][1] == '\0')
    m = m6(m);
  else if (m.cmd[m.i + 1] != NULL && m.cmd[m.i + 1][0] == '<' &&
	   m.cmd[m.i + 1][1] == '<')
    m = m7(m);
  else
    m = m8(m);
  return (m);
}

t_main		m1(t_main m)
{
  close(m.fd[0]);
  m.d.s = malloc(1);
  m.d.s[0] = '\0';
  m.i = 0;
  while (m.cmd[m.i] != NULL)
    m = m9(m);
  my_printf("%s", m.d.s);
  m.i = -1;
  while (m.cmd[++m.i] != NULL)
    free(m.cmd[m.i]);
  free(m.cmd[m.i]);
  free(m.cmd);
  aff_fd(m.d.env, m.fd[1]);
  kill(getpid(), SIGINT);
  return (m);
}

t_main		m10(t_main m)
{
  wait(&m.st);
  close(m.fd[1]);
  m.i = read(m.fd[0], m.b, 4096);
  m.b[m.i] = '\0';
  m.n = my_strdup(m.b);
  while ((m.i = read(m.fd[0], m.b, 4096)) > 0)
    {
      m.b[m.i] = '\0';
      m.n = sc(m.n, m.b, 0);
    }
  close(m.fd[0]);
  free_list(m.d.env);
  m.d.env = NULL;
  m.d.env = g_path2(m.n, m.d.env, '\n');
  return (m);
}
