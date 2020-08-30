/*
** my_putstr.c for my_putstr in /home/axel/Piscine_C_J04
** 
** Made by proust axel
** Login   <proust_c@epitech.net>
** 
** Started on  Thu Oct  1 12:20:51 2015 proust axel
** Last update Mon Nov 16 17:58:47 2015 proust axel
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int	my_affstr(va_list ap)
{
  char	*str;

  str = va_arg(ap, char *);
  if (str == NULL)
    my_putstr("(null)");
  else 
    my_putstr(str);
}

int	my_putstr(char *str)
{
  int	c;

  c = 0;
  while (str[c] != '\0')
    {
      my_putchar(str[c]);
      c = c + 1;
    }
}
