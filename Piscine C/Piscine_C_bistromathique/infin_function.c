/*
** infin_function.c for infin_function.c in /home/afou_n/rendu/Piscine_C_evalexpr
** 
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
** 
** Started on  Fri Oct 30 15:00:54 2015 Afou Nacerdine
** Last update Tue Nov  3 22:01:34 2015 Afou Nacerdine
*/

#include <stdlib.h>
#include "./include/my.h"
#include "./include/bistromatique.h"

char    *infin_addpositiv(char *s1 ,char *s2)
{
  int	size;
  char	*s3;
  int	i;
  int	ret;

  i = 0;
  s3 = malloc(sizeof(char) * (my_strlen(s1) + 2));
  while (i != my_strlen(s1) + 1)
    {
      ret = 48;
      while ((s1[i] + s2[i] - ret) > 57)
        {
          s3[i] = s1[i] + s2[i] - ret - 10;
          i = i + 1;
          ret = 47;
        }
      s3[i] = s1[i] + s2[i] - ret;
      i = i + 1;
    }
  i = i - 1;
  if ((s1[i - 1] + s2[i - 1] - ret) > 57)
    s3[i] = '1';
  s3 = my_deletez(s3);
  return (s3);
}

char    *infin_doubleneg(char *s1 ,char *s2)
{
  int	size;
  char	*s3;
  int	i;
  int	ret;

  i = 0;
  s3 = malloc(sizeof(char) * (my_strlen(s1) + 2));
  while (i != my_strlen(s1) + 1)
    {
      ret = 48;
      while ((s1[i] + s2[i] - ret) > 57)
        {
          s3[i] = s1[i] + s2[i] - ret - 10;
          i = i + 1;
          ret = 47;
        }
      s3[i] = s1[i] + s2[i] - ret;
      i = i + 1;
    }
  i = i - 1;
  if ((s1[i - 1] + s2[i - 1] - ret) > 57)
    s3[i] = '1';
  s3 = my_deletez(s3);
  (s3[i - 1] == '1') ? (s3[i] = '-') : (s3[i - 1] = '-');
  return (s3);
}

char    *infin_addneg(char *s1 ,char *s2)
{
  char	*s3;
  int	i;
  int	ret;

  i = 0;
  s3 = malloc(sizeof(char) * (my_strlen(s1) + 2));
  ret = 0;
  while (i != my_strlen(s1) + 1)
    {
      if (s1[i] >= (s2[i] + ret))
        {
          s3[i] = s1[i] - (s2[i] + ret) + 48 ;
          ret = 0;
        }
      else
        {
          s3[i] =(s1[i] + 10 ) - (s2[i] + ret) + 48;
          ret = 1;
        }
      i = i + 1;
    }
  my_deletez(s3);
  return (s3);
}

char	*sum(char **tab, int size)
{
  int	i;
  char	*result;

  result = malloc(sizeof(char) * (size + 1));
  result[0] = '0';
  result[1] = '\0';
  i = 0;
  while (tab[i] != NULL)
    {
      tab[i] = my_deletez(tab[i]);
      result = infin_add(result,my_revstr(tab[i]));
      i = i + 1;
    }
  return (result);
}
