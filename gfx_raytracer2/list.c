/*
** list.c for list.c in /home/Rayan/Info/gfx_raytracer2
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue May  3 10:02:52 2016 AKKACHE Kaci
** Last update Tue May 24 02:17:36 2016 AKKACHE Kaci
*/

#include "./include/rt.h"

int	list_len(t_l *l)
{
  int	i;
  t_l	*p;

  i = 0;
  p = l;
  while (p != NULL)
    {
      p = p->next;
      i++;
    }
  return (i);
}

t_obj	*dup_obj(t_obj *obj)
{
  t_obj	*n;

  if ((n = malloc(sizeof(t_obj))) == NULL)
    return (NULL);
  n->x = obj->x;
  n->y = obj->y;
  n->z = obj->z;
  n->type = obj->type;
  n->r = obj->r;
  n->c = obj->c;
  n->i = obj->i;
  n->t = d_pix(obj->t);
  n->p = obj->p;
  n->s = obj->s;
  n->l = obj->l;
  n->lx = obj->lx;
  n->ly = obj->ly;
  n->lz = obj->lz;
  n->o = obj->o;
  n->b = obj->b;
  return (n);
}

t_lum	*dup_lum(t_lum *lum)
{
  t_lum	*n;

  if ((n = malloc(sizeof(t_obj))) == NULL)
    return (NULL);
  n->x = lum->x;
  n->y = lum->y;
  n->z = lum->z;
  n->p = lum->p;
  n->c = lum->c;
  return (n);
}

t_l	*add_elem(t_l *l, t_obj *obj, t_lum *lum)
{
  t_l	*n;

  if ((n = malloc(sizeof(t_l))) == NULL)
    return (NULL);
  if (obj != NULL)
    {
      if ((n->obj = dup_obj(obj)) == NULL)
	return (NULL);
    }
  else
    if ((n->lum = dup_lum(lum)) == NULL)
      return (NULL);
  n->next = NULL;
  if (l == NULL)
    {
      n->last = n;
      return (n);
    }
  l->last->next = n;
  l->last = n;
  return (l);
}

t_l	*sup_elem(t_l *l)
{
  t_l	*n;

  n = l;
  l = l->next;
  if (n->obj != NULL)
    {
      bunny_delete_clipable(&n->obj->t->clipable);
      free(n->obj);
    }
  else
    free(n->lum);
  free(n);
  return (l);
}

t_l	*sup_elem_id(t_l *l, int i)
{
  int	j;
  t_l	*n;
  t_l	*p;

  n = NULL;
  j = 0;
  p = l;
  while (j < i && p != NULL)
    {
      n = add_elem(n, p->obj, p->lum);
      p = p->next;
      j++;
    }
  if (p != NULL)
    p = p->next;
  while (p != NULL)
    {
      n = add_elem(n, p->obj, p->lum);
      p = p->next;
    }
  while (l != NULL)
    l = sup_elem(l);
  return (n);
}

