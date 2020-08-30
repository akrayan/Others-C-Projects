/*
** my_set_cercle.c for my_set_cercle.c in /home/felten_n/rendu/rush/gfx_incendie/gfx_incendie
** 
** Made by nicolas felten
** Login   <felten_n@epitech.net>
** 
** Started on  Sat Dec  5 15:09:42 2015 nicolas felten
** Last update Thu Jan  7 18:47:16 2016 Moshe Assaban
*/

#include <math.h>
#include <lapin.h>
#include "my.h"

void			tekcercle_2(t_bunny_pixelarray *pix, t_bunny_position *pos,
				  int rayon, t_color *color)
{
  t_bunny_position	buff[3];
  float			angle;

  buff[0] = *pos;
  buff[2] = buff[0];
  angle = 0;
  while (angle <= M_PI / 2)
    {
      buff[1].x = buff[2].x - rayon * cos(angle);
      buff[1].y = buff[2].y + rayon * sin(angle);
      buff[0] = buff[2];
      angle +=  M_PI / (rayon * 10);
      tekline(pix, buff, color);
    }
  angle = 0;
  while (angle <= M_PI / 2)
    {
      buff[1].x = buff[2].x + rayon * cos(angle);
      buff[1].y = buff[2].y + rayon * sin(angle);
      buff[0] = buff[2];
      angle +=  M_PI / (rayon * 10);
      tekline(pix, buff, color);
    }
}

void			tekcercle(t_bunny_pixelarray *pix, t_bunny_position *pos,
				  int rayon, t_color *color)
{
  t_bunny_position	buff[3];
  float			angle;

  buff[0] = *pos;
  buff[2] = buff[0];
  angle = 0;
  while (angle <= M_PI / 2)
    {
      buff[1].x = buff[2].x + rayon * cos(angle);
      buff[1].y = buff[2].y - rayon * sin(angle);
      buff[0] = buff[2];
      angle +=  M_PI / (rayon * 10);
      tekline(pix, buff, color);
    }
  angle = 0;
  while (angle <= M_PI / 2)
    {
      buff[1].x = buff[2].x - rayon * cos(angle);
      buff[1].y = buff[2].y - rayon * sin(angle);
      buff[0] = buff[2];
      angle +=  M_PI / (rayon * 10);
      tekline(pix, buff, color);
    }
  buff[0] = buff[2];
  tekcercle_2(pix, buff, rayon, color);
}
