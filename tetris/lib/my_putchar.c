/*
** my_putchar.c for my_putchar in /home/axel/librairie
**
** Made by proust axel
** Login   <proust_c@epitech.net>
**
** Started on  Tue Oct  6 09:26:02 2015 proust axel
** Last update Mon Feb 15 15:55:59 2016 Axel Proust
*/

#include <stdarg.h>
#include <unistd.h>
#include "my.h"

int	aff_my_putchar(va_list ap)
{
  my_putchar(va_arg(ap, int));
}

int	my_putchar(int c)
{
  my_return(1);
  write(1, &c, 1);
}
