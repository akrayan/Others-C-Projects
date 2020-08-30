/*
** disp_stdarg.c for disp_stdarg.c in /home/Rayan/Systeme Unix/PSU_2015_my_printf_bootstrap
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Thu Nov  5 03:17:34 2015 AKKACHE Kaci
** Last update Thu Nov  5 05:07:48 2015 AKKACHE Kaci
*/

#include <stdio.h>
#include <stdarg.h>

int	disp_stdarg(char *s, ...)
{
  va_list(ap);
  int	i;

  i = 0;
  va_start(ap, s);
  while (s[i] != '\0')
    {
      if (s[i] == 's')
	my_putstr(va_arg(ap, char *));
      else if (s[i] == 'c')
	my_putchar(va_arg(ap, int));
      else if (s[i] == 'i')
	my_put_nbr(va_arg(ap, int));
      my_putchar('\n');
      i = i + 1;
    }
  va_end(ap);
}
