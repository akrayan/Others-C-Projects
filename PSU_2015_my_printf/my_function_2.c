/*
** my_function_2.c for my_function_2.c in /home/Rayan/Systeme Unix/PSU_2015_my_printf
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sat Nov 14 12:18:54 2015 AKKACHE Kaci
** Last update Sat Nov 14 12:19:46 2015 AKKACHE Kaci
*/

#include "my_printf.h"

void    aff_hexa_min(va_list ap)
{
  my_putstr(convert(va_arg(ap, long int), 16, 0));
}

void    aff_hexa_maj(va_list ap)
{
  my_putstr(convert(va_arg(ap, long int), 16, 1));
}

void    aff_octa(va_list ap)
{
  my_putstr(convert(va_arg(ap, long int), 8, 0));
}

void    aff_not_print(va_list ap)
{
  not_print(va_arg(ap, char *));
}

void    aff_number_uns(va_list ap)
{
  unsigned int  nbr;

  nbr = va_arg(ap, unsigned int);
  my_put_nbr_uns(nbr);
}
