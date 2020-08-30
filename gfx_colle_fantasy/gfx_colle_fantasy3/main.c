/*
** main.c for main.c in /home/assaba_m/rendu/Infographie/gfx_colle_fantasy3
** 
** Made by Moshe Assaban
** Login   <assaba_m@epitech.net>
** 
** Started on  Thu Jan  7 18:23:11 2016 Moshe Assaban
** Last update Thu Jan  7 19:15:21 2016 Moshe Assaban
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

void			draw_snow(t_bunny_pixelarray *pix, int xpos,
				  t_bunny_position *pos)
{
  t_color		color;
  int			rayon;
  
  color.full = WHITE;
  while (xpos <= 1000)
    {
      rayon = 0;
      pos->x = xpos;
      while (rayon < 10)
	{
	  tekcercle(pix, pos, rayon, &color);
	  rayon += 1;
	}
      xpos += 300;
    }
  pos->y = pos->y + 100;
}

int			main()
{
  t_bunny_window        *win;
  t_bunny_pixelarray    *pix;
  t_color		color;
  t_bunny_position	pos;
  t_bunny_position	pos2;
  int			xpos;

  xpos = 100;
  pix = bunny_new_pixelarray(1000, 1000);
  win = bunny_start(1000, 1000, false, "lloth");
  pos2.x = 220;
  pos2.x = 220;
  color.full = BLACK;
  fill_it(pix, &color);
  draw_snow(pix, xpos, &pos);
  bunny_blit(&win->buffer, &pix->clipable, &pos2);
  bunny_display(win);
  bunny_loop(win, 150, win);
  bunny_stop(win);
  return (0);
}

