/*
** cmd1.c for cmd1.c in /home/Rayan/test/shell
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Apr 10 08:38:46 2016 AKKACHE Kaci
** Last update Wed Apr 13 12:12:55 2016 AKKACHE Kaci
*/

#include "./include/shell.h"

char	*do_pipe2(char *a, t_c c, t_cmd d)
{
  pipe(c.fd2);
  c.pid2 = fork();
  if (c.pid2 == 0)
    {
      close(c.fd[0]);
      close(c.fd[1]);
      close(c.fd2[0]);
      dup2(c.fd2[1], 1);
      my_printf("%s", d.s);
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

char	*do_pipe(char *a, t_cmd d)
{
  t_c	c;

  pipe(c.fd);
  c.pid = fork();
  if (c.pid == 0)
    do_pipe2(a, c, d);
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
  return (c.o);
}

char	*do_cmd(char *a, t_cmd d)
{
  t_c	c;

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
    {
      wait(&c.status);
      close(c.fd[1]);
      dup2(c.fd[0], 0);
      c.pid2 = fork();
      if (c.pid2 == 0)
	exec(d.path, d.env, a);
      else
	wait(&c.status);
    }
  c.o = init_s();
  return (c.o);
}

char	*do_chv2(char *a, char *file, t_c c, t_cmd d)
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

char	*do_chv(char *a, char *file, t_cmd d)
{
  t_c	c;

  c.f = open(file, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU | S_IRWXG | S_IRWXO);
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
    do_chv2(a, file, c, d);
  close(c.f);
  c.o = malloc(1);
  c.o[0] = '\0';
  return (c.o);
}
