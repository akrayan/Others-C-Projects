/*
** str_cat.c for  in /home/axel/rendu/PSU_2015_minishell1
**
** Made by Axel Proust
** Login   <proust_c@epitech.net>
**
** Started on  Thu Jan 21 12:59:38 2016 Axel Proust
** Last update Thu Mar 17 14:58:32 2016 Axel Proust
*/

#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <assert.h>
#include <string.h>
#include "../tetris"

char	*str_copy2(char *dest, char *src)
{
  char	*retour;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((retour = malloc(sizeof(char) * (my_strlen(dest) +
				       my_strlen(src) + 1))) == NULL)
    return (NULL);
  while (dest[i])
    {
      retour[i] = dest[i];
      i++;
    }
  while (src[j])
    {
      retour[i] = src[j];
      i++;
      j++;
    }
  retour[i] = '\0';
  return (retour);
}

char	*str_copy(char *dest, char *src)
{
  char	*retour;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((retour = malloc(sizeof(char) * (my_strlen(dest) +
				       my_strlen(src) + 2))) == NULL)
    return (NULL);
  while (dest[i])
    {
      retour[i]= dest[i];
      i++;
    }
  retour[i] = '\n';
  i++;
  while (src[j])
    {
      retour[i]= src[j];
      i++;
      j++;
    }
  retour[i] = '\0';
  return (retour);
}

char	*str_copy3(char *dest, char *src)
{
  char	*retour;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((retour = malloc(sizeof(char) * (my_strlen(dest) +
				       my_strlen(src) + 2))) == NULL)
    return (NULL);
  while (dest[i])
    {
      retour[i]= dest[i];
      i++;
    }
  retour[i] = '/';
  i++;
  while (src[j])
    {
      retour[i]= src[j];
      i++;
      j++;
    }
  retour[i] = '\0';
  return (retour);
}
