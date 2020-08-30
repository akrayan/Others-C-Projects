/*
** infin_function_10.c for infin_function_10.c in /home/afou_n/rendu/Piscine_C_evalexpr
** 
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
** 
** Started on  Sun Nov  1 23:30:26 2015 Afou Nacerdine
** Last update Tue Nov  3 22:03:46 2015 Afou Nacerdine
*/
#include <stdlib.h>
#include "./include/my.h"
#include "./include/bistromatique.h"

t_list_init    initmod_stock(t_list_init ini, char **str2, int i)
{
  ini.j = 0;
  ini.nb = nbmod(str2, i);
  ini.mod = malloc(sizeof(char *) * tablen(str2) + 1);
  ini.mod[ini.j] = malloc(my_strlen(str2[i - 1]));
  return (ini);
}

char    **initmod(char **str2, char **sum, int s, int i)
{
  t_list_init	ini;

  ini = initmod_stock(ini, str2, i);
  if (((i - 2) > 0 && str2[i - 2][0] == '/') ||
      ((i - 2) > 0 && str2[i - 2][0] == '*'))
    ini.mod[ini.j] = sum[s - 1];
  else
    ini.mod[ini.j] = str2[i - 1];
  ini.j = ini.j + 1;
  i = i + 2;
  if (ini.nb > 2)
    {
      while (str2[i] != NULL && str2[i][0] == '%')
        {
          ini.mod[ini.j] = malloc(my_strlen(str2[i - 1]));
          ini.mod[ini.j] = str2[i - 1];
          ini.j = ini.j + 1;
          i = i + 2;
        }
    }
  ini.mod[ini.j] = malloc(my_strlen(str2[i - 1]));
  ini.mod[ini.j] = str2[i - 1];
  return (ini.mod);
}
