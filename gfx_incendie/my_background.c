/*
** my_background.c for my_background.c in /home/Rayan/Info/gfx_incendie
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sat Dec  5 16:25:30 2015 AKKACHE Kaci
** Last update Sat Dec  5 16:25:32 2015 AKKACHE Kaci
*/


#include "./include/lapin.h"

void    my_background(t_bunny_pixelarray *pix, unsigned int color)
{
  t_bunny_position      pos;
  int                   x;
  int                   y;

  x = 0;
  y = 0;
  pos.x = x;
  pos.y = y;
  while (y != pix->clipable.clip_height || x != pix->clipable.clip_width)
    {
      x = 0;
      pos.x = x;
      while (x != pix->clipable.clip_width)
        {
          my_set_pixel(pix,pos,color);
          x += 1;
          pos.x = x;
        }
      y += 1;
      pos.y = y;
    }
}
