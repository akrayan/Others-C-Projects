/*
** disp_stdarg.c for  in /home/axel/rendu/Piscine_PSU_2015_my_printf_bootstrap/sum_stdarg
** 
** Made by proust axel
** Login   <proust_c@epitech.net>
** 
** Started on  Tue Nov  3 14:09:55 2015 proust axel
** Last update Mon Nov 16 19:12:58 2015 proust axel
*/

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int	check_char(char c)
{
  int	i;
  char	*flags;

  flags = "csdoxXbSupin%";
  i = 0;
  while (flags[i] != '\0')
    {
      if (flags[i] == c)
	return (i);
      i = i + 1;
    }
  return (-1);
}

void	check_aff(int i, va_list ap)
{
  int	(*check[13])(va_list);

  check[0] = &aff_my_putchar;
  check[1] = &my_affstr;
  check[2] = &aff_my_put_nbr;
  check[3] = &aff_convert_oct;
  check[4] = &aff_my_put_nbr_base;
  check[5] = &aff_my_put_nbr_BASE;
  check[6] = &aff_convert_bin;
  check[7] = &aff_my_putStr;
  check[8] = &aff_my_put_nbru;
  check[9] = &aff_my_put_nbr_basep;
  check[10] = &aff_my_put_nbr;
  check[11] = &calc;
  check[12] = &aff_modulo;
  (*check[i])(ap);
}

int	conditions(const char *str, va_list ap, int i)
{
  if (str[i - 1] == ' ' && (str[i] == 'd' && str[i] == 'p' && str[i] == 'i'))
    my_putchar(' ');
  if (check_char(str[i]) != -1)
    check_aff(check_char(str[i]), ap);
  else if (check_char(str[i]) == -1)
  {
    my_putchar('%');
    my_putchar(str[i]);
  }
  return (i);
}

int	my_printf(const char *str, ...)
{
  va_list	ap;
  int		i;

  if (str == 0)
    return (-1);
  i = 0;
  va_start(ap, str);
  while (str[i])
    {
      if (str[i] == '%')
	{
	  i++;
	  while (str[i] == ' ')
	    i++;
	  if (str[i] == '\0')
	    return (0);
	  conditions(str, ap , i);
	}
      else
	my_putchar(str[i]);
      i = i + 1;
    }
  return (my_return(0));
  va_end(ap);
}
