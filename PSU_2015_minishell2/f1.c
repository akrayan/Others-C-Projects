/*
** f1.c for f1.c in /home/Rayan/Shell/PSU_2015_minishell2
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue Apr 12 18:09:21 2016 AKKACHE Kaci
** Last update Tue Apr 12 19:16:42 2016 AKKACHE Kaci
*/

#include "./include/shell.h"

int	c_s3(char *s)
{
  int	i;

  i = my_strlen(s) - 1;
  while (i >= 0 && s[i] == ' ')
    i--;
  return (i);
}

char	*init_s()
{
  char	*s;

  s = malloc(1);
  s[0] = '\0';
  return (s);
}

void	exec(t_l *path, t_l *env, char *a)
{
  t_l	*p;
  int	i;
  char	**arg;

  arg = s_t_w(a, ' ');
  p = path;
  i = 0;
  while (arg[0][i] != '\0' && arg[0][i] != '/')
    i++;
  if (arg[0][i] == '\0')
    {
      while (p != NULL && access(sc(p->s, arg[0], '/'), F_OK) != 0)
	p = p->next;
      execve(sc(p->s, arg[0], '/'), arg, l_tab(env));
    }
  execve(arg[0], arg, l_tab(env));
}

char	*sc2(char *s, int *i, char c)
{
  int	j;

  j = *i;
  if (c != 0)
    {
      s[j] = c;
      j++;
    }
  *i = j;
  return (s);
}

char	*sc(char *s1, char *s2, char c)
{
  int	i;
  int	k;
  char	*s3;

  i = 0;
  k = 0;
  if ( c != 0)
    s3 = malloc(my_strlen(s1) + my_strlen(s2) + 2);
  else
    s3 = malloc(my_strlen(s1) + my_strlen(s2) + 1);
  while (s1[i] != '\0')
    {
      s3[i] = s1[i];
      i++;
    }
  s3 = sc2(s3, &i, c);
  while (s2[k] != '\0')
    {
      s3[i] = s2[k];
      i++;
      k++;
    }
  s3[i] = '\0';
  return (s3);
}
