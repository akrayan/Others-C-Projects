/*
** my_revstr.c for my_revstr.c in /home/Rayan/Systeme Unix/PSU_2015_my_printf
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sat Nov 14 12:31:42 2015 AKKACHE Kaci
** Last update Sat Nov 14 12:31:44 2015 AKKACHE Kaci
*/

#include <stdlib.h>

char	*my_revstr(char *str)
{
  int	i;
  int	j;
  char	*result;

  i = 0;
  result = malloc(my_strlen(str) + 1);
  j = my_strlen(str) - 1;
  while (str[i] != '\0')
    {
      result[j] = str[i];
      i = i + 1;
      j = j - 1;
    }
  return(result);
}
