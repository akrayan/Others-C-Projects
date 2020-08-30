/*
** read_tetri2.c for  in /home/axel/rendu/PSU/PSU_2015_tetris
**
** Made by Axel Proust
** Login   <proust_c@epitech.net>
**
** Started on  Tue Mar  1 13:57:48 2016 Axel Proust
** Last update Sun Mar 20 18:48:23 2016 Axel Proust
*/

#include "tetris.h"

int             check_larg(t_te *te)
{
  int           line;
  int           col;
  int           c;

  line = 1;
  col = 0;
  c = 0;
  while (te->tab_tetri[line])
    {
      if (my_strlen(te->tab_tetri[line]) > c)
	c = my_strlen(te->tab_tetri[line]);
      line++;
    }
  return (c);
}

char    *my_copy_nb(char *str, int nb, int dep)
{
  int           i;
  char          *result;
  int           x;

  i = dep;
  x = 0;
  if ((result = malloc(sizeof(char) * nb + 1)) == NULL)
    return (NULL);
  while (i < nb)
    {
      result[x] = str[i];
      i++;
      x += 1;
    }
  result[x] = '\0';
  return (result);
}

int             check_taille2(t_te *te, char *str)
{
  int           line;
  int           col;

  line = 1;
  col = 0;
  te->tetrim = my_strdup(str);
  te->tab_tetri = str_to_wordtab(str, '\n');
  if ((te->longu != (tab_len(te->tab_tetri) - 1)))
    return (-1);
  if (check_larg(te) != te->larg)
    return (-1);
  return (0);
}

int             check_taille(char *str)
{
  int           i;
  t_te         *te;
  int           n;
  int           dep;

  i = -1;
  n = 0;
  dep = 0;
  if ((te = malloc(sizeof(t_te))) == NULL)
    return (-1);
  while (str[++i])
    {
      if (str[i] == ' ' && n == 0)
	{
	  te->larg = my_getnbr(my_copy_nb(str, i, dep));
	  n = 1;
	  dep = i + 1;
	}
      else if (str[i] == ' ' && n == 1)
	{
	  te->longu = my_getnbr(my_copy_nb(str, i, dep));
	  n++;
	  dep = i + 1;
	}
      else if (str[i] == '\n' && n > 1)
	if (check_taille2(te, str) == -1)
	  return (-1);
    }
  return (1);
}
