/*
** my_strcat.c for  in /home/vella_c/CPE_colle_semaine6
** 
** Made by VELLA CYRIL
** Login   <Cyril@epitech.net>
** 
** Started on  Tue May 31 18:12:10 2016 VELLA CYRIL
** Last update Tue May 31 19:02:19 2016 AKKACHE Kaci
*/

#include "include/brain.h"

int	s_len(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char	*s_cat(char *str, char *str2)
{
  int	i;
  int	j;
  char	*buff;

  i = 0;
  j = 0;
  if ((buff = malloc(s_len(str) + s_len(str2) + 1)) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      buff[i] = str[i];
      i++;
    }
  while (str2[j] != '\0')
    {
      buff[i] = str2[j];
      i++;
      j++;
    }
  buff[i] = '\0';
  free(str);
  return (buff);
}

char	*s_dup(char *s)
{
  int	i;
  char	*r;

  if ((r = malloc(s_len(s) + 1)) == NULL)
    return (NULL);
  i = -1;
  while (s[++i] != '\0')
    r[i] = s[i];
  r[i] = '\0';
  return (r);
}

char	*r_all(char *f)
{
  int	fd;
  int	r;
  char	*s;
  char	*b;

  if ((b = malloc(11)) == NULL)
    return (NULL);
  if ((fd = open(f, O_RDONLY)) == - 1)
    return (NULL);
  if ((r = read(fd, b, 10)) == - 1)
    return (NULL);
  b[r] = '\0';
  if ((s = s_dup(b)) == NULL)
    return (NULL);
  while (r > 0)
    {
      if ((r = read(fd, b, 10)) == - 1)
	return (NULL);
      b[r] = '\0';
      if ((s = s_cat(s, b)) == NULL)
	return (NULL);
    }
  free(b);
  return (s);
}
