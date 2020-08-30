/*
** tekpixel.c for tekpixel in /home/assaba_m/RENDU/SEM2/Infographie/gfx_scroller
**
** Made by assaba_m
** Login   <assaba_m@epitech.net>
**
** Started on  Fri Mar 18 20:01:44 2016 assaba_m
** Last update Wed May 18 19:28:32 2016 Afou Nacerdine
*/

#include "colle.h"

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
