/*
** infin_function_3.c for infin_function_3.c in /home/afou_n/rendu/Piscine_C_evalexpr
** 
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
** 
** Started on  Sun Nov  1 14:55:36 2015 Afou Nacerdine
** Last update Tue Nov  3 22:03:07 2015 Afou Nacerdine
*/
#include <stdlib.h>
#include "./include/my.h"
#include "./include/bistromatique.h"

char	*my_copy(char *str)
{
  char	*scpy;
  int   i;

  scpy = malloc(sizeof(char) * (my_strlen(str) + 1));
  i = 0;
  while (i != my_strlen(str))
    {
      if ((str[i] >= '0' && str[i] <= '9') && (i < my_strlen(str)))
	scpy[i] = str[i];
      else
        scpy[i] = '0';
      i = i + 1;
    }
  scpy[i] = 0;
  return (scpy);
}

char	*dump(char *str,int z)
{
  char  *cpy;
  int   i;

  cpy = malloc(sizeof(char) * (z + 1));
  i = 0;
  while (str[i] != 0)
    {
      cpy[i] = str[i];
      i = i + 1;
    }
  return (cpy);
}

char    *rest(char*rest ,char *nb1, int begin ,int z)
{
  int	i;
  int	y;
  char	*cpy;

  cpy = dump(rest,my_strlen(nb1));
  i = my_strlen(rest);
  while (nb1[begin] != 0)
    {
      cpy[i] = nb1[begin];
      begin = begin + 1;
      i = i + 1;
    }
  cpy[i] = 0;
  return (cpy);
}

char	*dumpdiv(char *str,int begin,int end)
{
  char  *cpy;
  int	i;
  int	y;

  cpy = malloc(sizeof(char) * (my_strlen(str) + 2));
  i = 0;
  y = begin;
  while (y != end)
    {
      cpy[i] = str[y];
      i = i + 1;
      y = y + 1;
    }
  return (cpy);
}

char *addz(char *str ,char * nb1)
{
  int	nb;
  int	i;
  int	y;
  char	*cpy;

  cpy = malloc(sizeof(char) * (my_strlen(nb1) + 1));
  nb = my_strlen(nb1) - my_strlen(str);
  i = 0;
  y = 0;
  while (i < nb)
    {
      cpy[i] = '0';
      i = i + 1;
    }
  while (i != my_strlen(nb1))
    {
      cpy[i] = str[y];
      y = y + 1;
      i = i + 1;
    }
  cpy[i] = 0;
  return (cpy);
}
