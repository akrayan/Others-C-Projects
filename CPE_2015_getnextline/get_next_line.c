/*
** get_next_line.c for get_next_line.c in /home/Rayan/Prog_Elem/CPE_2015_getnextline
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Wed Jan  6 12:16:55 2016 AKKACHE Kaci
** Last update Sun Jan 17 15:34:06 2016 AKKACHE Kaci
*/

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int	len(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

char	*my_strcat(char *s1, char *s2)
{
  char	*res;
  int	i;
  int	j;

  i = 0;
  j = 0;
  res = malloc(len(s1) + len(s2) + 1);
  while (i < len(s1))
    {
      res[i] = s1[i];
      i++;
    }
  while (j < len(s2))
    {
      res[i] = s2[j];
      i++;
      j++;
    }
  res[i] = '\0';
  return (res);
}

char	*read_inf(const int fd)
{
  char	*buffer;
  char	*result;
  int	ret;

  if ((buffer = malloc(sizeof(char) * READ_SIZE + 1)) == NULL ||
      (result = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  while ((ret = read(fd, buffer, READ_SIZE)) > 0)
    {
      buffer[ret] = '\0';
      result = my_strcat(result, buffer);
    }
  result[len(result)] = '\0';
  return (result);
}

int	go_to_nline(char *buff, int n)
{
  int	i;
  int	k;

  i = 0;
  k = 0;
  while (k < n && buff[i] != '\0')
    {
      if (buff[i] == '\n')
	k = k + 1;
      i = i + 1;
    }
  return (i);
}

char	*get_next_line(const int fd)
{
  static int	n = 0;
  static char	*buff;
  char		*res;
  t_compt	c;

  c.j = 0;
  c.k = 0;
  if (n == 0)
    buff = read_inf(fd);
  c.i = go_to_nline(buff, n);
  while (buff[c.i + c.k] != '\n' && buff[c.i + c.k] != '\0')
    c.k = c.k + 1;
  res = malloc(c.k + 1);
  while (buff[c.i] != '\n' && buff[c.i] != '\0')
    {
      res[c.j] = buff[c.i];
      c.i = c.i + 1;
      c.j = c.j + 1;
    }
  n = n + 1;
  return (res);
}
