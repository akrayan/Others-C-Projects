/*
** my_printf.c for my_printf.c in /home/Rayan/Systeme Unix/PSU_2015_my_printf
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sat Nov 14 12:23:52 2015 AKKACHE Kaci
** Last update Sat Nov 14 12:26:37 2015 AKKACHE Kaci
*/

#include "my_printf.h"
#include <stdlib.h>

int     check(char c)
{
  char  *str;
  int   i;

  i = 0;
  str = "dicsbxXoSup%";
  while (str[i] != '\0')
    {
      if (str[i] == c)
        return (i);
      i = i + 1;
    }
  return (-1);
}

void	tab(int i, va_list ap)
{
  void (*tab[12])(va_list);

  tab[0] = &aff_number;
  tab[1] = &aff_number;
  tab[2] = &aff_char;
  tab[3] = &aff_string;
  tab[4] = &aff_binary;
  tab[5] = &aff_hexa_min;
  tab[6] = &aff_hexa_maj;
  tab[7] = &aff_octa;
  tab[8] = &aff_not_print;
  tab[9] = &aff_number_uns;
  tab[10] = &aff_pointer;
  tab[11] = &aff_modulo;
  (*tab[i])(ap);
}

char	*zero(char *str)
{
  if (my_strlen(str) == 1)
    my_putstr("00");
  else if (my_strlen(str) == 2)
    my_putchar('0');
}

int	not_print(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')

    {
      if (str[i] < 32 || str[i] >= 127)
	{
	  my_putchar('\\');
	  zero(convert(str[i], 8, 0));
	  my_putstr(convert(str[i], 8, 0));
	}
      else
	my_putchar(str[i]);
      i = i + 1;
    }
}

int     my_printf(const char *str, ...)
{
  va_list       ap;
  int           i;

  compteur = 0;
  va_start(ap, str);
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '%')
	{
	  i = i + 1;
	  while (str[i] == ' ')
	    i = i + 1;
	  if (str[i - 1] == ' ' && (str[i] == 'd' || str[i] == 'i' || str[i] == 'p'))
	    my_putchar(' ');
	  stock(str, i, ap);
	}
      else
	my_putchar(str[i]);
      if (str[i] != '\0')
	i = i + 1;
    }
  va_end(ap);
  return compteur;
}
