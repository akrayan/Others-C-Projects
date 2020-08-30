/*
** infin_function_6.c for infin_function_6.c in /home/afou_n/rendu/Piscine_C_evalexpr
** 
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
** 
** Started on  Sun Nov  1 22:27:44 2015 Afou Nacerdine
** Last update Tue Nov  3 22:03:24 2015 Afou Nacerdine
*/
#include <stdlib.h>
#include "./include/my.h"
#include "./include/bistromatique.h"

char    *tabsum(char **sum)
{
  char  *res;
  int   i;

  res = malloc(1);
  res = "0";
  i = 0;
  while (sum[i] != NULL)
    {
      res = infin_add(res, sum[i]);
      i = i + 1;
    }
  return (res);
}

char    *domul(char **mul)
{
  int   j;
  char  *m;

  j = 0;
  m = malloc(1);
  m = "1";
  while (mul[j] != NULL)
    {
      m = infin_mult(m, mul[j]);
      j = j + 1;
    }
  return (m);
}

char    *dodiv(char **div)
{
  int   j;
  char  *m;

  m = div[0];
  j = 1;
  while (div[j] != NULL)
    {
      m = infin_div(m, div[j]);
      j = j + 1;
    }
  return (m);
}

char    *domod(char **mod)
{
  int   j;
  char  *m;

  m = mod[0];
  j = 1;
  while (mod[j] != NULL)
    {
      m = infin_modulo(m, mod[j]);
      j = j + 1;
    }
  return (m);
}

int     nbmul(char **str2, int i)
{
  int	nb;

  nb = 0;
  while (str2[i] != NULL && str2[i][0] == '*')
    {
      nb = nb + 1;
      i = i + 2;
    }
  nb = nb + 1;
  return nb;
}
