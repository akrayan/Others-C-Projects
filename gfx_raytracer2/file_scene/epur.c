/*
** epur.c for rt2 in /home/nasrat_v/rendu/Infographie/gfx_raytracer2/file_scene
**
** Made by
** Login   <nasrat_v@epitech.net>
**
** Started on  Fri May 20 02:31:32 2016
** Last update Sat May 21 16:44:57 2016 
*/

#include "../include/rt.h"

char	*epur_str(char *str)
{
  char	*stock;
  int	n;
  int	i;

  i = 0;
  n = 0;
  if ((stock = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  while (str[i] == ' ' || str[i] == '\t')
    i += 1;
  while (str[i])
    {
      while ((str[i] == ' ' || str[i] == '\t') &&
	     (str[i + 1] == ' ' || str[i + 1] == '\t'))
	i += 1;
      if (str[i] == '\t' && (str[i + 1] != '\t' || str[i + 1] != ' ')
	  && (str[i - 1] != '\t' || str[i - 1] != ' '))
	str[i] = ' ';
      if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] == '\0')
	  str[i] = '\0';
      else
	stock[n++] = str[i++];
    }
  stock[n] = 0;
  return (stock);
}

char	*super_epur_str(char *str)
{
  char	*stock;
  int	n;
  int	i;

  i = 0;
  n = 0;
  if ((stock = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  while (str[i] == ' ' || str[i] == '\t')
    i += 1;
  while (str[i])
    {
      while (str[i] == ' ' || str[i] == '\t')
	i += 1;
      if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] == '\0')
	str[i] = '\0';
      else
	stock[n++] = str[i++];
    }
  stock[n] = 0;
  return (stock);
}
