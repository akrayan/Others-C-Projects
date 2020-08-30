/*
** fcn2.c for fcn2.c in /home/Rayan/Prog_Elem2/CPE_2015_Allum1
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Feb 21 09:28:41 2016 AKKACHE Kaci
** Last update Sun Feb 21 09:29:33 2016 AKKACHE Kaci
*/

#include "./include/allum.h"

int		snb_a(char **t)
{
  int		n;
  int		i;

  n = 0;
  i = 0;
  while (t[i] != NULL)
    {
      n = n + nb_a(t[i]);
      i++;
    }
  return (n);
}

char		check_s(char *s)
{
  char		i;

  i = 0;
  if (s[i] == '\0')
    return (0);
  while (s[i] != '\0')
    {
      if (s[i] < 48 || s[i] > 57)
	return (0);
      i++;
    }
  return (1);
}

t_index		matche(char **t, char *s, t_index id)
{
  id.n = my_getnbr(s);
  if (id.n > nb_a(t[id.i]))
    {
      id.i = 0;
      my_printf("Error: not enough matches on this line\n");
    }
  if (id.n == 0)
    {
      id.i = 0;
      my_printf("Error: you have to remove at least one match\n");
    }
  return (id);
}

t_index		line(char **t, char *s, t_index id, int l)
{
  id.i = my_getnbr(s);
  if (id.i < 1 || id.i > l)
    my_printf("Error: this line is out of range\n", id.i);
  else if (nb_a(t[id.i]) < 1)
    my_printf("Error: this line is empty\n");
  else
    {
      my_printf("Matches: ");
      s = read_st(0);
      if (check_s(s) == 0)
	{
	  my_printf("Error: invalid input (positive number expected)\n");
	  id.i = 0;
	}
      else
	id = matche(t, s, id);
    }
  return (id);
}

char		**p_turn(char **t, int l)
{
  t_index	id;
  char		*s;

  id.i = 0;
  id.n = 0;
  my_show_wordtab(t);
  my_printf("\nYour turn:\n");
  while (id.i < 1 || id.i > 4 || nb_a(t[id.i]) < 1)
    {
      my_printf("Line: ");
      s = read_st(0);
      if (check_s(s) == 0)
	my_printf("Error: invalid input (positive number expected)\n");
      else
	id = line(t, s, id, l);
    }
  my_printf("Player removed %d match(es) from line %d\n", id.n, id.i);
  t = r_allum(t, id.i, id.n);
  return (t);
}
