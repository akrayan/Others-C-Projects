/*
** gestion_av.c for  in /home/axel/rendu/PSU/tetris_dossier/tetris_presque_definitif/debug
**
** Made by Axel Proust
** Login   <proust_c@epitech.net>
**
** Started on  Fri Mar 18 15:39:59 2016 Axel Proust
** Last update Sun Mar 20 16:13:00 2016 Axel Proust
*/

#include "../tetris.h"

int		check_d(char **av)
{
  int		i;

  i = -1;
  while (++i < tab_len(av))
    {
      if (strcmp(av[i], "-d") == 0)
	return (0);
    }
  return (-1);
}

char    **copy_tableau(char **tab2)
{
  char  **tab;
  int   j;
  int   i;

  i = 0;
  j = 0;
  if ((tab = malloc(sizeof(char *) * (tab_len(tab2) + 1))) == NULL)
    return (NULL);
  while (tab2[j] != NULL)
    {
      if ((tab[j] = malloc(sizeof(char) *
			   (my_strlen(tab2[j]) + 1))) == NULL)
	return (NULL);
      while (tab2[j][i] != '\0')
	{
	  tab[j][i] = tab2[j][i];
	  i += 1;
	}
      tab[j][i] = '\0';
      i = 0;
      j += 1;
    }
  tab[j] = NULL;
  return (tab);
}

char		**look_for_d(char **av)
{
  int		i;
  int		n;
  char		**tab;

  i = -1;
  n = 0;
  tab = copy_tableau(av);
  while (++i < (tab_len(tab) - 1))
    {
      if (strcmp(tab[i], "-d") == 0)
	{
	  n = 1;
	  while (i < tab_len(tab) - 1)
	    {
	      tab[i] = tab[i + 1];
	      i++;
	    }
	}
    }
  if (n == 1)
    {
      tab[i - 1] = my_strdup("-d");
      tab[i] = "\0";
    }
  return (tab);
}

int             clear_commande(t_opt *opt)
{
  int           i;

  i = -1;
  if (opt->commande[my_strlen(opt->commande) - 1] == '=')
    return (-1);
  else
    {
      while (opt->commande[++i] && opt->commande[i] != '=');
      if (opt->commande[i] != 0)
	opt->commande[i + 1] = '\0';
      return (0);
    }
}

int		check_av(char **tab)
{
  int		i;
  int		c;

  i = 0;
  c = 1;

  while (c < tab_len(tab) - 1)
    {
      while (tab[++i])
	{
	  if (i != tab_len(tab) && c == i)
	    i++;
	  if (strcmp(tab[c], tab[i]) == 0)
	    return (-1);
	}
      i = 0;
      c++;
    }
  return (0);
}
