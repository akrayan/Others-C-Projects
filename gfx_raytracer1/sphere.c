/*
** sphere.c for sphere.c in /home/Rayan/Info/gfx_raytracer1
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Mar 13 19:59:03 2016 AKKACHE Kaci
** Last update Mon May  9 00:15:49 2016 AKKACHE Kaci
*/

#include "./include/rt.h"

t_color			shade_sphere(t_co o, t_ray v, t_color color, double k)
{
  t_co			vn;
  t_co			vl;
  double		cosa;

  vn.x = (v.x * k);
  vn.y = (v.y * k);
  vn.z = (v.z * k);
  vl.x = 100 - (v.x * k);
  vl.y = 300 - (v.y * k);
  vl.z = 200 - ((v.z * k) - o.z);
  cosa = (vn.x * vl.x + vn.y * vl.y + vn.z * vl.z) /
  ((sqrt(pow(vn.x, 2) + pow(vn.y, 2) + pow(vn.z, 2)) *
  (sqrt(pow(vl.x, 2) + pow(vl.y, 2) + pow(vl.z, 2)))));
  if (cosa < 0.1 || cosa > 1 || (255 * cosa * 0.90) < 50)
    {
      color.argb[0] = 50;
      color.argb[1] = 0;
      color.argb[2] = 0;
      return (color);
    }
  color.argb[0] = (255 * cosa * 0.90) + (0.5 * 0 * cosa);
  color.argb[1] = 0;
  color.argb[2] = 0;
  return (color);
}

t_calc			trace_sphere2(t_calc calc)
{
  calc.s1 =  (- calc.b - sqrt(calc.d)) / (2 * calc.a);
  calc.s2 =  (- calc.b + sqrt(calc.d)) / (2 * calc.a);
  if (calc.s1 > 0 && calc.s1 < calc.s2)
    calc.k = calc.s1;
  else if (calc.s2 > 0 && calc.s2 < calc.s1)
    calc.k = calc.s2;
  return (calc);
}

void			trace_sphere(t_bunny_pixelarray *pix, t_bunny_position pos,
				     t_co o, t_ray v)
{
  t_calc		calc;
  t_color		color;

  calc.r = 100;
  calc.s2 = -1;
  calc.a = pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2);
  calc.b = 2 * ((o.x) * v.x + (o.y) * v.y + (o.z + 0) * v.z);
  calc.c = pow((o.x), 2) + pow((o.y), 2) + pow((o.z + 0), 2) - pow(calc.r, 2);
  calc.d = pow(calc.b, 2) - (4 * calc.a * calc.c);
  calc.k = -1;
  if (calc.d >= 0)
    {
      if (calc.d == 0)
	calc.k = - (calc.b) / (2 * calc.a);
      else
	calc = trace_sphere2(calc);
      if (calc.k > 0)
	{
	  color = shade_sphere(o, v, color, calc.k);
	  tekpixel(pix, &pos, &color);
	}
    }
}
