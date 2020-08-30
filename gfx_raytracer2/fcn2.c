/*
** fcn2.c for fcn2.c in /home/Rayan/test/rt
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue May 24 07:41:16 2016 AKKACHE Kaci
** Last update Tue May 24 07:49:56 2016 AKKACHE Kaci
*/

#include "./include/rt.h"

double			calc_cy_z(t_s *s, t_obj *obj)
{
  t_c			c;

  c.a = pow(s->vx, 2) + pow(s->vy, 2);
  c.b = 2 * ((s->ox - obj->x) * s->vx + (s->oy - obj->y) * s->vy);
  c.c = pow(s->ox - obj->x, 2) + pow(s->oy - obj->y, 2) - pow(obj->r, 2);
  c.d = pow(c.b, 2) - (4 * c.a * c.c);
  if (c.d > 0)
    {
      c.t1 = (-c.b + sqrt(c.d)) / (2 * c.a);
      c.t2 = (-c.b - sqrt(c.d)) / (2 * c.a);
      if (c.t2 > 0 && c.t2 < c.t1)
	c.t1 = c.t2;
      return (c.t1);
    }
  else if (c.d == 0)
    return ((- c.b) / (2 * c.a));
  return (-1);
}

void			t_r(t_s *s, t_bunny_position pos)
{
  s->vy = - (pos.y - (s->pix->clipable.clip_height / 2));
  s->vx = pos.x - (s->pix->clipable.clip_width / 2);
  s->vz = 1000;
}

void			rot(t_s *s)
{
  double	x;
  double	y;
  double	z;

  x = ((s->vx * cos(s->ry)) - (s->vz * sin(s->ry))) + s->vx
    + (s->vx * cos(s->rz)) - (s->vy * sin(s->rz));
  y = s->vy + ((s->vy * cos(s->rx)) - (s->vz * sin(s->rx)))
    + (s->vx * sin(s->rz)) + (s->vy * cos(s->rz));
  z = - (s->vx * sin(s->ry)) + (s->vz * cos(s->ry))
    + ((s->vy * sin(s->rx)) + (s->vz * cos(s->rx))) + s->vz;
  s->vx = x;
  s->vy = y;
  s->vz = z;
}

double			calc_p(t_s *s, t_obj *obj)
{
  double		k;

  if (obj->r == 'z' && s->vz != 0)
    k = (obj->z - s->oz) / s->vz;
  else if (obj->r == 'y' && s->vy != 0)
    k = (obj->y - s->oy) / s->vy;
  else if (obj->r == 'x' && s->vx != 0)
    k = (obj->x - s->ox) / s->vx;
  else
    k = -1;
  if ((obj->l == 1) && ((k * s->vx + s->ox < obj->x && obj->lx > 0) ||
			(k * s->vy + s->oy < obj->y && obj->ly > 0) ||
			(k * s->vz + s->oz < obj->z && obj->lz > 0) ||
			(k * s->vx + s->ox - obj->x > obj->lx && obj->lx > 0) ||
			(k * s->vy + s->oy - obj->y > obj->ly && obj->ly > 0) ||
			(k * s->vz + s->oz - obj->z > obj->lz && obj->lz > 0)))
    k = -1;
  return (k);
}

double			calc_oc(t_s *s, t_obj *o)
{
  int			i;
  int			j;
  double		*k;
  double		k1;

  k = calc_main(s, o->o);
  i = 0;
  j = 0;
  while (i < list_len(o->o))
    {
      if (k[i] > 0 && k[i] < k[j])
	j = i;
      else if (k[j] < 0 && k[i] > 0)
	j = i;
      i++;
    }
  k1 = k[j];
  free(k);
  return (k1);
}

