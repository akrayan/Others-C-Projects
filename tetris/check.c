/*
** check.c for check.c in /home/Rayan/test/tetris
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Mar  6 06:17:28 2016 AKKACHE Kaci
** Last update Sun Mar  6 06:18:19 2016 AKKACHE Kaci
*/

#include "./tetris.h"

int		is_ok(t_tet tet, char **t, int tl)
{
  int	i;
  int	j;

  j = 0;
  if (tet.y + tab_len(tet.t) > tl - 1)
    return (1);
  while (tet.t[j] != NULL)
    {
      i = 0;
      while (tet.t[j][i] != '\0')
	{
	  if (tet.t[j][i] == '*')
	    {
	      if (t[j + tet.y + 1][i + tet.x] > 0)
		return (1);
	    }
	  i++;
	}
      j++;
    }
  return (0);
}

int		can_move_r(t_tet tet, char **t, int tc)
{
  int	i;
  int	j;

  j = 0;
  if (tet.x + my_strlen(tet.t[0]) > tc - 1)
    return (1);
  while (tet.t[j] != NULL)
    {
      i = 0;
      while (tet.t[j][i] != '\0')
	{
	  if (tet.t[j][i] == '*')
	    {
	      if (t[j + tet.y][i + tet.x + 1] > 0)
		return (1);
	    }
	  i++;
	}
      j++;
    }
  return (0);
}

int		can_move_l(t_tet tet, char **t)
{
  int	i;
  int	j;

  j = 0;
  if (tet.x == 0)
    return (1);
  while (tet.t[j] != NULL)
    {
      i = 0;
      while (tet.t[j][i] != '\0')
	{
	  if (tet.t[j][i] == '*')
	    {
	      if (t[j + tet.y][i + tet.x - 1] > 0)
		return (1);
	    }
	  i++;
	}
      j++;
    }
  return (0);
}
