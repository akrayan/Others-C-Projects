/*
** f3.c for f3.c in /home/Rayan/Shell/PSU_2015_minishell2
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue Apr 12 20:31:38 2016 AKKACHE Kaci
** Last update Fri Apr 15 15:02:46 2016 AKKACHE Kaci
*/

#include "./include/shell.h"

t_main		m2(t_main m)
{
  m.j = 6;
  while (m.cmd[m.i][m.j] == ' ')
    m.j++;
  if (m.cmd[m.i][m.j] == '\0')
    {
      free(m.d.s);
      m.d.s = l_t_s(m.d.env);
    }
  else
    {
      m.d.s = malloc(1);
      m.d.s[0] = '\0';
      m.d.env = s_e(m.d.env, m.cmd[m.i]);
    }
  m.i++;
  if (m.cmd[m.i] != NULL && m.cmd[m.i][0] == '>')
    {
      m.i = m.i + 2;
      if (m.cmd[m.i] != NULL)
	m.i++;
    }
  else if (m.cmd[m.i] != NULL)
    m.i++;
  return (m);
}

t_main		m3(t_main m)
{
  if (my_strncmp(m.cmd[m.i], "unsetenv", 7) == 0 &&
      (m.cmd[m.i][8] == '\0' || m.cmd[m.i][8] == ' '))
    {
      m.d.s = malloc(1);
      m.d.s[0] = '\0';
      m.d.env = us_e(m.d.env, m.cmd[m.i]);
      m.i++;
      if (m.cmd[m.i] != NULL)
	m.i++;
    }
  else if (my_strncmp(m.cmd[m.i], "env", 2) == 0 &&
	   (m.cmd[m.i][3] == '\0' || m.cmd[m.i][3] == ' '))
    {
      free(m.d.s);
      m.d.s = l_t_s(m.d.env);
      m.i++;
      if (m.cmd[m.i] != NULL)
	m.i++;
    }
  return (m);
}

t_main		m4(t_main m)
{
  if (m.cmd[m.i + 1] != NULL && m.cmd[m.i + 1][0] == '|')
    {
      if (error_c(m.d.path, m.cmd[m.i]) == 0)
	m.d.s = do_pipe(m.cmd[m.i], m.d);
      else
	{
	  m.d.s = malloc(1);
	  m.d.s = '\0';
	}
      m.i = m.i + 2;
    }
  else if (m.cmd[m.i + 1] != NULL && m.cmd[m.i + 1][0] == '>'
	   && m.cmd[m.i + 1][1] == '\0')
    {
      if (error_c(m.d.path, m.cmd[m.i]) == 0)
	m.d.s = do_chv(m.cmd[m.i], m.cmd[m.i + 2], m.d);
      m.i = m.i + 3;
      if (m.cmd[m.i] != NULL && m.cmd[m.i][0] == ';')
	m.i++;
    }
  return (m);
}

t_main		m5(t_main m)
{
  if (error_c(m.d.path, m.cmd[m.i]) == 0)
    m.d.s = do_dchv(m.cmd[m.i], m.cmd[m.i + 2], m.d);
  m.i = m.i + 3;
  if (m.cmd[m.i] != NULL && m.cmd[m.i][0] == ';')
    m.i++;
  return (m);
}

t_main		m6(t_main m)
{
  if (access(m.cmd[m.i + 2], F_OK) == 0 && error_c(m.d.path, m.cmd[m.i]) == 0)
    m.d.s = do_chva(m.cmd[m.i], m.cmd[m.i + 2], m.d);
  else if (access(m.cmd[m.i + 2], F_OK) != 0)
    my_printf("%s: Aucun fichier ou dossier de ce type.\n", m.cmd[m.i + 2]);
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
