/*
** cmd2.c for cmd2.c in /home/Rayan/test/shell
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Apr 10 08:40:13 2016 AKKACHE Kaci
** Last update Tue Apr 12 19:23:00 2016 AKKACHE Kaci
*/

#include "./include/shell.h"

char	*do_dchv2(char *a, char *file, t_c c, t_cmd d)
{
  wait(&c.status);
  c.pid = fork();
  if (c.pid == 0)
    {
      c.a1 = s_t_w(a, ' ');
      close(c.fd[1]);
      dup2(c.fd[0], 0);
      dup2(c.f, 1);
      exec(d.path, d.env, a);
    }
  else
    wait(&c.status);
}

char	*do_dchv(char *a, char *file, t_cmd d)
{
  t_c	c;

  c.f = open(file, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU | S_IRWXG | S_IRWXO);
  pipe(c.fd);
  c.pid = fork();
  if (c.pid == 0)
    {
      close(c.fd[0]);
      dup2(c.fd[1], 1);
      my_printf("%s", d.s);
      kill(getpid(), SIGINT);
    }
  else
    do_dchv2(a, file, c, d);
  close(c.f);
  c.o = malloc(1);
  c.o[0] = '\0';
  return (c.o);
}

char	*do_chva3(char *a, char *file, t_c c, t_cmd d)
{
  wait(&c.status);
  close(c.fd[0]);
  close(c.fd2[1]);
  dup2(c.fd[1], 1);
  dup2(c.fd2[0], 0);
  exec(d.path, d.env, a);
}

char	*do_chva2(char *a, char *file, t_c c, t_cmd d)
{
  pipe(c.fd2);
  c.pid2 = fork();
  if (c.pid2 == 0)
    {
      close(c.fd[0]);
      close(c.fd[1]);
      close(c.fd2[0]);
      dup2(c.fd2[1], 1);
      c.r = read(c.f, c.b, 20);
      c.b[c.r] = '\0';
      c.p = my_strdup(c.b);
      while ((c.r = read(c.f, c.b, 20)) > 0)
	{
	  c.b[c.r] = '\0';
	  c.p = sc(c.p, c.b, 0);
	}
      my_printf("%s", c.p);
      kill(getpid(), SIGINT);
    }
  else
    do_chva3(a, file, c, d);
}

char	*do_chva(char *a, char *file, t_cmd d)
{
  t_c	c;

  c.f = open(file, O_RDONLY);
  pipe(c.fd);
  c.pid = fork();
  if (c.pid == 0)
    do_chva2(a, file, c, d);
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
