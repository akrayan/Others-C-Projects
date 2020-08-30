/*
** my_str_to_wordtab.c for rt2 in /home/nasrat_v/rendu/Infographie/gfx_raytracer2/file_scene
**
** Made by
** Login   <nasrat_v@epitech.net>
**
** Started on  Sat May 21 16:45:46 2016
** Last update Mon May 23 00:49:38 2016 AKKACHE Kaci
*/

#include "../include/rt.h"

int	nb_mot(char *str, char sep)
{
  int	i;
  int	nb;

  i = 0;
  nb = 1;
  while (str[i] != 0)
    {
      if (str[i] == sep)
	nb = nb + 1;
      i = i + 1;
    }
  return (nb);
}

int	nb_mot_bis(char *str, char sep1, char sep2)
{
  int	i;
  int	nb;

  i = 0;
  nb = 1;
  while (str[i] != 0)
    {
      if (str[i] == sep1 && str[i + 1] == sep2)
	nb = nb + 1;
      i = i + 1;
    }
  return (nb);
}

char	**my_str_to_wordtab(char *str, char sep)
{
  char	**tab;
  int	i;
  int	j;

  write(1, "a", 1);
  if ((tab = malloc((nb_mot(str, sep) + 1) * sizeof(char*))) == NULL)
    return (NULL);
  write(1, "a", 1);
  tab[nb_mot(str, sep)] = NULL;
  i = 0;
  j = 1;
  tab[0] = str;
  write(1, "a", 1);
  while (str[i] != 0)
    {
      if (str[i] == sep)
	{
	  str[i] = 0;
	  i = i + 1;
	  tab[j] = &str[i];
	  j = j + 1;
	}
      i = i + 1;
    }
  return (tab);
}

char	**my_str_to_wordtab_bis(char *str, char sep1, char sep2)
{
  char	**tab;
  int	i;
  int	j;

  if ((tab = malloc((nb_mot_bis(str, sep1, sep2) + 1) * sizeof(char*))) == NULL)
    return (NULL);
  tab[nb_mot_bis(str, sep1, sep2)] = NULL;
  i = 0;
  j = 1;
  tab[0] = str;
  while (str[i] != 0)
    {
      if (str[i] == sep1 && str[i + 1] == sep2)
	{
	  str[i] = 0;
	  i = i + 1;
	  tab[j] = &str[i + 1];
	  j = j + 1;
	}
      i = i + 1;
    }
  return (tab);
}

void	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      if (tab[i + 1] != NULL)
	write(1, "\n", 1);
      i += 1;
    }
}
