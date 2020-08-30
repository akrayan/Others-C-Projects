/*
** tab.c for tab.c in /home/Rayan/Systeme_Unix/PSU_2015_minishell1
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Thu Jan 21 16:03:13 2016 AKKACHE Kaci
** Last update Sun Jan 24 22:26:31 2016 AKKACHE Kaci
*/

#include "./mini_shell.h"

int	nb_l(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 1;
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
	nb = nb + 1;
      i = i + 1;
    }
  return (nb);
}

char	**tab_for_shell(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  i = 0;
  k = 0;
  tab = malloc(sizeof(char *) * (nb_l(str) + 1));
  while (str[i] != '\0')
    {
      tab[k] = malloc(sizeof(char) * (my_strlen(str) + 1));
      while (str[i] == ' ')
	i = i + 1;
      j = 0;
      while (str[i] != ' ' && str[i] != '\0')
	{
	  tab[k][j] = str[i];
	  i = i + 1;
	  j = j + 1;
	}
      tab[k][j] = '\0';
      k = k + 1;
    }
  tab[k] = NULL;
  return (tab);
}

int	nb_dbpoint(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 1;
  while (str[i] != '\0')
    {
      if (str[i] == ':')
	nb = nb + 1;
      i = i + 1;
    }
  return (nb);
}

char	**tab_for_path(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  i = 5;
  k = 0;
  tab = malloc(sizeof(char *) * nb_dbpoint(str) + 1);
  while (str[i] != '\0')
    {
      tab[k] = malloc(sizeof(char) * my_strlen(str) + 1);
      while (str[i] == ':')
	i = i + 1;
      j = 0;
      while (str[i] != ':' && str[i] != '\0')
	{
	  tab[k][j] = str[i];
	  i = i + 1;
	  j = j + 1;
	}
      k = k + 1;
    }
  tab[k] = NULL;
  return (tab);
}

char	**get_path(char **env)
{
  char	**bin;
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      if (env[i][0] == 'P' && env[i][1] == 'A')
	bin = tab_for_path(env[i]);
      i = i + 1;
    }
  return (bin);
}
