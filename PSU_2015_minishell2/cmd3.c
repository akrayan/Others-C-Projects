/*
** cmd3.c for cmd3.c in /home/Rayan/test/shell
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Apr 10 08:42:14 2016 AKKACHE Kaci
** Last update Tue Apr 12 19:23:28 2016 AKKACHE Kaci
*/

#include "./include/shell.h"

char	*g_chv(char *s)
{
  char	*res;
  char	*b;

  my_printf("? ");
  b = get_next_line(0);
  if (my_strcmp(b, s) == 0)
    {
      res = malloc(1);
      res[0] = '\0';
      return (res);
    }
  else
    res = my_strdup(b);
  while (my_strcmp(b, s) != 0)
    {
      my_printf("? ");
      b = get_next_line(0);
      if (my_strcmp(b, s) != 0)
	res = sc(res, b, '\n');
    }
  res = sc(res, "\0", '\n');
  return (res);
}

char	*do_dchva2(char *a, char *s, t_c c, t_cmd d)
{
  pipe(c.fd2);
  c.pid2 = fork();
  if (c.pid2 == 0)
    {
      close(c.fd[0]);
      close(c.fd[1]);
      close(c.fd2[0]);
      c.p = g_chv(s);
      dup2(c.fd2[1], 1);
      my_printf("%s", c.p);
      kill(getpid(), SIGINT);
    }
  else
    {
      wait(&c.status);
      close(c.fd[0]);
      close(c.fd2[1]);
      dup2(c.fd[1], 1);
      dup2(c.fd2[0], 0);
      exec(d.path, d.env, a);
    }
}

char	*do_dchva(char *a, char *s, t_cmd d)
{
  t_c	c;

  pipe(c.fd);
  c.pid = fork();
  if (c.pid == 0)
    do_dchva2(a, s, c, d);
  else
    {
      wait(&c.status);
      close(c.fd[1]);
      c.r = read(c.fd[0], c.b, 20);
      c.b[c.r] = '\0';
      c.o = my_strdup(c.b);
      while ((c.r = read(c.fd[0], c.b, 20)) > 0)
	{
	  c.b[c.r] = '\0';
	  c.o = sc(c.o, c.b, 0);
	}
    }
  close(c.f);
  return (c.o);
}
