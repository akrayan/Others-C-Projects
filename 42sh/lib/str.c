/*
** my_strcmp.c for my_strcnmp in /home/vella_c/rendu/Systeme_Unix/PSU_2015_minishell2
**
** Made by VELLA CYRIL
** Login   <Cyril@epitech.net>
**
** Started on  Wed Apr  6 14:48:41 2016 VELLA CYRIL
** Last update Mon May 30 11:46:53 2016 Scaduto
*/

#include "../include/minishell.h"

char	my_putchar(char c)
{
  write(1, &c, 1);
  return(c);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] !='\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (i);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] !='\0')
    i++;
  return (i);
}

int	my_strcmp(char *str, char *str1)
{
  int	i;

  i = 0;
  while (str[i] && str1[i])
    {
      if (str[i] > str1[i])
	return (1);
      if (str[i] < str1[i])
	return (-1);
      i++;
    }
  if (str[i] == 0 && str1[i] != 0)
    return (-1);
  else if (str1[i] == 0 && str[i] != 0)
    return (1);
  return (0);
}

int     my_strncmp(char *str, char *str1, int n)
{
  int   i;
  int   count;

  i = 0;
  count = -1;
  if (str == NULL || str1 == NULL)
    return(-1);
  while (str[i] && str1[i] && ++count < n)
    {
      if (str[i] > str1[i])
	return (1);
      if (str[i] < str1[i])
	return (-1);
      i++;
    }
  if (str[i] == 0 && str1[i] != 0)
    return (-1);
  else if (str1[i] == 0 && str[i] != 0)
    return (1);
  return (0);
}
