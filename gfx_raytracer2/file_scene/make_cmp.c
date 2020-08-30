/*
** make_cmp.c for rt2 in /home/nasrat_v/rendu/Infographie/test_rt2/yo regarde c les modif/file_scene
** 
** Made by valentin nasraty
** Login   <nasrat_v@epitech.net>
** 
** Started on  Tue May 24 09:15:35 2016 valentin nasraty
** Last update Tue May 24 09:53:02 2016 valentin nasraty
*/

#include "../include/rt.h"

void    make_cmp_rebis(t_s *s, t_obj *o, t_obj *p, t_lum *l)
{
  if (l->tab[l->i][0] == 'p' && l->tab[l->i][1] == 't')
    p->t = bunny_load_pixelarray(get_value(l->tab[l->i]));
  else if (l->tab[l->i][0] == 'p' && l->tab[l->i][1] == 'o' &&
	   l->tab[l->i][2] == 'b' && l->tab[l->i][3] == 'j' && l->tab[l->i][4] == '1')
    make_cube_face(o, p);
  else if (l->tab[l->i][0] == 'p' && l->tab[l->i][1] == 'o' &&
	   l->tab[l->i][2] == 'b' && l->tab[l->i][3] == 'j' && l->tab[l->i][4] == '2')
    make_cube_face2(o, p);
  else if (l->tab[l->i][0] == 'p' && l->tab[l->i][1] == 'o' &&
	   l->tab[l->i][2] == 'b' && l->tab[l->i][3] == 'j' && l->tab[l->i][4] == '3')
    make_cube_face3(o, p);
  else if (l->tab[l->i][0] == 'p' && l->tab[l->i][1] == 'o' &&
	   l->tab[l->i][2] == 'b' && l->tab[l->i][3] == 'j' && l->tab[l->i][4] == '4')
    make_cube_face4(o, p);
  else if (l->tab[l->i][0] == 'p' && l->tab[l->i][1] == 'o' &&
	   l->tab[l->i][2] == 'b' && l->tab[l->i][3] == 'j' && l->tab[l->i][4] == '5')
    make_cube_face5(o, p);
  else if (l->tab[l->i][0] == 'p' && l->tab[l->i][1] == 'o' &&
	   l->tab[l->i][2] == 'b' && l->tab[l->i][3] == 'j' && l->tab[l->i][4] == '6')
    make_cube_face6(o, p);
  else if (l->tab[l->i][0] == 'o' && l->tab[l->i][1] == 'b' &&
	   l->tab[l->i][2] == 'j')
    s->l_obj = add_elem(s->l_obj, o, NULL);
  else if (l->tab[l->i][0] == 'o')
     o->o = add_elem(o->o, p, NULL);
}

void    make_cmp_bis(t_s *s, t_obj *o, t_obj *p, t_lum *l)
{
  if (l->tab[l->i][0] == 'o' && l->tab[l->i][1] == 'l')
    o->l = my_getnbr(get_value(l->tab[l->i]));
  else if (l->tab[l->i][0] == 'o' && l->tab[l->i][1] == 'p')
    o->p = o->t->pixels;
  else if (l->tab[l->i][0] == 'o' && l->tab[l->i][1] == 's')
    o->s = my_getnbr(get_value(l->tab[l->i]));
  else if (l->tab[l->i][0] == 'o' && l->tab[l->i][1] == 'l' &&
	   l->tab[l->i][2] == 'x')
    o->lx = my_getnbr(get_value(l->tab[l->i]));
  else if (l->tab[l->i][0] == 'o' && l->tab[l->i][1] == 'l' &&
	   l->tab[l->i][2] == 'y')
    o->ly = my_getnbr(get_value(l->tab[l->i]));
  else if (l->tab[l->i][0] == 'o' && l->tab[l->i][1] == 'l' &&
	   l->tab[l->i][2] == 'z')
    o->lz = my_getnbr(get_value(l->tab[l->i]));
  else if (l->tab[l->i][0] == 'o' && l->tab[l->i][1] == 't')
    o->t = bunny_load_pixelarray(get_value(l->tab[l->i]));
  else if (l->tab[l->i][0] == 's')
    o->s = my_getnbr(get_value(l->tab[l->i]));
  else if (l->tab[l->i][0] == 'c' && l->tab[l->i][1] == 'o' &&
	   l->tab[l->i][2] == 'l'
	   && l->tab[l->i][3] == 'o' && l->tab[l->i][4] == 'r')
    o->c.full = cmp_color(get_value(l->tab[l->i]));
  else
    make_cmp_rebis(s, o, p, l);
}
