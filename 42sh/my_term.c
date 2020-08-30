/*
1;2802;0c** my_term.c for my_term in /home/vella_c/rendu/Systeme_Unix/PSU_2015_minishell2
**
** Made by VELLA CYRIL
** Login   <Cyril@epitech.net>
**
** Started on  Mon Apr  4 14:16:16 2016 VELLA CYRIL
** Last update Mon May 23 14:50:22 2016 Scaduto
*/

#include "include/minishell.h"

void	board(char **str)
{
  int	i;

  i = -1;
  while (str[++i] != NULL)
    {
      my_putstr(str[i]);
      write(1, "\n", 2);
    }
}

int	check_it(char **tab)
{
  int	i;

  i = -1;
  if (tab == NULL)
    return (0);
  while (tab[++i] != NULL);
  return (i);
}

char	**my_copy_env(char **env)
{
  char	**tab;
  t_list	a;

  a.i = -1;
  if ((tab = malloc(sizeof(char *) * (check_it(env) + 1))) == NULL)
    return (NULL);
  while (env[++a.i] != NULL)
    {
      a.r = -1;
      if ((tab[a.i] = malloc(sizeof(char) * (my_strlen(env[a.i]) + 2))) == NULL)
	return (NULL);
      while (env[a.i][++a.r] !='\0')
	tab[a.i][a.r] = env[a.i][a.r];
      tab[a.i][a.r] = '\0';
    }
  tab[a.i] = NULL;
  return (tab);
}

int	search_line(char **env, char *tab)
{
  t_list	a;

  a.i = -1;
  while (env[++a.i] && my_strncmp(env[a.i], tab, my_strlen(tab) - 1) != 0);
  if (env[a.i] == NULL)
    return (-1);
  return (a.i);
}
