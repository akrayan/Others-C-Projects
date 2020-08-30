/*
** str_to_wordtab.c for my_str_to_wordtab in /home/vella_c/rendu/Systeme_Unix/PSU_2015_minishell2
**
** Made by VELLA CYRIL
** Login   <Cyril@epitech.net>
**
** Started on  Mon Apr 11 13:41:16 2016 VELLA CYRIL
** Last update Mon May 23 14:52:35 2016 Scaduto
*/

#include "../include/minishell.h"

int	find_word_in_env(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 1;
  while (str[i] != 0)
    {
      if (str[i] == ':' && str[i+1] != '\n')
	nb++;
      i++;
    }
  return (nb);
}

char	**str_to_wordtab_env(char *str)
{
  char	**tab;
  t_list	a;

  if ((tab = malloc((find_word_in_env(str) + 1) * sizeof(char*))) == NULL)
    return (NULL);
  tab[find_word_in_env(str)] = NULL;
  a.i = 0;
  a.r = 1;
  tab[0] = str;
  while (str[a.i] != 0)
    {
      if (str[a.i] == ':' && str[a.i + 1] != '\n')
	{
	  str[a.i] = 0;
	 a.i++;
	  tab[a.r] = &str[a.i];
	  a.r++;
	}
      a.i++;
    }
  return (tab);
}

char	**str_to_wordtab_pathname(char **tab)
{
  int	i;
  char	*copy;

  i = 0;
  while (tab[i])
    {
      if (tab[i][0] == 'P' && tab[i][1] == 'A'
	  && tab[i][2] == 'T' && tab[i][3] == 'H')
	copy = my_strdup(tab[i] + 5);
      i++;
    }
  return (str_to_wordtab_env(copy));
}

char    **my_alloc_tab(char *str, char **tab)
{
  t_list        a;

  a.i = -1;
  a.r = 1;
  while (str[++a.i + 1])
    {
      if (str[a.i] == ' ' && str[a.i + 1] != ' ')
	a.r++;
    }
  if ((tab = malloc(sizeof(char *) * (a.r + 1))) == NULL)
    return (NULL);
  return(tab);
}

char    **my_str_to_wordtab(char *str)
{
  char  **tab;
  t_list        a;

  a.i = -1;
  tab = NULL;
  str = epur_str(str, -1);
  tab = my_alloc_tab(str, tab);
  while (str[++a.i + 1])
    {
      if (str[a.i] == ' '&& str[a.i + 1] != ' ')
	str[a.i] = 0;
    }
  a.r = a.i + 1;
  a.i = -1;
  a.z = -1;
  while (str[++a.i] && a.i < a.r)
    {
      tab[++a.z] = str + a.i;
      while (str[a.i])
	a.i++;
    }
  tab[++a.z] = NULL;
  return (tab);
}
