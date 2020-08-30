/*
** fcn1.c for fcn1.c in /home/Rayan/test/rt
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue May 24 07:40:17 2016 AKKACHE Kaci
** Last update Tue May 24 07:48:25 2016 AKKACHE Kaci
*/

#include "./include/rt.h"

double			calc_s(t_s *s, t_l *p)
{
  t_c			c;

  c.a = pow(s->vx, 2) + pow(s->vy, 2) + pow(s->vz, 2);
  c.b = 2 * (s->vx * (s->ox - p->obj->x) + s->vy *
	     (s->oy - p->obj->y) + s->vz * (s->oz - p->obj->z));
  c.c = (pow(s->ox - p->obj->x, 2) + pow(s->oy - p->obj->y, 2) +
	 pow(s->oz - p->obj->z, 2)) - pow(p->obj->r, 2);
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
  else
    return (-1);
}

t_c			calc_pa_1(t_s *s, t_l *p, t_c c)
{
  c.a = pow(s->vx, 2) + pow(s->vy, 2) / p->obj->i + pow(s->vz, 2);
  c.b = 2 * (s->vx * (s->ox - p->obj->x) + s->vy * (s->oy - p->obj->y)
	     / p->obj->i + s->vz * (s->oz - p->obj->z));
  c.c = (pow(s->ox - p->obj->x, 2) + pow(s->oy - p->obj->y, 2) /
	 p->obj->i + pow(s->oz - p->obj->z, 2)) - pow(p->obj->r, 2);
  c.d = pow(c.b, 2) - (4 * c.a * c.c);
  return (c);
}

double			calc_pa(t_s *s, t_l *p)
{
  t_c			c;

  c = calc_pa_1(s, p, c);
  if (c.d > 0)
    {
      c.t1 = (-c.b + sqrt(c.d)) / (2 * c.a);
      c.t2 = (-c.b - sqrt(c.d)) / (2 * c.a);
      if (c.t2 > 0 && c.t2 < c.t1)
	c.t1 = c.t2;
      if (s->vy * c.t1 + s->oy < p->obj->y)
	return (-1);
      return (c.t1);
    }
  else if (c.d == 0)
    {
      if (s->vy * ((- c.b) / (2 * c.a)) + s->oy < p->obj->y)
	return (-1);
      return ((- c.b) / (2 * c.a));
    }
  else
    return (-1);
}

double			calc_cy_x(t_s *s, t_obj *obj)
{
  t_c			c;

  c.a = pow(s->vy, 2) + pow(s->vz, 2);
  c.b = 2 * ((s->oy - obj->y) * s->vy + (s->oz - obj->z) * s->vz);
  c.c = pow(s->oy - obj->y, 2) + pow(s->oz - obj->z, 2) - pow(obj->r, 2);
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
  else
    return (-1);
}

double			calc_cy_y(t_s *s, t_obj *obj)
{
  t_c			c;

  c.a = pow(s->vx, 2) + pow(s->vz, 2);
  c.b = 2 * ((s->ox - obj->x) * s->vx + (s->oz - obj->z) * s->vz);
  c.c = pow(s->ox - obj->x, 2) + pow(s->oz - obj->z, 2) - pow(obj->r, 2);
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
  else
    return (-1);
}
