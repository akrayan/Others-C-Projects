/*
** bsq.c for bsq.c in /home/Rayan/Prog_Elem/CPE_2015_BSQ
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Dec 13 21:51:09 2015 AKKACHE Kaci
** Last update Tue Dec 15 11:05:26 2015 AKKACHE Kaci
*/

#include <stdlib.h>
#include "./bsq.h"
#include "./my.h"

t_c	function(t_c c, char **t)
{
  while (c.r == 0)
    {
      c.j = c.sqr.y;
      while (c.j < (c.n + c.sqr.y) && c.r == 0)
	{
	  c.i = c.sqr.x;
	  if (t[c.j] == NULL)
	    c.r = 1;
	  else
	    {
	      while (c.i < (c.n + c.sqr.x) && c.r == 0)
		{
		  if (t[c.j][c.i] == 'o' || t[c.j][c.i] == '\0')
		    c.r = 1;
		  c.i = c.i + 1;
		}
	    }
	  c.j = c.j + 1;
	}
      if (c.r == 1)
	c.sqr.t = c.n - 1;
      c.n = c.n + 1;
    }
  return (c);
}

t_sqr	check_t(int i, int j, char **t)
{
  t_c	c;

  c.n = 1;
  c.r = 0;
  c.j = j;
  c.i = i;
  c.sqr.x = i;
  c.sqr.y = j;
  if (t[c.j][c.i] == 'o')
    {
      c.r = 1;
      c.sqr.t = -1;
    }
  c = function(c, t);
  return (c.sqr);
}

t_sqr	search(char **t)
{
  t_sqr	sqr;
  int	i;
  int	j;

  j = 0;
  sqr.x = -1;
  sqr.y = -1;
  sqr.t = -1;
  while (t[j] != NULL)
    {
      i = 0;
      while (t[j][i] != '\0')
	{
	  if (sqr.t < check_t(i, j, t).t)
	    sqr = check_t(i, j, t);
	  i = i + 1;
	}
      j = j + 1;
    }
  return (sqr);
}

int	bsq(char **t)
{
  t_sqr sqr;
  int	i;
  int	j;

  sqr = search(t);
  j = 0;
  while (t[j] != NULL)
    {
      i = 0;
      while (t[j][i] != '\0')
	{
	  if (j >= sqr.y && j < (sqr.y + sqr.t) &&
	      i >= sqr.x && i < (sqr.x + sqr.t))
	    my_putchar('x');
	  else
	    my_putchar(t[j][i]);
	  i = i + 1;
	}
      if (t[j + 1] != NULL)
	my_putchar('\n');
      j = j + 1;
    }
  return (0);
}
