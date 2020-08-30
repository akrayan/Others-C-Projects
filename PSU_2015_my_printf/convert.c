/*
** convert.c for convert.c in /home/Rayan/Systeme Unix/PSU_2015_my_printf
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sat Nov 14 12:16:47 2015 AKKACHE Kaci
** Last update Sat Nov 14 12:17:38 2015 AKKACHE Kaci
*/

#include <stdlib.h>
#include "my_printf.h"

long int	nbrlen(long int nbr, long int base)
{
  long int	i;

  i = 0;
  while (nbr > 0)
    {
      nbr = nbr / base;
      i = i + 1;
    }
  return (i);
}

char	*convert(long int nbr, long int base, int maj)
{
  long int	i;
  long int	rest;
  char		*str;

  i = 0;
  str = malloc(nbrlen(nbr, base) + 1);
  while (nbr > 0)
    {
      rest = nbr % base;
      if (rest >= 10)
	{
	  if (maj == 0)
	    str[i] = rest + 87;
	  else if (maj == 1)
	    str[i] = rest + 55;
	}
      else
	str[i] = rest + 48;
      nbr = nbr / base;
      i = i + 1;
    }
  return (my_revstr(str));
}
