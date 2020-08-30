/*
** my_str.c for my_str in /home/vella_c/rendu/Prog_elem/CPE_colle_semaine1
** 
** Made by VELLA CYRIL
** Login   <Cyril@epitech.net>
** 
** Started on  Tue Apr 26 18:22:56 2016 VELLA CYRIL
** Last update Tue Apr 26 20:21:14 2016 AKKACHE Kaci
*/

#include "./include/maze.h"

char	*scat(char *str, char *str1)
{
  int	j;
  int	i;
  char	*res;

  i = 0;
  j = 0;
  if ((res = malloc(slen(str) + slen(str1) + 1)) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      res[i] = str[i];
      i++;
    }
  while (str1[j] != '\0')
    {
      res[i] = str1[j];
      i++;
      j++;
    }
  res[i] = '\0';
  free(str);
  free(str1);
  return (res);
}

char	*sdup(char *str)
{
  int	i;
  char	*res;
  
  i = 0;
  if ((res = malloc(slen(str) + 1)) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      res[i] = str[i];
      i++;
    }
  res[i] = '\0';
  return (res);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (i);
}

int	slen(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0');
  return (i);
}
