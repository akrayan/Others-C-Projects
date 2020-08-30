/*
** my_strncat.c for  in /home/scaduto/PSU_2015_42sh/lib
**
** Made by Scaduto
** Login   <scaduto@epitech.net>
**
** Started on  Mon May 23 14:32:35 2016 Scaduto
** Last update Mon May 23 14:51:32 2016 Scaduto
*/

#include "../include/minishell.h"

char    *my_strncat(char *str, char *str2, int n)
{
  int   i;
  char  *final;
  int   j;

  j = -1;
  i = -1;
  final = malloc(n + my_strlen(str2) + 1);
  if (my_strlen(str) < n)
    return (NULL);
  while (++i < n)
    final[i] = str[i];
  i = i - 1;
  while (str2[++j])
    final[++i] = str2[j];
  final[i] = 0;
  return (final);
}
