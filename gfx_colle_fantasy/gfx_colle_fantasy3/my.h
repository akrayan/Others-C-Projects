/*
** my.h for my.h in /home/assaba_m/rendu/Infographie/gfx_colle_fantasy3
** 
** Made by Moshe Assaban
** Login   <assaba_m@epitech.net>
** 
** Started on  Thu Jan  7 18:45:55 2016 Moshe Assaban
** Last update Thu Jan  7 18:46:32 2016 Moshe Assaban
*/

#ifndef MY_H_
# define MY_H_

#include <lapin.h>
#include <math.h>


/* In ./tekpixel.c */
void			tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos, t_color *color);
/* In ./main.c */
void			fill_it(t_bunny_pixelarray *pix, t_color *color);
int			main();
/* In ./my_set_cercle.c */
void			tekcercle_2(t_bunny_pixelarray *pix, t_bunny_position *pos,
				  int rayon, t_color *color);
void			tekcercle(t_bunny_pixelarray *pix, t_bunny_position *pos,
				  int rayon, t_color *color);
/* In ./my_set_line2.c */
void			my_set_line_inf_inf(t_bunny_pixelarray *pix, t_bunny_position *pos,
			    t_color *color);
/* In ./tekline.c */
void			my_set_line_sup_sup(t_bunny_pixelarray *pix, t_bunny_position *pos,
			    t_color *color);
void			my_set_line_sup_inf(t_bunny_pixelarray *pix, t_bunny_position *pos,
			    t_color *color);
void			my_set_line_inf_sup(t_bunny_pixelarray *pix, t_bunny_position *pos,
			    t_color *color);
void			my_set_line_diago(t_bunny_pixelarray *pix, t_bunny_position *pos,
			  t_color *color);
void			tekline(t_bunny_pixelarray *pix, t_bunny_position *pos, t_color *color);

#endif /* !MY_H_ */
