/*
** my_set_line2.c for tekline2 in /home/assaba_m/rendu/Infographie/gfx_colle_fantasy2
** 
** Made by Moshe Assaban
** Login   <assaba_m@epitech.net>
** 
** Started on  Thu Jan  7 17:23:50 2016 Moshe Assaban
** Last update Thu Jan  7 18:47:24 2016 Moshe Assaban
*/

#include <lapin.h>
#include "my.h"

void	my_set_line_inf_inf(t_bunny_pixelarray *pix, t_bunny_position *pos,
			    t_color *color)
{
  float v;
  float v2;
  float buffer;

  v = (float)(pos[0].y - pos[1].y) / (float)(pos[0].x - pos[1].x);
  v2 = v;
  buffer = 0;
  while (pos[1].x < pos[0].x && pos[1].y < pos[0].y)
    {
      while (v2 >= 1)
	{
	  tekpixel(pix, &pos[0], color);
	  pos[0].y--;
	  v2--;
	}
      buffer += v2;
      if (buffer >= 1)
	{
	  pos[0].y--;
	  buffer = buffer - 1;
	}
      tekpixel(pix, &pos[0], color);
      v2 = v;
      pos[0].x--;
    }
}
