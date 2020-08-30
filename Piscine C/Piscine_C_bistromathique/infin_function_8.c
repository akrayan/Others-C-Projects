/*
** infin_function_8.c for infin_function_8.c in /home/afou_n/rendu/Piscine_C_evalexpr
** 
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
** 
** Started on  Sun Nov  1 22:31:13 2015 Afou Nacerdine
** Last update Tue Nov  3 22:03:33 2015 Afou Nacerdine
*/

#include <stdlib.h>
#include "./include/my.h"
#include "./include/bistromatique.h"

char    **getsum(char **sum, char **str2, int i, int s)
{
  sum[s] = malloc(sizeof(char) * my_strlen(str2[i - 1]) + 1);
  sum[s] = str2[i - 1];
  return (sum);
}

char    **getstr2(char **sum, char **str2, int i, int s)
{
  if (str2[i][0] == '-' && str2[i][1] == '\0')
    str2[i + 1] = infin_mult(str2[i + 1], "-1");
  return (str2);
}

char    **finishsum(char **sum, char **str2, int i, int s)
{
  if (str2[i - 2][0] == '+' ||
      (str2[i - 2][0] == '-' && str2[i - 2][1] == '\0'))
    {
      sum[s] = malloc(sizeof(char) * my_strlen(str2[i - 1]) + 1);
      sum[s] = str2[i - 1];
    }
  return (sum);
}

t_list_init initmul_stock(t_list_init ini, char **str2, int i)
{
  ini.j = 0;
  ini.nb = nbmul(str2, i);
  ini.mul = malloc(sizeof(char *) * tablen(str2) + 1);
  ini.mul[ini.j] = malloc(my_strlen(str2[i - 1]));
  return (ini);
}

char    **initmul(char **str2, char **sum, int s, int i)
{
  t_list_init ini;

  ini = initmul_stock(ini, str2, i);
  if (((i - 2) > 0 && str2[i - 2][0] == '/') ||
      ((i - 2) > 0 && str2[i - 2][0] == '%'))
    ini.mul[ini.j] = sum[s - 1];
  else
    ini.mul[ini.j] = str2[i - 1];
  ini.j = ini.j + 1;
  i = i + 2;
  if (ini.nb > 2)
    {
      while (str2[i] != NULL && str2[i][0] == '*')
        {
          ini.mul[ini.j] = malloc(my_strlen(str2[i - 1]));
          ini.mul[ini.j] = str2[i - 1];
          ini.j = ini.j + 1;
          i = i + 2;
        }
    }
  ini.mul[ini.j] = malloc(my_strlen(str2[i - 1]));
  ini.mul[ini.j] = str2[i - 1];
  return (ini.mul);
}
