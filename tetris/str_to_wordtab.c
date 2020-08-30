/*
** str_to_wordtab.c for  in /home/axel/rendu/CPE_2015_BSQ
**
** Made by proust axel
** Login   <proust_c@epitech.net>
**
** Started on  Fri Dec 18 17:16:07 2015 proust axel
** Last update Wed Mar 16 03:40:17 2016 AKKACHE Kaci
*/

#include "tetris.h"

int	my_show_wordtab(char **tab)
{
  int	n;
  int	i;

  i = -1;
  n = 0;
  while (tab[n] != '\0')
    {
      my_putstr(tab[n]);
      my_putchar('\n');
      n = n + 1;
    }
  return (0);
}

int	count_line(char *str, char sep)
{
  int	compteur;
  int	result;

  compteur = 0;
  result = 1;
  while (str[compteur])
    {
      if (str[compteur] == sep)
	result += 1;
      compteur++;
    }
  return (result);
}

char	**str_to_wordtab(char *str, char sep)
{
  int	i;
  int	column;
  int	line;
  char	**tab;

  if ((tab = malloc(((count_line(str, sep) + 1) * sizeof(char *)))) == NULL)
    return (NULL);
  i = count_line(str, sep);
  column = -1;
  line = -1;
  while (++column < i)
    {
      tab[column] = &str[++line];
      while (str[++line] != sep && str[line] != 0);
      str[line] = 0;
    }
  tab[column] = NULL;
  return (tab);
}
