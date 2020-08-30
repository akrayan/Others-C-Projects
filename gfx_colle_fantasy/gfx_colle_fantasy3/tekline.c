/*
** tekline.c for tekline in /home/assaba_m/rendu/Infographie/gfx_colle_fantasy2
** 
** Made by Moshe Assaban
** Login   <assaba_m@epitech.net>
** 
** Started on  Thu Jan  7 17:23:31 2016 Moshe Assaban
** Last update Thu Jan  7 18:47:37 2016 Moshe Assaban
*/

#include <lapin.h>
#include "my.h"

void	my_set_line_sup_sup(t_bunny_pixelarray *pix, t_bunny_position *pos,
			    t_color *color)
{
  float v;
  float v2;
  float buffer;

  v = (float)(pos[1].y - pos[0].y) / (float)(pos[1].x - pos[0].x);
  v2 = v;
  buffer = 0;
  while (pos[1].x > pos[0].x && pos[1].y > pos[0].y)
    {
      while (v2 >= 1)
	{
	  tekpixel(pix, &pos[0], color);
	  pos[0].y++;
	  v2--;
	}
      buffer += v2;
      if (buffer >= 1)
	{
	  pos[0].y++;
	  buffer = buffer - 1;
	}
      tekpixel(pix, &pos[0], color);
      v2 = v;
      pos[0].x++;
    }
}

void	my_set_line_sup_inf(t_bunny_pixelarray *pix, t_bunny_position *pos,
			    t_color *color)
{
  float v;
  float v2;
  float buffer;

  v = (float)(pos[1].y - pos[0].y) / (float)(pos[1].x - pos[0].x);
  v2 = v;
  buffer = 0;
  while (pos[1].x > pos[0].x && pos[1].y < pos[0].y)
    {
      while (v2 <= -1)
	{
	  tekpixel(pix, &pos[0], color);
	  pos[0].y--;
	  v2++;
	}
      buffer += v2;
      if (buffer <= -1)
	{
	  pos[0].y--;
	  buffer = buffer + 1;
	}
      tekpixel(pix, &pos[0], color);
      v2 = v;
      pos[0].x++;
    }
}

void	my_set_line_inf_sup(t_bunny_pixelarray *pix, t_bunny_position *pos,
			    t_color *color)
{
  float v;
  float v2;
  float buffer;

  v = (float)(pos[1].y - pos[0].y) / (float)(pos[1].x - pos[0].x);
  v2 = v;
  buffer = 0;
  while (pos[1].x < pos[0].x && pos[1].y > pos[0].y)
    {
      while (v2 <= -1)
	{
	  tekpixel(pix, &pos[0], color);
	  pos[0].y++;
	  v2++;
	}
      buffer += v2;
      if (buffer <= -1)
	{
	  pos[0].y++;
	  buffer = buffer + 1;
	}
      tekpixel(pix, &pos[0], color);
      v2 = v;
      pos[0].x--;
    }
}

void	my_set_line_diago(t_bunny_pixelarray *pix, t_bunny_position *pos,
			  t_color *color)
{
  if (pos[1].x > pos[0].x && pos[1].y > pos[0].y)
    my_set_line_sup_sup(pix, pos, color);
  else if (pos[1].x > pos[0].x && pos[1].y < pos[0].y)
    my_set_line_sup_inf(pix, pos, color);
  else
    {
      if (pos[1].x < pos[0].x && pos[1].y > pos[0].y)
	my_set_line_inf_sup(pix, pos, color);
      else if (pos[1].x < pos[0].x && pos[1].y < pos[0].y)
	my_set_line_inf_inf(pix, pos, color);
    }
}

void	tekline(t_bunny_pixelarray *pix, t_bunny_position *pos, t_color *color)
{
  if ((pos[1].x - pos[0].x) == 0)
    {
      if (pos[0].y <= pos[1].y)
	while (pos[1].y > pos[0].y++)
	  tekpixel(pix, &pos[0], color);
      else
	while (pos[1].y < pos[0].y--)
	  tekpixel(pix, &pos[0], color);
    }
  else if ((pos[1].y - pos[0].y) == 0)
    {
      if (pos[0].x <= pos[1].x)
	while (pos[1].x > pos[0].x++)
	  tekpixel(pix, &pos[0], color);
      else
	while (pos[1].x < pos[0].x--)
	  tekpixel(pix, &pos[0], color);
    }
  else
    my_set_line_diago(pix, pos, color);
}
