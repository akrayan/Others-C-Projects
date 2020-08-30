/*
** color.c for rt2 in /home/nasrat_v/rendu/Infographie/gfx_raytracer2/file_scene
**
** Made by
** Login   <nasrat_v@epitech.net>
**
** Started on  Sat May 21 17:33:33 2016
** Last update Sat May 21 19:07:10 2016 
*/

#include "../include/rt.h"

unsigned int	*macro_tab()
{
  unsigned int	*tab;

  if ((tab = malloc(sizeof(unsigned int) * 9)) == NULL)
    return (0);
  tab[0] = BLACK;
  tab[1] = WHITE;
  tab[2] = RED;
  tab[3] = GREEN;
  tab[4] = BLUE;
  tab[5] = TEAL;
  tab[6] = PURPLE;
  tab[7] = PINK;
  tab[8] = YELLOW;
  return (tab);
}

char		**str_tab()
{
  char		**tab;

  if ((tab = malloc(sizeof(char *) * 10)) == NULL)
    return (0);
  tab[0] = my_strdup("BLACK");
  tab[1] = my_strdup("WHITE");
  tab[2] = my_strdup("RED");
  tab[3] = my_strdup("GREEN");
  tab[4] = my_strdup("BLUE");
  tab[5] = my_strdup("TEAL");
  tab[6] = my_strdup("PURPLE");
  tab[7] = my_strdup("PINK");
  tab[8] = my_strdup("YELLOW");
  tab[9] = NULL;
  return (tab);
}

unsigned int	cmp_color(char *str)
{
  int		i;
  char		**tab;
  unsigned int	*int_tab;
  unsigned int	result;

  i = 0;
  int_tab = macro_tab();
  tab = str_tab();
  while (tab[i])
    {
      if (my_strcmp(str, tab[i]) == 0)
	{
	  result = int_tab[i];
	  return (result);
	}
      i += 1;
    }
  return (0);
}
