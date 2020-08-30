/*
** my_getnbr.c for my_getnbr in /home/assaba_m/rendu/Infographie/gfx_colle_fantasy5
** 
** Made by Moshe Assaban
** Login   <assaba_m@epitech.net>
** 
** Started on  Thu Jan  7 21:12:47 2016 Moshe Assaban
** Last update Thu Jan  7 21:12:48 2016 Moshe Assaban
*/

#include "my.h"

int	my_getnbr(char *str)
{
  int	i;
  int	nbr;
  int	isneg;
  int	temp;

  i = 0;
  nbr = 0;
  temp = 0;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
	temp = temp + 1;
      i = i + 1;
    }
  if (temp % 2 != 0)
    isneg = -1;
  else
    isneg = 1;
  while (str[i] >= '0' && str[i] <= '9')
    {
      nbr = (nbr * 10) + str[i] - '0';
      i = i + 1;
    }
  return (isneg * nbr);
}
