/*
** main.c for main in /home/assaba_m/rendu/Infographie/gfx_colle_fantasy1
** 
** Made by Moshe Assaban
** Login   <assaba_m@epitech.net>
** 
** Started on  Thu Jan  7 16:28:01 2016 Moshe Assaban
** Last update Thu Jan  7 18:17:44 2016 Moshe Assaban
*/

#include <lapin.h>
#include "my.h"

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

int			main()
{
  t_bunny_window        *win;
  t_bunny_pixelarray    *pix;
  t_bunny_position	line[2];
  t_color		color;
  t_bunny_position	pos;

  pix = bunny_new_pixelarray(1000, 1000);
  win = bunny_start(1000, 1000, false, "lloth");
  pos.x = 0;
  pos.y = 0;
  color.full = BLACK;
  fill_it(pix, &color);
  color.full = WHITE;
  line[0].x = 100;
  line[0].y = 100;
  line[1].x = 400;
  line[1].y = 400;
  tekline(pix, line, &color);
  bunny_blit(&win->buffer, &pix->clipable, &pos);
  bunny_display(win);
  bunny_loop(win, 150, win);
  bunny_stop(win);
  return (0);
}
