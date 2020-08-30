/*
** infin_function_11.c for infin_function_11.c in /home/afou_n/rendu/Piscine_C_Bistromatique
** 
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
** 
** Started on  Tue Nov  3 20:23:46 2015 Afou Nacerdine
** Last update Tue Nov  3 22:40:00 2015 AKKACHE Kaci
*/

#include <stdlib.h>
#include "./include/my.h"
#include "./include/bistromatique.h"

t_list_testtop  testop_stock(char **str2, char *str, t_list_testtop top2)
{
  if (((top2.i - 2) > 0 && str2[top2.i - 2][0] == '/') ||
      ((top2.i - 2) > 0 && str2[top2.i - 2][0] == '%'))
    top2.sum[top2.s - 1] = domul(initmul(str2, top2.sum, top2.s, top2.i));
  else
    {
      top2.sum[top2.s] = malloc(sizeof(char) * my_strlen(str));
      top2.sum[top2.s] = domul(initmul(str2, top2.sum, top2.s, top2.i));
    }
  top2.i = geti(str2, top2.i);
  top2.s = top2.s + 1;
  return (top2);
}

t_list_testtop  testop_stock2(char **str2, char *str, t_list_testtop top)
{
  if (((top.i - 2) > 0 && str2[top.i - 2][0] == '*') ||
      ((top.i - 2) > 0 && str2[top.i - 2][0] == '%'))
    top.sum[top.s - 1] = dodiv(initdiv(str2, top.sum, top.s, top.i));
  else
    {
      top.sum[top.s] = malloc(sizeof(char) * my_strlen(str));
      top.sum[top.s] = dodiv(initdiv(str2, top.sum, top.s, top.i));
    }
  top.i = geti2(str2, top.i);
  top.s = top.s + 1;
  return (top);
}

t_list_testtop  testop_stock3(char **str2, char *str, t_list_testtop top)
{
  if (((top.i - 2) > 0 && str2[top.i - 2][0] == '/') ||
      ((top.i - 2) > 0 && str2[top.i - 2][0] == '*'))
    top.sum[top.s - 1] = domod(initmod(str2, top.sum, top.s, top.i));
  else
    {
      top.sum[top.s] = malloc(sizeof(char) * my_strlen(str));
      top.sum[top.s] = domod(initmod(str2, top.sum, top.s, top.i));
    }
  top.i = geti3(str2, top.i);
  top.s = top.s + 1;
  return (top);
}

t_list_testtop  testop_stock4(char **str2, char *str, t_list_testtop top)
{
  if (((str2[1][0] == '+' || (str2[1][0] == '-' && str2[1][1] == '\0'))
       || ((top.i - 2) > 0 && (str2[top.i - 2][0] != '*'))) &&
      ((str2[1][0] == '+' || (str2[1][0] == '-' && str2[1][1] == '\0'))
       || ((top.i - 2) > 0 && (str2[top.i - 2][0] != '/'))) &&
      ((str2[1][0] == '+' || (str2[1][0] == '-' && str2[1][1] == '\0'))
       || ((top.i - 2) > 0 && (str2[top.i - 2][0] != '%'))))
    {
      top.sum = getsum(top.sum, str2, top.i, top.s);
      top.s = top.s + 1;
    }
  str2 = getstr2(top.sum, str2, top.i, top.s);
 return (top);
}
