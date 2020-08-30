/*
** syntax_error.c for  in /home/zemmou_b/rendu/bistro1
** 
** Made by Billal Zemmouri
** Login   <zemmou_b@epitech.net>
** 
** Started on  Sun Nov  1 21:25:35 2015 Billal Zemmouri
** Last update Tue Nov  3 23:13:03 2015 AKKACHE Kaci
*/
#include "./include/bistromatique.h"

int	syntax_error(char *str)
{
  t_list_testtop cp;

  cp.i = 0;
  cp.parop = 0;
  cp.parcl = 0;
  while (str[cp.i] != 0)
    {
      if ((str[cp.i] == '/' && str[cp.i + 1] == '0') 
	  || (str[cp.i] >= '0' && str[cp.i] <= '9' && str[cp.i + 1]  == '('))
	{
	  SYNTAXE_ERROR_MSG;
	  return (1);
	}
      if (str[cp.i] == '(')
	cp.parop = cp.parop + 1;
      if (str[cp.i] == ')')
	cp.parcl =cp.parcl + 1;
      cp.i = cp.i + 1;
    }
  if (cp.parop != cp.parcl)
    {
      SYNTAXE_ERROR_MSG;
      return (1);
    }
  return (0);
}
