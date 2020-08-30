/*
** my_revstr.c for my_revstr in /home/axel/Piscine_C_J06/ex_04
** 
** Made by proust axel
** Login   <proust_c@epitech.net>
** 
** Started on  Mon Oct  5 10:33:56 2015 proust axel
** Last update Mon Nov 16 17:58:27 2015 proust axel
*/

#include "my.h"

char	*my_revstr(char *str)
{
  char	c;
  int	i;
  int	j;

  i = 0;
  j = my_strlen(str) - 1;
  while (i < j)
    {
      c = str[i];
      str[i] = str[j];
      str[j] = c;
      i = i + 1;
      j = j - 1;
    }
  return (str);
}
