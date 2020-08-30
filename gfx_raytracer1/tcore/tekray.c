/*
** tekray.c for tekray.c in /home/Rayan/Info/gfx_raytracer1
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Mar 13 19:12:21 2016 AKKACHE Kaci
** Last update Sun Mar 13 19:38:24 2016 AKKACHE Kaci
*/

#include <lapin.h>

void	tekray(const t_bunny_position *screen_info,
	       int *x,
	       int *y,
	       int *z)
{
  *y = - (screen_info[1].y - (screen_info[0].y / 2));
  *x = screen_info[1].x - (screen_info[0].x / 2);
  *z = 100;
}
