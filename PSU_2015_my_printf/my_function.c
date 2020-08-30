/*
** my_function.c for my_function.c in /home/Rayan/Systeme Unix/PSU_2015_my_printf
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sat Nov 14 12:22:59 2015 AKKACHE Kaci
** Last update Sat Nov 14 12:23:02 2015 AKKACHE Kaci
*/

#include "my_printf.h"

void    aff_number(va_list ap)
{
  my_put_nbr(va_arg(ap, int));
}

void    aff_char(va_list ap)
{
  my_putchar(va_arg(ap, int));
}

void    aff_string(va_list ap)
{
  my_putstr(va_arg(ap, char *));
}

void    aff_binary(va_list ap)
{
  my_putstr(convert(va_arg(ap, int), 2, 0));
}

void    aff_modulo(va_list ap)
{
  my_putchar('%');
}
