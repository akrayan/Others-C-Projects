/*
** flammes.c for flammes.c in /home/Rayan/Info/gfx_incendie
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sat Dec  5 12:08:33 2015 AKKACHE Kaci
** Last update Sun Dec  6 19:13:19 2015 AKKACHE Kaci
*/

#include "./include/my.h"
#include "./include/lapin.h"
#include "./include/lapin_enum.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int	color(int c)
{
  unsigned int	color;

  if (c <= 0)
    color = BLACK;
  else if (c <= 32)
    color =  (c * 7) << (RED_CMP * 8);
  else if (c <= 64)
    color = 255 << (RED_CMP * 8) | ((c - 32) * 7) << (GREEN_CMP * 8);
  else if (c <= 96)
    color = 255 << (RED_CMP * 8) | 255 << (GREEN_CMP * 8) | ((c - 64) * 7) << (BLUE_CMP * 8);
  else
    color = WHITE;
  return (color);
}

int	flammes(t_bunny_pixelarray *pix)
{
  int	t[pix->clipable.clip_height][pix->clipable.clip_width];
  int	i;
  int	j;
  int	k;
  double	f;
  t_bunny_position      pos;

  f = 0;
  j = 0;
  k = 0;
  srand(time(NULL));
  while (j < pix->clipable.clip_height)
    {
      i = 0;
      while (i < pix->clipable.clip_width)
	{
	  t[j][i] = (rand() % 128);
	  i = i + 1;
	}
      j = j + 1;
    }
  k = 0;
  while (k < 3)
    {
      j = 2;
      while (j < pix->clipable.clip_height - 2)
	{
	  i = 2;
	  while (i < pix->clipable.clip_width - 2)
	    {
	      t[j][i] = ((t[j-1][i-1] + t[j-1][i] + t[j-1][i+1] + t[j][i-1] + t[j][i+1] + t[j+1][i-1] + t[j+1][i] + t[j+1][i+1] + t[j-1][i-2] + t[j-1][i + 2] + t[j][i+2] + t[j][i-2] + t[j+1][i-2] + t[j+1][i+2] + t[j-2][i-2] + t[j-2][i-1] + t[j-2][i] + t[j-2][i+1] + t[j-2][i+2] + t[j+2][i-2] + t[j+2][i-1] + t[j+2][i] + t[j+2][i+1] + t[j+2][i+2]) / 24);
	      i = i + 1;
	    }
	  j = j + 1;
	}
      k = k + 1;
    }
   j = 0;
  while (j < pix->clipable.clip_height)
    {
      i = 0;
      while (i < pix->clipable.clip_width)
	{
	  t[j][i] = t[j][i] - f;
	  i = i + 1;
	}
      f = f + 0.15;
      j = j + 1;
    }
  pos.y = 0;
  while (j >= 0)
    {
      i = 0;
      pos.x = 0;
      while (i < pix->clipable.clip_width)
        {
          my_set_pixel(pix, pos, color(t[j][i]));
          pos.x = pos.x + 1;
          i = i + 1;
        }
      pos.y = pos.y + 1;
      j = j - 1;
    }
}
