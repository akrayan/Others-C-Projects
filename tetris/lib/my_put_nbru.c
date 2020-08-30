/*
** my_put_nbru.c for my_put_nbru in /home/axel/printf/lib/my
**
** Made by proust axel
** Login   <proust_c@epitech.net>
**
** Started on  Tue Nov 10 15:22:35 2015 proust axel
** Last update Mon Feb 15 15:58:26 2016 Axel Proust
*/

#include <stdarg.h>
#include "my.h"

int	aff_my_put_nbru(va_list ap)
{
  my_put_nbru(va_arg(ap, unsigned int));
}

int     my_put_nbru(unsigned int nb)
{
  unsigned int   i;

  i = 1;
  while (nb / i > 9)
    {
      i = i * 10;
    }
  while (i >= 1)
    {
      my_putchar((nb / i ) + 48);
      nb = nb % i;
      i = i / 10;
    }
}
