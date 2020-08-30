/*
** eval_expr.c for eval_expr.c in /home/afou_n/rendu/Piscine_C_evalexpr
** 
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
** 
** Started on  Mon Oct 26 19:03:22 2015 Afou Nacerdine
** Last update Tue Nov  3 22:46:42 2015 AKKACHE Kaci
*/

#include <stdlib.h>
#include "./include/my.h"
#include "./include/bistromatique.h"

char	**testop(char **str2, char *str)
{
  t_list_testtop top;

  top.i = 0;
  top.s = 0;
  top.sum = malloc(sizeof(char *) * tablen(str2) + 2);
  while (str2[top.i] != NULL)
    {
      if (str2[top.i][0] == '*')
	top = testop_stock(str2, str, top);
      else if (str2[top.i][0] == '/')
	top = testop_stock2(str2, str, top);
      else if (str2[top.i][0] == '%')
	top = testop_stock3(str2, str, top);
      else if (str2[top.i][0] == '+' || (str2[top.i][0] == '-' && str2[top.i][1] == '\0'))
	top = testop_stock4(str2, str, top);
      top.i = top.i + 1;
    }
  return (finishsum(top.sum, str2, top.i, top.s));
}

char	*eval_expr(char *str)
{
  char	**str2;
  int	i;
  int	nb;
  char	*p;

  i = 0;
  str2 = my_str_to_wordtab(str);
  nb = tablen(str2);
  while (str2[i] != NULL)
    {
      if (str2[i][0] == '(')
        {
          p = par(str2, i);
          str2[i] = eval_expr(p);
        }
      i = i + 1;
    }
  if (nb  > 1)
    return tabsum(testop(str2, str));
  else
    return str2[0];
}
