/*
** fill_it.c for fill_it.c in /home/afou_n/Inforgraphie/rush/gfx_scroller/step_1
** 
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
** 
** Started on  Sat Mar 19 21:38:22 2016 Afou Nacerdine
** Last update Tue May 24 04:55:30 2016 AKKACHE Kaci
*/

#include "./include/rt.h"

t_bunny_pixelarray	*d_pix(t_bunny_pixelarray *p1)
{
  t_bunny_pixelarray	*p2;
  unsigned int		*k;
  unsigned int		*p;
  int			i;

  if (p1 != NULL)
    {
      p2 = bunny_new_pixelarray(p1->clipable.clip_width,
				p1->clipable.clip_height);
      k = p1->pixels;
      p = p2->pixels;
      i = - 1;
      while (++i < p1->clipable.clip_width * p1->clipable.clip_height)
	p[i] = k[i];
      return (p2);
    }
  return (NULL);
}

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
