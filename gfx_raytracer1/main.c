/*
** main.c for main.c in /home/Rayan/Info/gfx_raytracer1
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sat Mar  5 13:32:34 2016 AKKACHE Kaci
** Last update Thu May  5 23:14:00 2016 AKKACHE Kaci
*/

#include "./include/rt.h"

void			fill_it(t_bunny_pixelarray *pix, t_color *color)
{
  unsigned char		*pixel;
  int			i;

  i = 0;
  pixel = (unsigned char *)(pix->pixels);
  while (i < (pix->clipable.clip_width * pix->clipable.clip_height * 4))
    {
      pixel[i] = color->argb[0];
      pixel[i + 1] = color->argb[1];
      pixel[i + 2] = color->argb[2];
      pixel[i + 3] = color->argb[3];
      i = i + 4;
    }
}

void			trace_plan(t_bunny_pixelarray *pix, t_bunny_position pos,
				   t_co o, t_ray v)
{
  double		y;
  double		k;
  t_color		color;

  color.argb[0] = 255;
  color.argb[1] = 255;
  color.argb[2] = 255;
  y = - 200;
  k = (y - o.y) / v.y;
  if (k > 0)
    tekpixel(pix, &pos, &color);
}

t_init			init(t_init i)
{
  i.pix = bunny_new_pixelarray(1920, 1080);
  i.win = bunny_start(1920, 1080, false, "raytracer1");
  i.color.argb[0] = 0;
  i.color.argb[1] = 0;
  i.color.argb[2] = 0;
  fill_it(i.pix, &i.color);
  i.o.x = 0;
  i.o.y = 0;
  i.o.z = - 110;
  i.pos.y = 0;
  return (i);
}

void			aff(t_init i)
{
  i.pos.x = 0;
  i.pos.y = 0;
  bunny_blit(&i.win->buffer, &i.pix->clipable, &i.pos);
  bunny_display(i.win);
  bunny_loop(i.win, 150, i.win);
  bunny_stop(i.win);
}

int			main()
{
  t_bunny_position	*scr;
  t_init		i;
  t_ray			v;

  scr = malloc(sizeof(t_bunny_position) * 2);
  scr[0].x = 1920;
  scr[0].y = 1080;
  i = init(i);
  while (i.pos.y  < 1080)
    {
      i.pos.x = 0;
      while (i.pos.x < 1920)
	{
	  scr[1].x = i.pos.x;
	  scr[1].y = i.pos.y;
	  tekray(scr, &v.x, &v.y, &v.z);
	  trace_plan(i.pix, i.pos, i.o, v);
	  trace_sphere(i.pix, i.pos, i.o, v);
	  i.pos.x++;
	}
      i.pos.y++;
    }
  aff(i);
  return (0);
}
