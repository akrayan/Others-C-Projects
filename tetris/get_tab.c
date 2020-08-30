/*
** get_tab.c for get_tab.c in /home/Rayan/PSU_2015_tetris
**
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
**
** Started on  Wed Mar 16 03:16:12 2016 AKKACHE Kaci
** Last update Tue Mar 22 01:37:16 2016 AKKACHE Kaci
** Last update Fri Mar 18 12:54:27 2016 AKKACHE Kaci
*/

#include "tetris.h"

t_get	get_w(char *b, t_get g)
{
  int	n;
  int	k;
  char	*s;

  k = 0;
  while (b[k] != ' ')
    k++;
  s = malloc(k + 1);
  while (b[g.i] != ' ')
    {
      s[g.i] = b[g.i];
      g.i++;
    }
  s[g.i] = '\0';
  g.cl = my_getnbr(s);
  free(s);
  return (g);
}

t_get	get_h(char *b, t_get g)
{
  int	n;
  int	k;
  char	*s;

  k = 0;
  n = 0;
  while (b[g.i] == ' ')
    g.i++;
  while (b[k] != ' ')
    k++;
  s = malloc(k + 1);
  while (b[g.i] != ' ')
    {
      s[n] = b[g.i];
      n++;
      g.i++;
    }
  s[n] = '\0';
  g.l = my_getnbr(s);
  free(s);
  return (g);
}

t_get	get_c(char *b, t_get g)
{
  int	n;
  int	k;
  char	*s;

  k = 0;
  n = 0;
  while (b[g.i] == ' ')
    g.i++;
  while (b[k] != '\n')
    k++;
  s = malloc(k + 1);
  while (b[g.i] != '\n')
    {
      s[n] = b[g.i];
      n++;
      g.i++;
    }
  s[n] = '\0';
  g.c = my_getnbr(s);
  free(s);
  return (g);
}

int		have_ptet(char *s, int i)
{
  int		r;
  int		k;
  char		*s2;

  r = 1;
  s2 = ".tetrimino";
  while (s[i] != '\0')
    {
      r = 1;
      k = 0;
      if (s[i] == '.')
	{
	  while (s[k + i] != '\0' && s2[k] != '\0' && r == 1)
	    {
	      if (s[k + i] != s2[k])
		r == 0;
	      k++;
	    }
	  if (k == my_strlen(s2) && s[k + i] == '\0' && r == 1)
	    return (1);
	}
      i++;
    }
  return (0);
}

int		have_ptet2(char *s, int i)
{
  int		r;
  int		k;
  char		*s2;

  r = 1;
  s2 = ".tetrimino";
  k = 0;
  if (s[i] == '.')
    {
      while (s[k + i] != '\0' && s2[k] != '\0' && r == 1)
	{
	  if (s[k + i] != s2[k])
	    r == 0;
	  k++;
	}
      if (k == my_strlen(s2) && s[k + i] == '\0' && r == 1)
	return (1);
    }
  return (0);
}

char	*cut_s(char *s)
{
  int	k;
  int	i;
  char	*s2;

  k = 0;
  while (s[k] != '\0' && have_ptet2(s, k) == 0)
    k++;
  if ((s2 = malloc(k + 1)) == NULL)
    return (NULL);
  i = 0;
  while (s[i] != '\0' && have_ptet2(s, i) == 0)
    {
      s2[i] = s[i];
      i++;
    }
  s2[i] = '\0';
  return (s2);
}

char	**get_tab2(char *t1, t_get g)
{
  int	j;
  int	i;
  char	*s;
  char	**t;

  i = g.i;
  while (t1[i] != '\0')
    i++;
  if ((s = malloc(i + 1 - g.i)) == NULL)
    return (NULL);
  i = 0;
  while (t1[g.i] != '\0')
    {
      s[i] = t1[g.i];
      i++;
      g.i++;
    }
  s[i] = '\0';
  t = str_to_wordtab(s, '\n');
  j = -1;
  while (t[++j] != NULL)
    {
      i = my_strlen(t[j]) - 1;
      while (i >= 0 && t[j][i] != '*')
	{
	  t[j][i] = '\0';
	  i--;
	}
    }
  return (t);
}

int	check_tet(t_get g, char *s)
{
  int	j;
  int	i;
  int	l;

  j = -1;
  while (g.t[++j] != NULL)
    {
      i = my_strlen(g.t[j]);
      while (--i >= 0 && g.t[j][i] != '*')
	{
	  if (g.t[j][i] != 42 && g.t[j][i] != 32 && g.t[j][i] < 48 && g.t[j][i] > 57)
	    return (0);
	}
      if (i > g.c)
	return (0);
      while (--i >= 0)
	{
	  if (g.t[j][i] != 42 && g.t[j][i] != 32 && g.t[j][i] < 48 && g.t[j][i] > 57)
	    return (0);
	}
    }
  if (j > g.l)
    return (0);
  return (1);
}

int	is_sup(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] > s2[i])
	return (1);
      else if (s1[i] < s2[i])
	return (0);
      i++;
    }
  if (s2[i] == '\0')
    return (1);
  return (0);
}

t_get	*tri_g(t_get *g)
{
  int	j;
  int	i;
  int	l;
  t_get	s;

  l = g[0].len;
  j = 0;
  while (j < l)
    {
      i = 0;
      while (i < l - 1)
	{
	  if (is_sup(g[i].n, g[i + 1].n) == 1)
	    {
	      s.n = g[i].n;
	      s.t = g[i].t;
	      s.l = g[i].l;
	      s.cl = g[i].cl;
	      s.c = g[i].c;
	      s.i = g[i].i;
	      g[i].n = g[i + 1].n;
	      g[i].t = g[i + 1].t;
	      g[i].l = g[i + 1].l;
	      g[i].cl = g[i + 1].cl;
	      g[i].c = g[i + 1].c;
	      g[i].i = g[i + 1].i;
	      g[i + 1].n = s.n;
	      g[i + 1].t = s.t;
	      g[i + 1].l = s.l;
	      g[i + 1].cl = s.cl;
	      g[i + 1].c = s.c;
	      g[i + 1].i = s.i;
	    }
	  i++;
	}
      j++;
    }
  g[0].len = l;
  return (g);
}

t_tet	*add_tet(t_tet *t1, t_tet tet, int len)
{
  int	k;
  t_tet	*t2;

  k = 0;
  t2 = malloc(sizeof(t_tet) * (len + 1));
  while (k < len)
    {
      t2[k].col = t1[k].col;
      t2[k].t = t1[k].t;
      k++;
    }
  t2[k].col = tet.col;
  t2[k].t = tet.t;
  return (t2);
}

t_t	get_tab(t_te te, t_t t)
{
  int	len;
  int	i;
  int	j;
  int	k;
  int	n;
  char	*s;
  t_tet	tet;

  k = 0;
  t.len = 0;
  
  t.g = malloc(sizeof(t_get) * tab_len(te.tab_def));
  while (te.tab_def[k] != NULL)
    {
      t.g[k].i = 0;
      t.g[k] = get_w(te.tab_def[k], t.g[k]);
      t.g[k] = get_h(te.tab_def[k], t.g[k]);
      t.g[k] = get_c(te.tab_def[k], t.g[k]);
      t.g[k].i++;
      t.g[k].t = get_tab2(te.tab_def[k], t.g[k]);
      t.g[k].n = cut_s(te.tab_tetri[k]);
      if ((t.g[k].i = check_tet(t.g[k], te.tab_def[k])) == 1)
	{
	  tet.col = t.g[k].c;
	  tet.t = malloc(sizeof(char *) * (t.g[k].l + 1));
	  j = 0;
	  while (j < t.g[k].l)
	    {
	      i = 0;
	      tet.t[j] = malloc(t.g[k].cl + 1);
	      while (t.g[k].t[j][i] != '\0')
		{
		  tet.t[j][i] = t.g[k].t[j][i];
		  i++;
		}
	      while (i < t.g[k].cl)
		{
		  tet.t[j][i] = ' ';
		  i++;
		}
	      tet.t[j][i] = '\0';
	      j++;
	    }
	  tet.t[j] = NULL;
	  t.tab_tet = add_tet(t.tab_tet, tet, t.len);
	  t.len++;
	  //	  free_tab(tet.t);
	}
      k++;
    }
  /*i = 0;
  while (i < len)
    {
      printf("%d\n", tab_tet[i].col);
      my_show_wordtab(tab_tet[i].t);
      i++;
      }*/
  t.g[0].len = k;
  //g[k] = NULL;
  t.g = tri_g(t.g);
  //tab_tet[k] = NULL;
  //return (tab_tet);
  return (t);
}
