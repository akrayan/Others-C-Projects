/*
** my_static.c for static in /home/axel/rendu/printf
** 
** Made by proust axel
** Login   <proust_c@epitech.net>
** 
** Started on  Fri Nov 13 11:56:35 2015 proust axel
** Last update Fri Nov 13 12:06:52 2015 proust axel
*/

#include "my.h"

int	my_return(int nb)
{
  static int	i;

  i = i + nb;
  return (i);
}

int	calc(va_list ap)
{
  my_put_nbr(my_return(0));
}
