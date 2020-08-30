/*
** sum_stdarg.c for sum_stdarg.c in /home/Rayan/Systeme Unix/PSU_2015_my_printf_bootstrap
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Thu Nov  5 02:36:56 2015 AKKACHE Kaci
** Last update Thu Nov  5 04:32:47 2015 AKKACHE Kaci
*/

#include <stdio.h>
#include <stdarg.h>

int	sum_stdarg(int i, int nb, ...)
{
  int	j;
  int	s;
  va_list(ap);

  j = 0;
  s = 0;
  va_start(ap, nb);
  while (j < nb)
    {
      if (i == 0)    
	s = s + va_arg(ap, int);
      else 
	s = s + my_strlen(va_arg(ap, char *));
      j = j + 1;    
    }
  va_end(ap);
  return (s);
}

