/*
** my.h for my.h in /home/assaba_m/rendu/Infographie/gfx_colle_fantasy1
** 
** Made by Moshe Assaban
** Login   <assaba_m@epitech.net>
** 
** Started on  Thu Jan  7 16:47:07 2016 Moshe Assaban
** Last update Sun Mar 13 19:36:41 2016 AKKACHE Kaci
*/

#ifndef LIBLAP_H_
# define LIBLAP_H_

void	tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos, t_color *color);
void	fill_it(t_bunny_pixelarray *pix, t_color *color);
void	tekray(const t_bunny_position *screen_info,
	       int *x,
	       int *y,
	       int *z);

#endif
