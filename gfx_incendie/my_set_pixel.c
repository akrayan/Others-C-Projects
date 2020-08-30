/*
** my_set_pixel.c for my_set_pixel.c in /home/Rayan/Info/fdf1
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Mon Nov 23 14:42:25 2015 AKKACHE Kaci
** Last update Sat Dec  5 01:25:17 2015 AKKACHE Kaci
*/

#include <lapin.h>
#include <stdio.h>

void	my_set_pixel(t_bunny_pixelarray *pix, t_bunny_position pos, unsigned int color)
{
  unsigned char *tmp;
  int		poq;

  tmp = (unsigned char*)&color;
  poq = (pix->clipable.clip_width * 4 * pos.y) + (pos.x * 4);
  ((unsigned char*) (pix->pixels))[poq] = tmp[0];
  ((unsigned char*) (pix->pixels))[poq + 1] = tmp[1];
  ((unsigned char*) (pix->pixels))[poq + 2] = tmp[2];
  ((unsigned char*) (pix->pixels))[poq + 3] = tmp[3];
}
