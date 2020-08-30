/*
** my_strdup.c for my_strdup.c in /home/Rayan/Piscine_C_J08
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Wed Oct  7 10:30:42 2015 AKKACHE Kaci
** Last update Thu Oct  8 18:44:25 2015 AKKACHE Kaci
*/

#include <stdlib.h>

char	*my_strdup(char *src)
{
  int	i;  
  char	*dest;

  i = 0;  
  dest = malloc(my_strlen(src));
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
