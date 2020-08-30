/*
** my_put_nbrbase.c for  in /home/axel/printf/lib/my
** 
** Made by proust axel
** Login   <proust_c@epitech.net>
** 
** Started on  Sat Nov  7 10:37:00 2015 proust axel
** Last update Mon Nov 16 17:46:20 2015 proust axel
*/

#include <stdarg.h>
#include "my.h"

int	aff_my_put_nbr_base(va_list ap)
{
  my_put_nbr_base(va_arg(ap, int));
}

int     aff_my_put_nbr_BASE(va_list ap)
{
  my_put_nbr_BASE(va_arg(ap, int));
}

int	my_put_nbr_base(int nb)
{
  int	i;

  i = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  while (nb / i > 15)
    {
      i = i * 16;
    }
  while (i >= 1)
    {
      if (nb / i > 9)
	my_putchar(nb / i  + 87);
      else
	my_putchar((nb / i ) + 48);
      nb = nb % i;
      i = i / 16;
    }
}

int     my_put_nbr_BASE(int nb)
{
  int   i;

  i = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  while (nb / i > 15)
    {
      i = i * 16;
    }
  while (i >= 1)
    {
      if (nb / i > 9)
        my_putchar(nb / i  + 55);
      else
        my_putchar((nb / i ) + 48);
      nb = nb % i;
      i = i / 16;
    }
}

int	my_put_nbr_basep(long nb)
{
  long   i;

  i = 1;
  my_putstr("0x");
  while (nb / i > 15)
    {
      i = i * 16;
    }
  while (i >= 1)
    {
      if (nb / i > 9)
        my_putchar(nb / i  + 87);
      else
        my_putchar((nb / i ) + 48);
      nb = nb % i;
      i = i / 16;
    }
}
