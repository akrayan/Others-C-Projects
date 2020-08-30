/*
** main.c for main.c in /home/Rayan/Colle/CPE_colle_semaine6
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue May 31 18:36:48 2016 AKKACHE Kaci
** Last update Tue May 31 21:55:26 2016 AKKACHE Kaci
*/

#include "./include/brain.h"

char	*init_ptr()
{
  int	i;
  char	*p;

  if ((p = malloc(32768)) == NULL)
    return (NULL);
  i = -1;
  while (++i < 32768)
    p[i] = 0;
  return (p);
}

char	*guil(char *pt)
{
  if (read(0, pt, 1) == - 1)
    return (NULL);
  return (pt);
}

int	c_par(char *s, char c)
{
  int	i;

  i = 0;
  while (s[i] != c && s[i] != '\0')
    i++;
  return (i);
}

t_s	init_tab(t_s s)
{
  s.par = "><+-.\'";
  s.t[0] = &sup;
  s.t[1] = &inf;
  s.t[2] = &add;
  s.t[3] = &moin;
  s.t[4] = &poin;
  s.t[5] = &guil;
  return (s);
}

int	main(int ac, char **av)
{
  t_s	s;

  if (ac > 1)
    {
      s = init_tab(s);
      if ((s.pt = init_ptr()) == NULL)
	return (0);
      if ((s.s = r_all(av[1])) == NULL)
	return (0);
      s.i = 0;
      while (s.s[s.i] != '\0')
	{
	  s.c = c_par(s.par, s.s[s.i]);
	  if (s.c < 6)
	    if ((s.pt = (*s.t[s.c])(s.pt)) == NULL)
	      return (0);
	  s.i++;
	}
      free(s.s);
      free(s.pt);
    }
  return (0);
}
