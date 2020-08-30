/*
** my_epur_str.c for  in /home/scaduto/PSU_2015_42sh/lib
**
** Made by Scaduto
** Login   <scaduto@epitech.net>
**
** Started on  Mon May 23 14:21:33 2016 Scaduto
** Last update Thu May 26 21:16:32 2016 VELLA CYRIL
*/

#include "../include/minishell.h"

char    *epur_str(char *str, int i)
{
  t_list        a;

  a.i = -1;
  if (str[i + 1] == ' ' || str[i + 1] == '\t')
    {
      while (str[i + 1] == ' ' || str[i + 1] == '\t')
	i++;
    }
  while (str[++i])
    {
      str[++a.i] = str[i];
      if (str[i] == ' ' || str[i] == '\t')
	{
	  while (str[i] == ' ' || str[i] == '\t')
	    i++;
	  i--;
	}
    }
  if (str[a.i] == ' ' || str[a.i] == '\t')
    str[a.i] = '\0';
  else
    str[++a.i] = '\0';
  return (str);
}
