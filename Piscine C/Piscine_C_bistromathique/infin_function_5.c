/*
** infin_function_5.c for infin_function_5.c in /home/afou_n/rendu/Piscine_C_evalexpr
** 
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
** 
** Started on  Sun Nov  1 15:32:10 2015 Afou Nacerdine
** Last update Tue Nov  3 22:03:15 2015 Afou Nacerdine
*/
#include <stdlib.h>
#include "./include/my.h"
#include "./include/bistromatique.h"

t_list_mult	initz(t_list_mult mult)
{
  while (mult.i != mult.y)
    {
      mult.tab[mult.y][mult.i] = '0';
      mult.i = mult.i + 1;
    }
  return (mult);
}

t_list_mult	multcal(char *nb1, char *nb2, t_list_mult mult)
{
  while (nb2[mult.a] != 0)
    {
      if ((((nb1[mult.y] - 48) * (nb2[mult.a] - 48)) + mult.ret) > 9)
	{
	  mult.tab[mult.y][mult.i] =
	    (((nb1[mult.y] - 48) * (nb2[mult.a] - 48) + mult.ret) % 10) + 48;
	  mult.ret = ((nb1[mult.y] - 48) * (nb2[mult.a] - 48) + mult.ret) / 10;
	}
      else
	{
	  mult.tab[mult.y][mult.i] =
	    ((nb1[mult.y] - 48) * (nb2[mult.a] - 48)) + 48 + mult.ret;
	  mult.ret = 0;
	}
      mult.a = mult.a + 1;
      mult.i =  mult.i + 1;
    }
  return (mult);
}

char		**infin_mult1(char *nb1, char *nb2 ,int strlen)
{
  t_list_mult	mult;

  mult.a = 0;
  mult.i = 0;
  mult.y = 0;
  mult.ret = 0;
  mult.size = (my_strlen(nb2) + strlen);
  mult.tab = malloc(sizeof(char *) * (strlen + 1));
  while (mult.y != strlen + 1)
    {
      mult.tab[mult.y] = malloc(sizeof(char) * (mult.size + 1));
      initz(mult);
      mult.i = mult.y;
      mult = multcal(nb1, nb2, mult);
      mult.tab[mult.y][mult.i] = 0;
      mult.y = mult.y + 1;
      mult.a = 0;
      mult.i = 0;
    }
  mult.tab[mult.y - 1] = NULL;
  return (mult.tab);
}

char    *par(char **str2, int i)
{
  char  *p;
  int   j;

  p = malloc(my_strlen(str2[i]));
  j = 1;
  while (str2[i][j + 1] != '\0')
    {
      p[j - 1] = str2[i][j];
      j = j + 1;
    }
  p[j - 1] = '\0';
  return (p);
}

int     tablen(char **tab)
{
  int   i;

  i = 0;
  while (tab[i] != NULL)
    {
      i = i + 1;
    }
  return i;
}
