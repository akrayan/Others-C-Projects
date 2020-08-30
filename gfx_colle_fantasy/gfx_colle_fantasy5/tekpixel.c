/*
** tekpixel.c for tekpixel in /home/assaba_m/rendu/Infographie/gfx_colle_fantasy5
** 
** Made by Moshe Assaban
** Login   <assaba_m@epitech.net>
** 
** Started on  Thu Jan  7 21:03:08 2016 Moshe Assaban
** Last update Thu Jan  7 21:03:08 2016 Moshe Assaban
*/

#include "my.h"

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos, t_color *color)
{
  unsigned char *pixel;
  int		i;

  if ((pos->x <= pix->clipable.clip_width || pos->x >= 0)
      || (pos->y <= pix->clipable.clip_height || pos->y >= 0))
    {
      i = (pix->clipable.clip_width * pos->y *4) + (4 * pos->x);
      pixel = (unsigned char *)(pix->pixels);
      pixel[i] = color->argb[0];
      pixel[i + 1] =  color->argb[1];
      pixel[i + 2] =  color->argb[2];
      pixel[i + 3] =  color->argb[3];
    }
}
