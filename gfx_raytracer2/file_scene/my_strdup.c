/*
** my_strdup.c for tr2 in /home/nasrat_v/rendu/Infographie/gfx_raytracer2/file_scene
**
** Made by
** Login   <nasrat_v@epitech.net>
**
** Started on  Sat May 21 17:50:23 2016
** Last update Sat May 21 17:52:17 2016 
*/

#include "../include/rt.h"

char	*my_strdup(char *str)
{
  char	*stock;
  int	i;
  int	n;

  i = 0;
  n = 0;
  if ((stock = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[i])
    {
      stock[n] = str[i];
      i += 1;
      n += 1;
    }
  stock[n] = 0;
  return (stock);
}
