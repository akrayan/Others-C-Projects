/*
** sum_params.c for sum_params.c in /home/Rayan/Piscine_C_J08
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Wed Oct  7 15:32:16 2015 AKKACHE Kaci
** Last update Thu Oct  8 18:48:33 2015 AKKACHE Kaci
*/

#include <stdlib.h>

char	*sum_params(int argc, char **argv)
{
  char	*dest;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  dest = malloc(my_strlen(argv));
  while (i < argc)
    {
      while (argv[i][j] != '\0')
	{
	  dest[k] = argv[i][j];
	  j = j + 1;
	  k = k + 1;
	}
      dest[k] = '\n';
      k = k + 1; 
      j = 0;
      i = i + 1; 
    } 
  return (dest);
} 
