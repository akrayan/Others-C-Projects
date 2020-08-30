/*
** my_strdup2.c for my_strdup2 in /home/scaduto/PSU_2015_42sh/lib
** 
** Made by scadut
** Login   <scaduto@scadut>
** 
** Started on  Wed Jun  1 13:48:46 2016 scadut
** Last update Wed Jun  1 15:00:37 2016 scadut
*/

#include "../include/minishell.h"

char	*strdup2(char *s1, char *s2)
{
  int	i;

  i = 0;
  if ((s1 = malloc(sizeof(char) * (my_strlen(s2) + 1))) == NULL)
    return (NULL);
  while (s2[i] != '\0')
    {
      s1[i] = s2[i];
      i++;
    }
  s1[i] = 0;
  return (s1);
}
