/*
** clean.c for clean.c in /home/Rayan/Shell/PSU_2015_minishell2
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Wed Mar 30 13:38:16 2016 AKKACHE Kaci
** Last update Tue Apr 12 18:10:11 2016 AKKACHE Kaci
*/

#include "./include/shell.h"

int	c_s1(char *s)
{
  int	i;
  int	n;

  n = 0;
  i = 0;
  while (s[i] != '\0')
    {
      if (s[i] == '|' || s[i] == ';' || s[i] == '>' || s[i] == '<')
	{
	  if ((s[i] == '>' && s[i + 1] == '>') || (s[i] == '<' && s[i + 1] == '<'))
	    i++;
	  n = n + 1;
	}
      if (s[i] != '\0')
	i++;
    }
  return (n);
}

void	a_space2(char *s, char *s2, int *i, int *k)
{
  if ((s[*i] == '>' && s[*i + 1] == '>') || (s[*i] == '<' && s[*i + 1] == '<'))
    {
      s2[*k] = ' ';
      s2[*k + 1] = s[*i];
      s2[*k + 2] = s[*i + 1];
      s2[*k + 3] = ' ';
      *i = *i + 1;
      *k = *k + 3;
    }
  else
    {
      s2[*k] = ' ';
      s2[*k + 1] = s[*i];
      s2[*k + 2] = ' ';
      *k = *k + 2;
    }
}

char	*a_space(char *s)
{
  int	i;
  int	k;
  char	*s2;

  k = 0;
  i = 0;
  s2 = malloc((c_s1(s) * 2) + my_strlen(s) + 1);
  while (s[i] != '\0')
    {
      if (s[i] == '|' || s[i] == ';' || s[i] == '>' || s[i] == '<')
	a_space2(s, s2, &i, &k);
      else
	s2[k] = s[i];
      if (s[i] != '\0')
	{
	  i = i + 1;
	  k = k + 1;
	}
    }
  s2[k] = '\0';
  free(s);
  return (s2);
}

int	c_s2(char *s)
{
  int	i;
  int	k;

  i = 0;
  k = 0;
  while (s[i] == ' ')
    i++;
  while (i <= c_s3(s))
    {
      k++;
      i++;
      if (s[i - 1] == ' ')
	while (s[i] == ' ')
	  i++;
    }
  return (k);
}

char	*s_space(char *s)
{
  int	i;
  int	k;
  char	*s2;

  i = 0;
  k = 0;
  s = a_space(s);
  s2 = malloc(c_s2(s) + 1);
  while (s[i] == ' ')
    i++;
  while (i <= c_s3(s))
    {
      s2[k] = s[i];
      k++;
      i++;
      if (s[i - 1] == ' ')
	while (s[i] == ' ')
	  i++;
    }
  s2[k] = '\0';
  free(s);
  return (s2);
}
