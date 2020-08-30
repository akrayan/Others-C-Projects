/*
** gm.h for gm.h in /home/Rayan/Colle
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue May 10 18:23:02 2016 AKKACHE Kaci
** Last update Tue May 10 21:51:10 2016 AKKACHE Kaci
*/

#ifndef GM_H
 #define GM_H

#include	<lapin.h>

typedef struct		s_s
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*img;
  t_bunny_pixelarray	*font;
  t_bunny_position	pos;
  t_bunny_position	t;
  t_bunny_position	p;
  t_bunny_position	p1;
  t_bunny_position	p2;
  t_color		color;
  int			score;
  int			vie;
  int			time;
  int			time2;
  int			a;
  char			**m;
}			t_s;

#endif