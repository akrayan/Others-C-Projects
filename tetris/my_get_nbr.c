/*
** my_get_nbr.c for  in /home/axel
**
** Made by proust axel
** Login   <proust_c@epitech.net>
**
** Started on  Wed Oct  7 18:38:38 2015 proust axel
** Last update Sun Mar 20 17:04:42 2016 Axel Proust
*/

#include "my.h"

int	error_input(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 48 && str[i] <= 57)
	i++;
      else if (str[i + 1] == '\0')
	return (0);
      else
	  return (1);
    }
  return (0);
}

int	my_get_nbr(char *str)
{
  int	x;
  int	count;
  int	nb;

  x = 0;
  count = 0;
  nb = 0;
  if (error_input(str) == 1)
    return (-1);
  while ((str[x] >= '0' && str[x] <= '9') || (str[x] == '+' || str[x] ==  '-'))
    {
      if (str[x] >= '0' && str[x] <= '9')
	nb = nb * 10 + (str[x] - 48);
      if (str[x] == '-')
	count = count + 1;
      x = x + 1;
    }
  if (count % 2 == 1)
    return (1);
  return (nb);
}
