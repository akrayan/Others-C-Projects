/*
** fcn3.c for fcn4.c in /home/Rayan/test/rt
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue May 24 07:42:21 2016 AKKACHE Kaci
** Last update Tue May 24 07:51:23 2016 AKKACHE Kaci
*/

#include "./include/rt.h"

double			calc_cy_0(t_s *s, t_l *p)
{
  if (p->obj->i == 0)
    return (calc_cy_x(s, p->obj));
  else if (p->obj->i == 1)
    return (calc_cy_y(s, p->obj));
  else if (p->obj->i == 2)
    return (calc_cy_z(s, p->obj));
  return (- 1);
}

double			*calc_main(t_s *s, t_l *l)
{
  t_l			*p;
  int			i;
  double	       	*k;

  k = malloc(sizeof(double) * list_len(l));
  p = l;
  i = 0;
  while (p != NULL)
    {
      if (p->obj->type == 1)
	k[i] = calc_s(s, p);
      else if (p->obj->type == 2)
	k[i] = calc_p(s, p->obj);
      else if (p->obj->type == 3)
	k[i] = calc_cy_0(s, p);
      else if (p->obj->type == 4)
	k[i] = calc_pa(s, p);
      else if (p->obj->type == 5)
	k[i] = calc_oc(s, p->obj);
      p = p->next;
      i++;
    }
  return (k);
}

t_co			color_s_1(t_co c, t_s *s, double k)
{
  c.x = (s->vx * k) + s->cx;
  c.y = (s->vy * k) + s->cy;
  c.z = (s->vz * k) + s->cz;
  c.lx = s->l_lum->lum->x - ((s->vx * k) + s->cx);
  c.ly = s->l_lum->lum->y - ((s->vy * k) + s->cy);
  c.lz = s->l_lum->lum->z - ((s->vz * k) + s->cz);
  c.cosa = (c.x * c.lx + c.y * c.ly + c.z * c.lz) /
    ((sqrt(pow(c.x, 2) + pow(c.y, 2) + pow(c.z, 2)) *
      (sqrt(pow(c.lx, 2) + pow(c.ly, 2) + pow(c.lz, 2)))));
  return (c);
}

t_co			color_s_2(t_co c, t_obj *obj)
{
  if (obj->i == 1)
    {
      c.y_ = (c.y - obj->y) / obj->r;
      if (c.y_ < 0)
	c.y_ = - c.y_;
      if (obj->s / c.y_ < 1)
	c.y_ = obj->s;
      else
	c.y_ = obj->s / c.y_;
    }
  else
    c.y_ = obj->s;
  c.x = c.x - obj->x + obj->r;
  c.y = - (c.y - obj->y + obj->r);
  if (c.x < 0)
    c.x = - c.x;
  if (c.y < 0)
    c.y = - c.y;
  c.i = (((int)c.y / obj->s % obj->t->clipable.clip_height)
	 * obj->t->clipable.clip_width +
	 ((int)c.x / (int)(c.y_) % obj->t->clipable.clip_width)) * 4;
  obj->c.argb[0] = obj->p[c.i];
  obj->c.argb[1] = obj->p[c.i + 1];
  return (c);
}

t_co			color_s_3(t_co c, t_s *s, t_obj *obj)
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
