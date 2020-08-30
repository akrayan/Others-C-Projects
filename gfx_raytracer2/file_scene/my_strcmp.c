/*
** my_strcmp.c for rt2 in /home/nasrat_v/rendu/Infographie/gfx_raytracer2/file_scene
**
** Made by
** Login   <nasrat_v@epitech.net>
**
** Started on  Sat May 21 16:45:34 2016
** Last update Sat May 21 16:45:35 2016 
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	n;

  n = 0;
  while (s1[n] != '\0')
    {
      if (s1[n] != s2[n])
	return (-1);
      n += 1;
    }
  if (s1[n] == s2[n])
    return (0);
  return (-1);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      else if (s1[i] == '\0')
	return (0);
      i += 1;
    }
  return (0);
}

char	*my_strcat(char *path, char *cmd)
{
  char	*final;
  int	cnt;
  int	n;

  cnt = 0;
  n = 0;
  if ((final = malloc(sizeof(char) * (my_strlen(path)
				      + my_strlen(cmd) + 2))) == NULL)
    return (NULL);
  while (path[cnt])
    {
      final[cnt] = path[cnt];
      cnt += 1;
    }
  final[cnt] = '/';
  cnt += 1;
  while (cmd[n])
    {
      final[cnt] = cmd[n];
      cnt += 1;
      n += 1;
    }
  final[cnt] = '\0';
  return (final);
}
