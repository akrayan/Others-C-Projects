/*
** my_put_nbroctal.c for put_nbr_octal in /home/axel/printf/lib/my
** 
** Made by proust axel
** Login   <proust_c@epitech.net>
** 
** Started on  Mon Nov  9 11:19:18 2015 proust axel
** Last update Mon Nov 16 19:12:11 2015 proust axel
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int	aff_convert_oct(va_list ap)
{
  convert_oct(va_arg(ap, int));
}

int     aff_convert_bin(va_list ap)
{
  convert_bin(va_arg(ap, int));
}

int	my_put_moins(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  return (nb);
}

int	convert_oct(int nb)
{
  char *result;
  int	i;
  int	n;

  i = 0;
  nb =  my_put_moins(nb);
  n = nb;
  while (n >= 1)
    {
      n = n / 8;
      i++;
    }
  if ((result = malloc(sizeof(char) * i + 1)) == NULL)
    return (0);
  i = 0;
  while (nb >= 1)
    {
      result[i] = (nb % 8) + 48;
      nb = nb / 8;
      i++;
    }
  result = my_revstr(result);
  my_putstr(result);
}

int     convert_bin(int nb)
{
  char *result;
  int   i;
  int   n;

  nb = my_put_moins(nb);
  n = nb;
  while (n >= 1)
    {
      n = n / 2;
      i++;
    }
  if ((result = malloc(sizeof(char) * i + 1)) == NULL)
    return (0);
  i = 0;
  while (nb >= 1)
    {
      result[i] = (((nb % 2) + 48));
      nb = nb / 2;
      i++;
    }
  result = my_revstr(result);
  my_putstr(result);
}
