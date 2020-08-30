/*
** tekpixel.c for tekpixel.c in /home/Rayan/Info/gfx_raytracer1
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sat Mar  5 13:35:31 2016 AKKACHE Kaci
** Last update Sun Mar 13 19:38:10 2016 AKKACHE Kaci
*/

#include <lapin.h>

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
