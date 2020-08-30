/*
** rev_wstr.c for  in /home/scaduto/PSU_2015_42sh/lib
**
** Made by Scaduto
** Login   <scaduto@epitech.net>
**
** Started on  Tue May 31 11:49:31 2016 Scaduto
** Last update Tue May 31 11:50:17 2016 Scaduto
*/

#include "../include/minishell.h"


void	rev_wstr(char *s, int first)
{
  int	start;
  int	i;

  i = 0;
  if (s[i])
    {
      while (s[i] && (s[i] == ' ' || s[i] == '\t'))
	i++;
      if (!s[i])
	return ;
      start = i;
      while (s[i] && s[i] != ' ' && s[i] != '\t')
	i++;
      rev_wstr(&s[i], 0);
      write(1, &s[start], i - start);
      if (!first)
	write(1, " ", 1);
    }
}
