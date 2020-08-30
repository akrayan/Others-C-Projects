/*
** add_space.c for  in /home/zemmou_b/rendu/bistro1
** 
** Made by Billal Zemmouri
** Login   <zemmou_b@epitech.net>
** 
** Started on  Sun Nov  1 22:09:18 2015 Billal Zemmouri
** Last update Tue Nov  3 22:54:33 2015 AKKACHE Kaci
*/
#include <stdlib.h>
#include "./include/my.h"
#include "./include/bistromatique.h"

t_list_param add_stock(char *str, t_list_param par)
{

  par.copy = malloc(sizeof(char) * my_strlen(str) * 2);
  par.i = 0;
  par.j = 0;
  return (par);
}

char    *add_space(char *str)
{
  t_list_param par;

  par = add_stock(str, par);
  while (str[par.i] != '\0')
    {
      if (str[par.i] == '+'
          || str[par.i] == '*' || str[par.i] == '/' || str[par.i] == '%' ||
          (str[par.i] == '-' && str[par.i - 1] != '-' && str[par.i - 1] != '+'
	   && str[par.i - 1] != '*' && str[par.i - 1] != '/' 
	   && str[par.i - 1] != '(' ))
        {
          par.copy[par.j] = ' ';
          par.j = par.j + 1;
          par.copy[par.j] = str[par.i];
          par.j = par.j + 1;
          par.copy[par.j] = ' ';
        }
      else
        par.copy[par.j] = str[par.i];
      par.j = par.j + 1;
      par.i = par.i + 1;
    }
  return (par.copy);
}
