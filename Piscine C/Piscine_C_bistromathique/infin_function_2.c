/*
** infin_add_function.c for infin_add_function.c in /home/afou_n/rendu/Piscine_C_evalexpr
** 
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
** 
** Started on  Tue Oct 27 11:46:53 2015 Afou Nacerdine
** Last update Tue Nov  3 22:02:59 2015 Afou Nacerdine
*/
#include <stdlib.h>
#include "./include/my.h"
#include "./include/bistromatique.h"

char	*my_deletez(char *str)
{
  int	i;

  i = my_strlen(str);
  while ((str[i] <= '0') && ( i > 0))
    {
      str[i] = '\0';
      i = i - 1;
    }
  return (str);
}

t_list_param	checkparams_stock(char *s1, char *s2, t_list_param param)
{
  param.str1 = malloc(sizeof(char) * (my_strlen(s1) + 1));
  param.str2 = malloc(sizeof(char) * (my_strlen(s2) + 1));
  param.i = 0;
  while (param.i != my_strlen(s1))
    {
      param.str1[param.i] = s1[param.i];
      param.str2[param.i] = s2[param.i];
      param.i = param.i + 1;
    }
  param.i = 0;
  param.str1 = my_revstr(my_deletez(param.str1));
  param.str2 = my_revstr(my_deletez(param.str2));
  return (param);
}

int	checkparams(char *s1, char *s2)
{
  t_list_param	param;

  param = checkparams_stock(s1, s2, param);
  if (my_strlen(param.str1) > my_strlen(param.str2))
    return (1);
  else
    {
      while ((param.str1[param.i] <= param.str2[param.i]) ||
	     (my_strlen(param.str1) < my_strlen(param.str2)))
        {
          if (param.str1[param.i] < param.str2[param.i] ||
	      (my_strlen(param.str1) < my_strlen(param.str2)))
            return (0);
          param.i = param.i + 1;
        }
      return (1);
    }
}

char	*my_revcopy(char *str, int size)
{
  char  *scpy;
  int   i;

  str = my_revstr(str);
  scpy = malloc(sizeof(char) * (size + 1));
  i = 0;
  while (i != size)
    {
      if ((str[i] >= '0' && str[i] <= '9') && (i < my_strlen(str)))
        {
	  scpy[i] = str[i];
        }
      else
        scpy[i] = '0';
      i = i + 1;
    }
  scpy[i] = 0;
  return (scpy);
}
