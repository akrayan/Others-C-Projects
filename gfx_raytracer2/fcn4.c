/*
** fcn4.c for fcn4.c in /home/Rayan/test/rt
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue May 24 07:43:23 2016 AKKACHE Kaci
** Last update Tue May 24 07:52:50 2016 AKKACHE Kaci
*/

#include "./include/rt.h"

t_color			color_s(t_s *s, t_obj *obj, double k)
{
  t_co			c;

  c = color_s_1(c, s, k);
  if (obj->t != NULL)
    {
      c = color_s_2(c, obj);
      obj->c.argb[2] = obj->p[c.i + 2];
      obj->c.argb[3] = obj->p[c.i + 3];
    }
  if (c.cosa < 0)
    {
      c.color.argb[0] = obj->c.argb[0] / 6;
      c.color.argb[1] = obj->c.argb[1] / 6;
      c.color.argb[2] = obj->c.argb[2] / 6;
      c.color.argb[3] = obj->c.argb[3] / 6;
    }
  else
    {
      c = color_s_3(c, s, obj);
      if (obj->c.argb[2] > 50 && c.color.argb[2] < 50)
	c.color.argb[2] = 50;
      if (obj->c.argb[3] > 50 && c.color.argb[3] < 50)
	c.color.argb[3] = 50;
    }
  return (c.color);
}

t_co			color_cy_1(t_co c, t_s *s, t_obj *obj, double k)
{
  if (obj->i == 0)
    c.nx = 0;
  else
    c.nx = (s->vx * k) + s->cx;
  if (obj->i == 1)
    c.ny = 0;
  else
    c.ny = (s->vy * k) + s->cy;
  if (obj->i == 2)
    c.nz = 0;
  else
    c.nz = (s->vz * k) + s->cz;
  c.lx = s->l_lum->lum->x - ((s->vx * k) + s->cx);
  c.ly = s->l_lum->lum->y - ((s->vy * k) + s->cy);
  c.lz = s->l_lum->lum->z - ((s->vz * k) + s->cz);
  c.cosa = (c.nx * c.lx + c.ny * c.ly + c.nz * c.lz) /
    ((sqrt(pow(c.nx, 2) + pow(c.ny, 2) + pow(c.nz, 2)) *
      (sqrt(pow(c.lx, 2) + pow(c.ly, 2) + pow(c.lz, 2)))));
  return (c);
}

t_co			color_cy_2(t_co c, t_s *s, t_obj *obj, double k)
{
  if (obj->t != NULL)
    {
      if (obj->i < 2)
	c.j = (s->vx * k) + s->cx;
      if (obj->i == 2)
	c.j = (s->vz * k) + s->cz;
      c.k = (s->vy * k) + s->cy;
      if (c.j < 0)
	c.j = - c.j;
      if (c.k < 0)
	c.k = - c.k;
      c.i = ((((c.k / obj->s % obj->t->clipable.clip_height)
	     * obj->t->clipable.clip_width) +
	    (c.j / obj->s % obj->t->clipable.clip_width)) * 4);
      obj->c.argb[0] = obj->p[c.i];
      obj->c.argb[1] = obj->p[c.i + 1];
      obj->c.argb[2] = obj->p[c.i + 2];
      obj->c.argb[3] = obj->p[c.i + 3];
    }
  return (c);
}

t_co			color_cy_3(t_co c, t_s *s, t_obj *obj)
{
  c.color.argb[0] = (obj->c.argb[0] * c.cosa * s->l_lum->lum->p)
    + (s->l_lum->lum->p * obj->b * c.cosa * s->l_lum->lum->c.argb[0]);
  c.color.argb[1] = (obj->c.argb[1] * c.cosa * s->l_lum->lum->p)
    + (s->l_lum->lum->p * obj->b * c.cosa * s->l_lum->lum->c.argb[1]);
  c.color.argb[2] = (obj->c.argb[2] * c.cosa * s->l_lum->lum->p)
    + (s->l_lum->lum->p * obj->b * c.cosa * s->l_lum->lum->c.argb[2]);
  c.color.argb[3] = (obj->c.argb[2] * c.cosa * s->l_lum->lum->p)
    + (s->l_lum->lum->p * obj->b * c.cosa * s->l_lum->lum->c.argb[3]);
  if (((obj->c.argb[0] * c.cosa * s->l_lum->lum->p) +
       (s->l_lum->lum->p * obj->b * c.cosa * s->l_lum->lum->c.argb[0])) >= 255)
    c.color.argb[0] = 255;
  if (((obj->c.argb[1] * c.cosa * s->l_lum->lum->p) +
       (s->l_lum->lum->p * obj->b * c.cosa * s->l_lum->lum->c.argb[1])) >= 255)
    c.color.argb[1] = 255;
  if (((obj->c.argb[2] * c.cosa * s->l_lum->lum->p) +
       (s->l_lum->lum->p * obj->b * c.cosa * s->l_lum->lum->c.argb[2])) >= 255)
    c.color.argb[2] = 255;
  if (((obj->c.argb[3] * c.cosa * s->l_lum->lum->p) +
       (s->l_lum->lum->p * obj->b * c.cosa * s->l_lum->lum->c.argb[3])) >= 255)
    c.color.argb[3] = 255;
  if (obj->c.argb[0] > 50 && c.color.argb[0] < 50)
    c.color.argb[0] = 50;
  if (obj->c.argb[1] > 50 && c.color.argb[1] < 50)
    c.color.argb[1] = 50;
  return (c);
}

t_color			color_cy(t_s *s, t_obj *obj, double k)
{
  t_co			c;

  c = color_cy_1(c, s, obj, k);
  c = color_cy_2(c, s, obj, k);
  if (c.cosa < 0)
    {
      c.color.argb[0] = obj->c.argb[0] / 6;
      c.color.argb[1] = obj->c.argb[1] / 6;
      c.color.argb[2] = obj->c.argb[2] / 6;
      c.color.argb[3] = obj->c.argb[3] / 6;
    }
  else
    {
      c = color_cy_3(c, s, obj);
      if (obj->c.argb[2] > 50 && c.color.argb[2] < 50)
	c.color.argb[2] = 50;
      if (obj->c.argb[3] > 50 && c.color.argb[3] < 50)
	c.color.argb[3] = 50;
    }
  return (c.color);
}
