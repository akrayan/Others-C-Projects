/*
** convert_base_to_nb.c for  in /home/zemmou_b/rendu/bistro1
** 
** Made by Billal Zemmouri
** Login   <zemmou_b@epitech.net>
** 
** Started on  Sun Nov  1 18:41:45 2015 Billal Zemmouri
** Last update Tue Nov  3 22:00:05 2015 Afou Nacerdine
*/

#include <stdlib.h>
#include "./include/my.h"
#include "./include/bistromatique.h"

char	*int_to_char(int nb)
{
  int	number;
  int	i;
  char  *result;

  result = malloc(sizeof(char) * 12);
  i = 0;
  number = 1;
  if (nb < 0)
    {
      result[0] = '-';
      i = i + 1;
    }
  else if (nb > 0)
    nb = nb * (-1);
  while ((-9) > (nb / number))
    number = number * 10;
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

char     *my_powerchar(char *nb, char *power)
{
  char   *n;

  n = malloc(10);
  n[0] = '1';
  if (power[0] == '0')
    return ("1");
  else if (power[0] < '0')
    return ("0");
  while (power[0] > '0')
    {
      n = infin_mult(nb , n);
      power = infin_sub(power, "1");
    }
  return (n);
}

char	*convert_base_to_nb(char *nbbase, char *base)
{
  char	*tbase;
  char	*nbbase_len;
  char	*nb;
  t_list_mod cv;

  cv.a = my_strlen(nbbase) - 1;
  nb  = malloc(2);
  cv.i = 0;
  tbase = int_to_char(my_strlen(base));
  nbbase_len = int_to_char(my_strlen(nbbase));
  cv.result = malloc(1);
  cv.result[0] = '0';
  while (nbbase_len[0] != '0')
    {
      nb[0] = nbbase[cv.i];
      cv.y = 0;
      while (nbbase[cv.a] != base[cv.y])
	cv.y = cv.y + 1;
      cv.result = infin_add(cv.result,
			 infin_mult(int_to_char(cv.y), my_powerchar(tbase, int_to_char(cv.i))));
      nbbase_len = infin_sub(nbbase_len, "1");
      cv.i = cv.i + 1;
      cv.a = cv.a - 1;
    }
  return (cv.result);
}
