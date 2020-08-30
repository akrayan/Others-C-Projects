/*
** fcn6.c for fcn6.c in /home/Rayan/test/rt
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue May 24 07:45:32 2016 AKKACHE Kaci
** Last update Tue May 24 07:54:41 2016 AKKACHE Kaci
*/

#include "./include/rt.h"

t_color			g_color(t_s *s, t_l *l)
{
  t_l			*p;
  int			i;
  t_color		c;
  double	       	*k;

  p = l;
  k = calc_main(s, l);
  if (k[g_c_1(k, l)] > 0)
    {
      p = l;
      i = -1;
      while (++i < g_c_1(k, l))
	p = p->next;
      if (p->obj->type == 5)
	c = g_color(s, p->obj->o);
      else
	c = color(s, p->obj, k[g_c_1(k, l)]);
      free(k);
    }
  else
    c.full = BLACK;
  return (c);
}

void			rt(t_s *s)
{
  t_bunny_position	pos;
  t_color	       	c;

  pos.y = 0;
  while (pos.y < 800)
    {
      pos.x = 0;
      while (pos.x < 800)
	{
	  s->ox = s->cx;
	  s->oy = s->cy;
	  s->oz = s->cz;
	  t_r(s, pos);
	  rot(s);
	  c = g_color(s, s->l_obj);
	  tekpixel(s->pix, &pos, &c);
	  pos.x++;
	}
      pos.y++;
    }
}
