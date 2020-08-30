/*
** my_strcmp.c for  in /home/axel/rendu/PSU_2015_minishell1
**
** Made by Axel Proust
** Login   <proust_c@epitech.net>
**
** Started on  Sat Jan 23 18:05:56 2016 Axel Proust
** Last update Sun Jan 24 18:10:40 2016 Axel Proust
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
#include "my.h"

int		my_strcmp(const char *s1, const char *s2)
{
  int		i;

  i = 0;
  while (s1[i] != '\0' || s2[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i = i + 1;
    }
  return (0);
}

int		my_strncmp(const char *s1, const char *s2, int nb)
{
  int		i;

  i = 0;
  while ((s1[i] != '\0' || s2[i] != '\0') && i < nb)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i = i + 1;
    }
  return (0);
}
