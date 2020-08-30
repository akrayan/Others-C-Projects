/*
** f2.c for f2.c in /home/Rayan/Shell/PSU_2015_minishell2
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue Apr 12 19:18:05 2016 AKKACHE Kaci
** Last update Tue Apr 12 19:20:26 2016 AKKACHE Kaci
*/

#include "./include/shell.h"

char	*l_t_s(t_l *l)
{
  t_l	*p;
  char	*s2;
  char	*s;

  p = l;
  if (p != NULL)
    {
      s = my_strdup(p->s);
      p = p->next;
    }
  while (p != NULL)
    {
      s = sc(s, p->s, '\n');
      p = p->next;
    }
  s = sc(s, "\0", '\n');
  return (s);
}

void	aff_fd(t_l *l, int fd)
{
  t_l	*p;
  char	*s;

  p = l;
  while (p != NULL)
    {
      write(fd, p->s, my_strlen(p->s));
      write(fd, "\n", 1);
      p = p->next;
    }
}

int	error_c(t_l *path, char *s)
{
  t_l	*p;
  int	i;
  char	**a;

  a = s_t_w(s, ' ');
  p = path;
  i = 0;
  while (a[0][i] != '\0' && a[0][i] != '/')
    i++;
  if (a[0][i] == '\0')
    {
      while (p != NULL && access(sc(p->s, a[0], '/'), F_OK) != 0)
	p = p->next;
      if (p == NULL)
	{
	  my_printf("%s: Command not found.\n", a[0]);
	  return (1);
	}
    }
  else if (access(a[0], F_OK) != 0)
    {
      my_printf("%s: Command not found.\n", a[0]);
      return (1);
    }
  return (0);
}

int	error_l2(char **t, int i)
{
  if ((t[i][0] == '|' || t[i][0] == '<') &&
      t[i + 1] != NULL && t[i + 2] != NULL && t[i + 2][0] == '<')
    {
      my_printf("Ambiguous input redirect.\n");
      return (1);
    }
  else if (t[i][0] == '>' && t[i + 1] != NULL &&
	   t[i + 2] != NULL && (t[i + 2][0] == '|' || t[i + 2][0] == '>'))
    {
      my_printf("Ambiguous output redirect.\n");
      return (1);
    }
  return (0);
}

int	error_l(char **t)
{
  int	i;

  i = 0;
  while (t[i] != NULL)
    {
      if ((t[i][0] == '>' || t[i][0] == '<') &&
	  (t[i + 1] == NULL || t[i + 1][0] == '>' || t[i + 1][0] == '<'
	   || t[i + 1][0] == '|' || t[i + 1][0] == ';'))
	{
	  my_printf("Missing name for redirect.\n");
	  return (1);
	}
      else if ((t[i][0] == '>' || t[i][0] == '<' || t[i][0] == '|') &&
	       (i == 0 || t[i - 1][0] == '>' || t[i - 1][0] == '<' ||
		t[i - 1][0] == '|' || t[i - 1][0] == ';'))
	{
	  my_printf("Invalid null command.\n");
	  return (1);
	}
      else if (error_l2(t, i) == 1)
	return (1);
      i++;
    }
  return (0);
}
