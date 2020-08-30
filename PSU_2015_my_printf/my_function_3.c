/*
** my_function_3.c for my_function_3.c in /home/Rayan/Systeme Unix/PSU_2015_my_printf
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sat Nov 14 12:22:21 2015 AKKACHE Kaci
** Last update Sat Nov 14 12:22:25 2015 AKKACHE Kaci
*/

#include "my_printf.h"

void    aff_pointer(va_list ap)
{
  my_putstr("0x");
  my_putstr(convert(va_arg(ap, long int), 16, 0));
}

int     stock(const char *str, int i, va_list ap)
{
  if (str[i] == '\0')
    return (0);
  if (check(str[i]) != -1)
    tab(check(str[i]), ap);
  else if (check(str[i]) == -1)
    {
      my_putchar('%');
      my_putchar(str[i]);
    }
}
