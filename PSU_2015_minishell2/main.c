/*
** main.c for main.c in /home/Rayan/Shell/PSU_2015_minishell2
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue Mar 29 16:42:40 2016 AKKACHE Kaci
** Last update Tue Apr 12 20:37:22 2016 AKKACHE Kaci
*/

#include "./include/shell.h"

int		main(int ac, char **av, char **e)
{
  t_main	m;

  m.d.path = g_path(e, m.d.path);
  m.d.env = g_e(e, m.d.env);
  while (42)
    {
      pipe(m.fd);
      my_printf("> ");
      m.cmd = cmd_tab(s_space(get_next_line(0)));
      if (error_l(m.cmd) == 0)
	{
	  m.p = fork();
	  if (m.p == 0)
	    m = m1(m);
	  else
	    m = m10(m);
	}
    }
}
