/*
** convert_base.c for  in /home/zemmou_b/rendu/bistro
** 
** Made by Billal Zemmouri
** Login   <zemmou_b@epitech.net>
** 
** Started on  Sun Nov  1 15:22:20 2015 Billal Zemmouri
** Last update Tue Nov  3 22:02:42 2015 Afou Nacerdine
*/

#include <stdlib.h>
#include "./include/my.h"
#include "./include/bistromatique.h"

char	*dumpb(char *str)
{
  char  *cpy;
  int   i;

  cpy = malloc(sizeof(char) * (my_strlen(str) + 1));
  i = 0;
  while (str[i] != 0)
    {
      cpy[i] = str[i];
      i = i + 1;
    }
  cpy[i] = 0;
  return (cpy);
}

char	*int_to_char(int nb)
{
  int	number;
  int	i;
  char	*result;

  result = malloc(sizeof(char) * 12);
  i = 0;
  number = 1;
  if (nb < 0)
    {
      result[0] = '-';
      i = i + 1;
    }
  else if (nb > 0)
    {
      nb = nb * (-1);
    }
  while ((-9) > (nb / number))
    {
      number = number * 10;
    }
  while (1 <= number)
    {
      result[i] = ('0' + ((nb / number) * (-1)));
      i = i + 1;
      nb = nb % number;
      number = number / 10;
    }
  result[i] = 0;
  return (result);
}

char	*dumpb(char *str)
{
  char  *cpy;
  int   i;

  cpy = malloc(sizeof(char) * (my_strlen(str) + 1));
  i = 0;
  while (str[i] != 0)
    {
      cpy[i] = str[i];
      i = i + 1;
    }
  cpy[i] = 0;
  return (cpy);
}

char	*convert_nb_to_base(char *nb,char *base)
{
  char	*nbcpy;
  int	i;
  char	*result;
  char	*rest;
  char	*resultdiv;
  char	*tbase;

  i = 0;
  tbase = int_to_char(my_strlen(base));
  result = malloc(sizeof(char) * (10));
  resultdiv = dumpb(nb);
  while (resultdiv[0] != '0')
    {
      rest = infin_modulo(resultdiv , tbase);
      result[i] = base[my_getnbr(rest)];
      resultdiv = infin_div(resultdiv, tbase);
      i = i + 1;
    }
  if (nb[0] = '-')
    result[i] = '-';
  result = my_revstr(result);
  return (result);
}

char	**convertab(char **str2, char *b)
{
  int	i;

  i = 0;
  while (str2[i] != NULL)
    {
      str2[i] = convert_nb_to_base(str2[i], char *b);
      i = i + 1;
    }
  return (str2);
}
