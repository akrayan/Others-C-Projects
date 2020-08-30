/*
** s_t_w.c for s_t_w.c in /home/Rayan/test/shell
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Apr 10 02:32:13 2016 AKKACHE Kaci
** Last update Sun Apr 10 02:35:28 2016 AKKACHE Kaci
*/

#include "./include/shell.h"

int	nbc2(char *s, char c, int k)
{
  int	i;

  i = 0;
  while (s[k] != '\0' && s[k] != c)
    {
      k++;
      i++;
    }
  return (i);
}

int	nbc(char *s, char c)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (s[i] != '\0')
    {
      if (s[i] == c)
	n++;
      i++;
    }
  return (n);
}

char	**s_t_w(char *s, char c)
{
  int	i;
  int	j;
  int	k;
  char	**t;

  j = 0;
  k = 0;
  t = malloc(sizeof(char *) * (nbc(s, c) + 2));
  while (j < nbc(s, c) + 1)
    {
      i = 0;
      t[j] = malloc(nbc2(s, c, k) + 1);
      while (s[k] != '\0' && s[k] != c)
	{
	  t[j][i] = s[k];
	  i++;
	  k++;
	}
      t[j][i] = '\0';
      k++;
      j++;
    }
  t[j] = NULL;
  return (t);
}
