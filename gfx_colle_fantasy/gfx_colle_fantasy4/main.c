/*
** main.c for main in /home/assaba_m/rendu/Infographie/gfx_colle_fantasy4
** 
** Made by Moshe Assaban
** Login   <assaba_m@epitech.net>
** 
** Started on  Thu Jan  7 19:47:24 2016 Moshe Assaban
** Last update Thu Jan  7 20:11:51 2016 Moshe Assaban
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

int			main(int ac, char **av)
{
  t_bunny_window        *win;
  t_bunny_pixelarray    *pix;
  t_bunny_pixelarray    *img;
  t_bunny_position      pos;
  t_color		color;

  if (ac == 1)
    return (0);
  pos.x = 0;
  pos.y = 0;
  win = bunny_start(1280, 1000, false, "mort");
  img = bunny_load_pixelarray(av[1]);
  pix = bunny_new_pixelarray(1280, 1000);
  color.full = BLACK;
  fill_it(pix, &color);
  bunny_blit(&win->buffer, &img->clipable, &pos);
  bunny_display(win);
  bunny_loop(win, 150, win);
  bunny_stop(win);
  return (0);
}

