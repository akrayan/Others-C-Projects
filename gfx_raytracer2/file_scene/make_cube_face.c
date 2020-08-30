/*
** make_cube_face.c for rt2 in /home/nasrat_v/rendu/Infographie/test_rt2/yo regarde c les modif/file_scene
** 
** Made by valentin nasraty
** Login   <nasrat_v@epitech.net>
** 
** Started on  Tue May 24 09:11:31 2016 valentin nasraty
** Last update Tue May 24 09:14:07 2016 valentin nasraty
*/

#include "../include/rt.h"

void	make_cube_face(t_obj *o, t_obj *p)
{
  p->x = o->x;
  p->z = o->z;
  p->y = o->y;
  p->type = 2;
  p->r = 1;
  p->l = 1;
  p->lx = o->r;
  p->ly = o->r;
  p->lz = o->r;
  p->p = p->t->pixels;
  p->s = o->s;
  o->o = add_elem(o->o, p, NULL);
}

void	make_cube_face2(t_obj *o, t_obj *p)
{
  p->y = o->y + o->r;
  p->x = o->x;
  p->z = o->z;
  p->type = 2;
  p->r = 1;
  p->l = 1;
  p->lx = o->r;
  p->ly = o->r;
  p->lz = o->r;
  p->p = p->t->pixels;
  p->s = o->s;
  o->o = add_elem(o->o, p, NULL);
}

void	make_cube_face3(t_obj *o, t_obj *p)
{
  p->r = 0;
  p->y = o->y;
  p->x = o->x;
  p->z = o->z;
  p->type = 2;
  p->l = 1;
  p->lx = o->r;
  p->ly = o->r;
  p->lz = o->r;
  p->p = p->t->pixels;
  p->s = o->s;
  o->o = add_elem(o->o, p, NULL);
}

void	make_cube_face4(t_obj *o, t_obj *p)
{
  p->x = o->x + o->r;
  p->r = 0;
  p->z = o->z;
  p->y = o->y;
  p->type = 2;
  p->l = 1;
  p->lx = o->r;
  p->ly = o->r;
  p->lz = o->r;
  p->p = p->t->pixels;
  p->s = o->s;
  o->o = add_elem(o->o, p, NULL);
}
