/*
** rt.h for rt.h in /home/Rayan/Info/gfx_raytracer1
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sat Mar  5 13:41:56 2016 AKKACHE Kaci
** Last update Fri May  6 08:43:57 2016 AKKACHE Kaci
*/

#ifndef RT_H_
 #define RT_H_

#include <lapin.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include "liblap.h"
#include "my.h"

typedef struct		s_co
{
  double       		x;
  double		y;
  double       		z;
}			t_co;

typedef struct		s_ray
{
  int			x;
  int			y;
  int			z;
}			t_ray;

typedef struct		s_init
{
  t_bunny_window        *win;
  t_bunny_pixelarray    *pix;
  t_color		color;
  t_bunny_position	pos;
  t_co			o;
}			t_init;

typedef struct		s_calc
{
  double		a;
  double		b;
  double		c;
  int			r;
  double		d;
  double		k;
  double		s1;
  double		s2;
}			t_calc;

void	trace_plan(t_bunny_pixelarray *pix, t_bunny_position pos,
		   t_co o, t_ray v);
t_init	init(t_init i);
void	aff(t_init i);
t_color	shade_sphere(t_co o, t_ray v, t_color color, double k);
t_calc	trace_sphere2(t_calc calc);
void	trace_sphere(t_bunny_pixelarray *pix, t_bunny_position pos,
		     t_co o, t_ray v);
#endif
