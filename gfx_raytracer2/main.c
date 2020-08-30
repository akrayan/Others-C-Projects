/*
** main.c for main.c in /home/Rayan/Info/gfx_raytracer1
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sat Mar  5 13:32:34 2016 AKKACHE Kaci
** Last update Tue May 24 15:58:14 2016 valentin nasraty
*/

#include "./include/rt.h"

int			check_av(char *str)
{
  int			i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '?')
	return (0);
      else if (str[i] == '!')
	return (1);
    }
  return (2);
}

void			key_2(t_bunny_event_state st,
                            t_bunny_keysym k,
			    t_s *s)
{
  if (st == GO_DOWN && k == BKS_RIGHT)
    s->cx = s->cx + 10;
  if (st == GO_DOWN && k == BKS_LEFT)
    s->cx = s->cx - 10;
  if (st == GO_DOWN && k == BKS_UP)
    s->cz = s->cz + 10;
  if (st == GO_DOWN && k == BKS_DOWN)
    s->cz = s->cz - 10;
}

t_bunny_response	key(t_bunny_event_state st,
                            t_bunny_keysym k,
			    void *dat)
{
  t_s			*s;

  s = dat;
  if (st == GO_DOWN && k == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  key_2(st, k, s);
  if (st == GO_DOWN && k == BKS_SPACE)
    s->cy = s->cy + 10;
  if (st == GO_DOWN && k == BKS_X)
    s->cy = s->cy - 10;
  if (st == GO_DOWN && k == BKS_Q)
    s->ry = s->ry + 0.05;
  if (st == GO_DOWN && k == BKS_D)
    s->ry = s->ry - 0.05;
  if (st == GO_DOWN && k == BKS_PAGEUP)
    s->rx = s->rx + 0.05;
  if (st == GO_DOWN && k == BKS_PAGEDOWN)
    s->rx = s->rx - 0.05;
  return (GO_ON);
}

t_bunny_response	loop(void *d)
{
  t_s	*s;

  s = d;
  fill_it(s->pix, &s->color);
  rt(s);
  bunny_blit(&s->win->buffer, &s->pix->clipable, &s->p);
  bunny_display(s->win);
  return (GO_ON);
}


int	main(int ac, char **av)
{
  t_s	s;
  t_obj	o;
  t_obj	p;
  t_lum	l;
  char	*buffer;

  if (ac == 2)
    {
      if (check_av(av[1]) == 0)
	{
	  //bunny_set_maximum_ram(100000);
	  s.l_obj = NULL;
	  s.l_lum = NULL;
	  l.x = 0;
	  l.y = 1500;
	  l.z = - 500;
	  l.p = 1;
	  l.c.full = RED;
	  s.l_lum = add_elem(s.l_lum, NULL, &l);
	  o.t = bunny_load_pixelarray("./asset/sauron3.png");
	  o.p = o.t->pixels;
	  o.s = 1;
	  o.x = 0;
	  o.y = 600;
	  o.z = 0;
	  o.type = 1;
	  o.r = 110;
	  o.b = 0;
	  o.i = 0;
	  s.l_obj = add_elem(s.l_obj, &o, NULL);
      
	  o.x = -800;
	  o.z = -800;
	  o.y = 0;
	  o.type = 2;
	  o.r = 'y';
	  o.l = 0;
	  o.t = bunny_load_pixelarray("./asset/o.png");
	  o.p = o.t->pixels;
	  o.s = 10;
	  s.l_obj = add_elem(s.l_obj, &o, NULL);
	  o.t = bunny_load_pixelarray("./asset/o.png");
	  o.p = o.t->pixels;
	  o.s = 3;
	  o.x = 0;
	  o.y = 0;
	  o.z = 0;
	  o.type = 3;
	  o.r = 50;
	  o.i = 1;
	  o.b = 0.6;
	  s.l_obj = add_elem(s.l_obj, &o, NULL);      
	  o.t = bunny_load_pixelarray("./asset/n.png");
	  o.p = o.t->pixels;
	  o.x = -300;
	  o.y = 0;
	  o.z = -600;
	  o.r = 100;
	  o.type = 4;
	  o.i = 10;
	  o.b = 0.8;
	  o.c.full = RED;
	  s.l_obj = add_elem(s.l_obj, &o, NULL);
	  o.x = -600;
	  o.y = 0;
	  o.z = -300;
	  o.r = 100;
	  o.type = 4;
	  o.i = 10;
	  o.b = 0.8;
	  o.c.full = RED;
	  s.l_obj = add_elem(s.l_obj, &o, NULL);
	  o.x = -600;
	  o.y = 0;
	  o.z = 300;
	  o.r = 100;
	  o.type = 4;
	  o.i = 10;
	  o.b = 0.8;
	  o.c.full = RED;
	  s.l_obj = add_elem(s.l_obj, &o, NULL);
	  o.x = -300;
	  o.y = 0;
	  o.z = 600;
	  o.r = 100;
	  o.type = 4;
	  o.i = 10;
	  o.b = 0.8;
	  o.c.full = RED;
	  s.l_obj = add_elem(s.l_obj, &o, NULL);
	  o.x = 300;
	  o.y = 0;
	  o.z = 600;
	  o.r = 100;
	  o.type = 4;
	  o.i = 10;
	  o.b = 0.8;
	  o.c.full = RED;
	  s.l_obj = add_elem(s.l_obj, &o, NULL);
	  o.x = 600;
	  o.y = 0;
	  o.z = 300;
	  o.r = 100;
	  o.type = 4;
	  o.i = 10;
	  o.b = 0.8;
	  o.c.full = RED;
	  s.l_obj = add_elem(s.l_obj, &o, NULL);
	  o.x = 300;
	  o.y = 0;
	  o.z = -600;
	  o.r = 100;
	  o.type = 4;
	  o.i = 10;
	  o.b = 0.8;
	  o.c.full = RED;
	  s.l_obj = add_elem(s.l_obj, &o, NULL);
	  o.x = 600;
	  o.y = 0;
	  o.z = -300;
	  o.r = 100;
	  o.type = 4;
	  o.i = 10;
	  o.b = 0.8;
	  o.c.full = RED;
	  s.l_obj = add_elem(s.l_obj, &o, NULL);
	}
      else if (check_av(av[1]) == 1)
	{
	  s.l_obj = NULL;
	  s.l_lum = NULL;
	  l.x = 0;
	  l.y = 1500;
	  l.z = 0;
	  l.p = 0.90;
	  l.c.full = WHITE;
	  s.l_lum = add_elem(s.l_lum, NULL, &l);
	  o.t = NULL;
	  o.p = NULL;
	  o.o = NULL;
	  o.x = - 50;
	  o.y = 100;
	  o.z = 100;
	  o.type = 1;
	  o.r = 100;
	  o.b = 0.5;
	  o.c.full = BLUE;
	  s.l_obj = add_elem(s.l_obj, &o, NULL);
	  o.s = 1;
	  o.i = 0;
	  o.t = bunny_load_pixelarray("./asset/b.png");
	  o.p = o.t->pixels;
	  o.x = 200;
	  o.y = 100;
	  o.z = 100;
	  o.type = 1;
	  o.r = 100;
	  o.b = 0.2;
	  //o.c.full = RED;
	  s.l_obj = add_elem(s.l_obj, &o, NULL);
	  o.t = bunny_load_pixelarray("./asset/b.png");
	  o.x = -300;
	  o.y = 0;
	  o.z = 100;
	  o.r = 100;
	  o.type = 4;
	  o.i = 10;
	  o.b = 1;
	  //o.c.full = PURPLE;
	  s.l_obj = add_elem(s.l_obj, &o, NULL);
	  o.x = 0;
	  o.z = 500;
	  o.y = 0;
	  o.type = 2;
	  o.r = 'y';
	  o.l = 1;
	  o.lx = 500;
	  o.ly = -1;
	  o.lz = 300;
	  o.c.full = GREEN;
	  o.t = bunny_load_pixelarray("./asset/b.png");
	  o.p = o.t->pixels;
	  o.s = 10;
	  s.l_obj = add_elem(s.l_obj, &o, NULL);
	  o.x = - 100;
	  o.z = 500;
	  o.y = 0;
	  o.type = 2;
	  o.r = 'y';
	  o.l = 0;
	  o.lx = 500;
	  o.ly = -1;
	  o.lz = 300;
	  o.c.full = GREEN;
	  o.t = bunny_load_pixelarray("./asset/g.png");
	  o.p = o.t->pixels;
	  o.s = 10;
	  s.l_obj = add_elem(s.l_obj, &o, NULL);

	  o.x = - 300;
	  o.z = -300;
	  o.y = 0;
	  o.type = 5;
	  o.r = 200;
	  o.s = 10;

	  p.x = o.x;
	  p.z = o.z;
	  p.y = o.y;
	  p.type = 2;
	  p.r = 'y';
	  p.l = 1;
	  p.lx = o.r;
	  p.ly = o.r;
	  p.lz = o.r;
	  p.t = bunny_load_pixelarray("./asset/b.png");
	  p.p = p.t->pixels;
	  p.s = o.s;
	  o.o = add_elem(o.o, &p, NULL);
	  p.x = o.x;
	  p.z = o.z;
	  p.y = o.y + o.r;
	  p.type = 2;
	  p.r = 'y';
	  p.l = 1;
	  p.lx = o.r;
	  p.ly = o.r;
	  p.lz = o.r;
	  p.t = bunny_load_pixelarray("./asset/g.png");
	  p.p = p.t->pixels;
	  p.s = o.s;
	  o.o = add_elem(o.o, &p, NULL);

	  p.x = o.x;
	  p.z = o.z;
	  p.y = o.y;
	  p.type = 2;
	  p.r = 'x';
	  p.l = 1;
	  p.lx = o.r;
	  p.ly = o.r;
	  p.lz = o.r;
	  p.t = bunny_load_pixelarray("./asset/b.png");
	  p.p = p.t->pixels;
	  p.s = o.s;
	  o.o = add_elem(o.o, &p, NULL);

	  p.x = o.x + o.r;
	  p.z = o.z;
	  p.y = o.y;
	  p.type = 2;
	  p.r = 'x';
	  p.l = 1;
	  p.lx = o.r;
	  p.ly = o.r;
	  p.lz = o.r;
	  p.t = bunny_load_pixelarray("./asset/b.png");
	  p.p = p.t->pixels;
	  p.s = o.s;
	  o.o = add_elem(o.o, &p, NULL);
	  p.x = o.x;
	  p.z = o.z;
	  p.y = o.y;
	  p.type = 2;
	  p.r = 'z';
	  p.l = 1;
	  p.lx = o.r;
	  p.ly = o.r;
	  p.lz = o.r;
	  p.t = bunny_load_pixelarray("./asset/b.png");
	  p.p = p.t->pixels;
	  p.s = o.s;
	  o.o = add_elem(o.o, &p, NULL);

	  p.x = o.x;
	  p.z = o.z + o.r;
	  p.y = o.y;
	  p.type = 2;
	  p.r = 'z';
	  p.l = 1;
	  p.lx = o.r;
	  p.ly = o.r;
	  p.lz = o.r;
	  p.t = bunny_load_pixelarray("./asset/b.png");
	  p.p = p.t->pixels;
	  p.s = o.s;
	  o.o = add_elem(o.o, &p, NULL);

	  s.l_obj = add_elem(s.l_obj, &o, NULL);


	  o.t = NULL;
	  o.p = NULL;
	  o.x = 100;
	  o.y = 200;
	  o.z = 100;
	  o.type = 3;
	  o.r = 10;
	  o.i = 2;
	  o.b = 1;
	  o.c.full = TEAL;
	  s.l_obj = add_elem(s.l_obj, &o, NULL);
	}      
      s.win = bunny_start(800, 800, false, "Raytracer 2");
      s.pix = bunny_new_pixelarray(800, 800);
      s.p.x = 0;
      s.p.y = 0;
      s.cx = 0;
      s.cy = 500;
      s.cz = - 2200;
      s.rx = 0;
      s.ry = 0;
      s.rz = 0;
      s.color.full = BLACK;
      bunny_set_key_response(key);
      bunny_set_loop_main_function(loop);
      bunny_loop(s.win, 150, &s);
      bunny_stop(s.win);
    }
  return (0);
}
