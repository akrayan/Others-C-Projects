/*
** my_strcat.c for my_strcat in /home/vella_c/rendu/Systeme_Unix/PSU_2015_minishell2
**
** Made by VELLA CYRIL
** Login   <Cyril@epitech.net>
**
** Started on  Mon Apr 11 17:52:19 2016 VELLA CYRIL
** Last update Mon May 23 14:51:21 2016 Scaduto
*/

#include "../include/minishell.h"

char	*my_strcat(char *str, char *str1)
{
  char	*final;
  t_list	a;

  a.i = -1;
  a.r = -1;
  while (str[++a.i] != '\0');
  while (str1[++a.r] != '\0');
  a.i = a.i + a.r;
  if ((final = malloc(sizeof(char) * (a.i + 1))) == NULL)
    return (NULL);
  a.i = -1;
  a.r = -1;
  while (str[++a.i])
    final[a.i] = str[a.i];
  a.i = a.i - 1;
  while (str1[++a.r])
    final[++a.i] = str1[a.r];
  final[++a.i] = '\0';
  return (final);
}

char    *my_strcpy(char *str, char *str1)
{
  int   i;

  i = -1;
  if ((str = malloc(my_strlen(str1) + 1)) == NULL)
    return (NULL);
  while (str1[++i])
    str[i] = str1[i];
  str[i] = 0;
  return (str);
}

char    *my_strdup(char *str)
{
  char  *copy;

  if ((copy = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  copy = my_strcpy(copy, str);
  copy[my_strlen(str)] = '\0';
  return (copy);
}

char    *my_strcpycat(char *str, char *buffer)
{
  char  *copy;
  t_list        a;

  a.i = 0;
  if ((copy = malloc(sizeof(char) *
		     (my_strlen(str) + my_strlen(buffer) + 2))) == NULL)
    return (NULL);
  while (str[a.i])
    {
      copy[a.i] = str[a.i];
      a.i++;
    }
  copy[a.i++] = '/';
  a.r = 0;
  while (buffer[a.r])
    {
      copy[a.i] = buffer[a.r];
      a.i++;
      a.r++;
    }
  copy[a.i] = '\0';
  return (copy);
}

char    *check_access(char **tab_path, char *str)
{
  t_list        a;
  char  *copy;

  a.i = 0;
  if (str[0] == '\0')
    return (NULL);
  while (tab_path[a.i])
    {
      copy = my_strcpycat(tab_path[a.i], str);
      if (access(copy, F_OK) == 0)
	return (copy);
      ++a.i;
    }
  return (NULL);
}
