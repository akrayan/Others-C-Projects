/*
** cmd_tab.c for cmd_tab.c in /home/Rayan/test/shell
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sat Apr  9 15:29:35 2016 AKKACHE Kaci
** Last update Sat Apr  9 15:31:58 2016 AKKACHE Kaci
*/

#include "./include/shell.h"

int	nbc4(char *s, int i)
{
  int	k;

  k = 0;
  if (!(s[i] == '|' || s[i] == '>' || s[i] == '<'
	|| s[i] == ';' || s[i] == '\0'))
    {
      while (!(s[i] == '|' || s[i] == '>' || s[i] == '<'
	       || s[i] == ';' || s[i] == '\0'))
	{
	  i++;
	  k++;
	}
      k--;
    }
  else
    {
      while (s[i] == '|' || s[i] == '>' || s[i] == '<'|| s[i] == ';')
	{
	  i++;
	  k++;
	}
    }
  return (k);
}

int	nbc3(char *s)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (s[i] != '\0')
    {
      if (s[i] == '|' || s[i] == '>' || s[i] == '<'|| s[i] == ';')
	{
	  n++;
	  while (s[i++] == '|' || s[i] == '>' || s[i] == '<'|| s[i] == ';');
	}
      else if (!(s[i] == '|' || s[i] == '>' || s[i] == '<'|| s[i] == ';'
		 || s[i] == ' ' || s[i] == '\0'))
	{
	  n++;
	  while (s[i] != '|' && s[i] != '>' && s[i] != '<'
		 && s[i] != ';' && s[i] != '\0')
	    i++;
	  i--;
	}
      if (s[i] != '\0')
	i++;
    }
  return (n);
}

char	*cmd_tab2(char *s, char *t, int *i, int *k)
{
  int	j;
  int	l;

  j = *i;
  l = *k;
  while (!(s[l] == '|' || s[l] == '>' || s[l] == '<'
	   || s[l] == ';' || s[l] == '\0'))
    {
      t[j] = s[l];
      l++;
      j++;
    }
  if (s[l] != '\0')
    {
      l--;
      j--;
    }
  *i = j;
  *k = l;
  return (t);
}

char	*cmd_tab3(char *s, char *t, int *i, int *k)
{
  int	j;
  int	l;

  j = *i;
  l = *k;
  while (s[l] == '|' || s[l] == '>' || s[l] == '<'|| s[l] == ';')
    {
      t[j] = s[l];
      l++;
      j++;
    }
  *i = j;
  *k = l;
  return (t);
}

char	**cmd_tab(char *s)
{
  int	i;
  int	j;
  int	k;
  char	**t;

  j = 0;
  k = 0;
  t = malloc(sizeof(char *) * (nbc3(s) + 1));
  while (j < nbc3(s))
    {
      i = 0;
      while (s[k] == ' ')
	k++;
      t[j] = malloc(nbc4(s, k) + 1);
      if (s[k] == '|' || s[k] == '>' || s[k] == '<' || s[k] == ';')
	t[j] = cmd_tab3(s, t[j], &i, &k);
      else if (!(s[k] == '|' || s[k] == '>' || s[k] == '<'
		 || s[k] == ';' || s[k] == ' ' || s[k] == '\0'))
	t[j] = cmd_tab2(s, t[j], &i, &k);
      t[j][i] = '\0';
      j++;
    }
  t[j] = NULL;
  return (t);
}
