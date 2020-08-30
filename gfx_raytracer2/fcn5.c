/*
** fcn5.c for fcn5.c in /home/Rayan/test/rt
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue May 24 07:44:44 2016 AKKACHE Kaci
** Last update Tue May 24 07:54:00 2016 AKKACHE Kaci
*/

#include "./include/rt.h"

t_co			color_p_1(t_co c, t_obj *obj)
{
  if ((obj->z - c.z_) < 0 && obj->r == 'y')
    c.y = (obj->z - c.z_) * (- 1);
  else if (obj->r == 'y')
    c.y = (obj->z - c.z_);
  if (obj->x - c.x_ < 0 && (obj->r == 'y' || obj->r == 'z'))
    c.x = (obj->x - c.x_) * (- 1);
  else if (obj->r == 'y' || obj->r == 'z')
    c.x = (obj->x - c.x_);
  if (obj->z - c.z_ < 0 && (obj->r == 'x'))
    c.x = (obj->z - c.z_) * (- 1);
  else if (obj->r == 'x')
    c.x = (obj->z - c.z_);
  if (obj->y - c.y_ < 0 && (obj->r == 'x' || obj->r == 'z'))
    c.y = (obj->y - c.y_) * (- 1);
  else if (obj->r == 'x' || obj->r == 'z')
    c.y = obj->y - c.y_;
  c.j = (((((int)c.y / obj->s % obj->t->clipable.clip_height) *
	   obj->t->clipable.clip_width) +
	  ((int)c.x / obj->s % obj->t->clipable.clip_width)) * 4);
  c.color.argb[0] = obj->p[c.j];
  c.color.argb[1] = obj->p[c.j + 1];
  c.color.argb[2] = obj->p[c.j + 2];
  c.color.argb[3] = obj->p[c.j + 3];
  return (c);
}

t_co			color_p_2(t_co c, t_s *s)
{
  c.z = c.z_;
  c.y = c.y_;
  c.x = c.x_;
  s->vx = s->l_lum->lum->x - c.x;
  s->vy = s->l_lum->lum->y - c.y;
  s->vz = s->l_lum->lum->z - c.z;
  s->ox = c.x;
  s->oy = c.y;
  s->oz = c.z;
  c.d = calc_main(s, s->l_obj);
  c.i = 0;
  while (c.i < list_len(s->l_obj) && (c.d[c.i] <= 0.000000001 || c.d[c.i] > 1))
    c.i++;
  if (c.d[c.i] > 0.000000001 && c.d[c.i] < 1)
    {
      c.color.argb[0] = c.color.argb[0] / 5;
      c.color.argb[1] = c.color.argb[1] / 5;
      c.color.argb[2] = c.color.argb[2] / 5;
      c.color.argb[3] = c.color.argb[3] / 5;
    }
  return (c);
}

t_color			color_p(t_s *s, t_obj *obj, double k)
{
  t_co			c;

  c.x_ = s->vx * k + s->ox;
  c.y_ = s->vy * k + s->oy;
  c.z_ = s->vz * k + s->oz;
  if (obj->t != NULL)
    c = color_p_1(c, obj);
  else
    c.color = obj->c;
  c = color_p_2(c, s);
  return (c.color);
}

t_color			color(t_s *s, t_obj *obj, double k)
{
  t_color			c;

  if (obj->type == 1)
    c = color_s(s, obj, k);
  else if (obj->type == 2)
    c = color_p(s, obj, k);
  else if (obj->type == 3)
    c = color_cy(s, obj, k);
  else if (obj->type == 4)
    c = color_s(s, obj, k);
  return (c);
}

int			g_c_1(double *k, t_l *l)
{
  int			i;
  int			j;

  i = 0;
  j = 0;
  while (i < list_len(l))
    {
      if (k[i] > 0 && k[i] < k[j])
	j = i;
      else if (k[j] < 0 && k[i] > 0)
	j = i;
      i++;
    }
  return (j);
}
