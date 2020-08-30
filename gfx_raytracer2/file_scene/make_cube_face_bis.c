/*
** make_cube_face_bis.c for rt2 in /home/nasrat_v/rendu/Infographie/test_rt2/yo regarde c les modif/file_scene
** 
** Made by valentin nasraty
** Login   <nasrat_v@epitech.net>
** 
** Started on  Tue May 24 09:13:20 2016 valentin nasraty
** Last update Tue May 24 09:13:45 2016 valentin nasraty
*/

#include "../include/rt.h"

void	make_cube_face5(t_obj *o, t_obj *p)
{
  p->z = o->z;
  p->y = o->y;
  p->type = 2;
  p->l = 1;
  p->lx = o->r;
  p->ly = o->r;
  p->lz = o->r;
  p->p = p->t->pixels;
  p->s = o->s;
  p->r = 2;
  p->x = o->x;
  o->o = add_elem(o->o, p, NULL);
}

void	make_cube_face6(t_obj *o, t_obj *p)
{
  p->x = o->x;
  p->y = o->y;
  p->type = 2;
  p->l = 1;
  p->lx = o->r;
  p->ly = o->r;
  p->lz = o->r;
  p->p = p->t->pixels;
  p->s = o->s;
  p->z = o->z + o->r;
  p->r = 2;
  o->o = add_elem(o->o, p, NULL);
}
