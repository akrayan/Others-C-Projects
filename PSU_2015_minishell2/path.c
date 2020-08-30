/*
** path.c for path.c in /home/Rayan/test/5
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Apr 10 02:46:51 2016 AKKACHE Kaci
** Last update Tue Apr 12 18:11:59 2016 AKKACHE Kaci
*/

#include "./include/shell.h"

t_l	*g_path2(char *t, t_l *path, char c)
{
  int	j;
  int	k;
  char	*s;

  k = 0;
  while (t[k] != '\0')
    {
      j = 0;
      s = malloc(nbc2(t, c, k) + 1);
      while (t[k] != '\0' && t[k] != c)
	{
	  s[j] = t[k];
	  j++;
	  k++;
	}
      s[j] = '\0';
      path = add_elem(s, path);
      free(s);
      if (t[k] != '\0')
	k++;
    }
  return (path);
}

t_l	*g_path(char **t, t_l *path)
{
  int	i;

  path = NULL;
  i = 0;
  while (t[i] != NULL && my_strncmp(t[i], "PATH", 3) != 0)
    i++;
  if (t[i] != NULL)
    path = g_path2(t[i] + 5, path, ':');
  return (path);
}
