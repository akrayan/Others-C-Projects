/*
** my_put_nbr.c for my_put nbr in /home/axel
**
** Made by proust axel
** Login   <proust_c@epitech.net>
**
** Started on  Fri Oct  2 10:01:50 2015 proust axel
** Last update Mon Feb 15 15:56:52 2016 Axel Proust
*/

#include <stdarg.h>
#include "my.h"

int	aff_my_put_nbr(va_list ap)
{
  my_put_nbr(va_arg(ap, int));
}

int	my_put_nbr(int nb)
{
  int	i;

  i = 1;
  if ( nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb == -21474836448)
    {
      my_put_nbr(2147483644);
      my_putchar('8');
    }
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
