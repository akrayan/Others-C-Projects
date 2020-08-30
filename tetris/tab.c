/*
** tab.c for tab.c in /home/Rayan/test/tetris
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Mar  6 06:12:13 2016 AKKACHE Kaci
** Last update Wed Mar 23 11:06:19 2016 AKKACHE Kaci
*/

#include "./tetris.h"

char		**init_tab(int tl, int tc)
{
  int		i;
  int		j;
  char		**t;

  i = 0;
  t = malloc(sizeof(char *) * (tl + 1));
  while (i < tl)
    {
      j = 0;
      t[i] = malloc(tc + 1);
      while (j < tc)
	{
	  t[i][j] = -1;
	  j++;
	}
      t[i][j] = '\0';
      i++;
    }
  t[i] = NULL;
  return (t);
}

char		**past_tab(t_tet tet, char **t)
{
  int	i;
  int	j;

  j = tet.y;
  while (j < tab_len(tet.t) + tet.y)
    {
      i = tet.x;
      while (i < my_strlen(tet.t[0]) + tet.x)
	{
	  if (tet.t[j - tet.y][i - tet.x] == '*')
	    t[j][i] = tet.col;
	  i++;
	}
      j++;
    }
  return (t);
}

char		**sup_line(char **t, int j)
{
  while (j > 0)
    {
      t[j] = t[j - 1];
      j--;
    }
  while (t[0][j] != '\0')
    {
      t[0][j] = -1;
      j++;
    }
  return (t);
}

char		**check_line(char **t, int tl, char **t2, int s, int c)
{
  int	n;
  int	j;
  int	i;
  int	r;

  j = tl - 1;
  n = 0;
  while (j >= 0)
    {
      i = 0;
      r = 0;
      while (t[j][i] != '\0' && r == 0)
	{
	  if (t[j][i] == -1)
	    r = 1;
	  i++;
	}
      if (r == 1)
	j--;
      else
	{
	  n++;
	  t = sup_line(t, j);
	  score++;
	  if (lvl < 10)
	    lvl = lvl + 0.1;
	}
    }
  anim_atk(t, tl, n, t2, s, c);
  return (t);
}

void		free_tab(char **t)
{
  int		i;

  i = 0;
  while (t[i] != NULL)
    {
      free(t[i]);
      i++;
    }
  free(t);
}
