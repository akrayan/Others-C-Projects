/*
** infin_function_7.c for infin_function_7.c in /home/afou_n/rendu/Piscine_C_evalexpr
** 
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
** 
** Started on  Sun Nov  1 22:29:22 2015 Afou Nacerdine
** Last update Tue Nov  3 22:01:17 2015 Afou Nacerdine
*/

#include <stdlib.h>
#include "./include/my.h"
#include "./include/bistromatique.h"

int     nbdiv(char **str2, int i)
{
  int	nb;

  nb = 0;
  while (str2[i] != NULL && str2[i][0] == '/')
    {
      nb = nb + 1;
      i = i + 2;
    }
  nb = nb + 1;
  return (nb);
}

int     nbmod(char **str2, int i)
{
  int	nb;

  nb = 0;
  while (str2[i] != NULL && str2[i][0] == '%')
    {
      nb = nb + 1;
      i = i + 2;
    }
  nb = nb + 1;
  return (nb);
}

int     geti(char **str2, int i)
{
  int	nb;

  nb = nbmul(str2, i);
  i = i + 2;
  if (nb > 2)
    while (str2[i] != NULL && str2[i][0] == '*')
      i = i + 2;
  return (i - 1);
}

int     geti2(char **str2, int i)
{
  int	nb;

  nb = nbdiv(str2, i);
  i = i + 2;
  if (nb > 2)
    while (str2[i] != NULL && str2[i][0] == '/')
      i = i + 2;
  return (i - 1);
}

int     geti3(char **str2, int i)
{
  int	nb;

  nb = nbmod(str2, i);
  i = i + 2;
  if (nb > 2)
    while (str2[i] != NULL && str2[i][0] == '%')
      i = i + 2;
  return (i - 1);
}
