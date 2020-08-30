/*
** my.h for main.c in /home/assaba_m/rendu/Infographie/gfx_colle_fantasy5
** 
** Made by Moshe Assaban
** Login   <assaba_m@epitech.net>
** 
** Started on  Thu Jan  7 20:40:08 2016 Moshe Assaban
** Last update Thu Jan  7 21:13:04 2016 Moshe Assaban
*/

#ifndef MY_H_
# define MY_H_

#include <lapin.h>

/* In ./tekpixel.c */
void			tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos, t_color *color);
/* In ./my_getnbr.c */
int			my_getnbr(char *str);
/* In ./main.c */
void			whirlpool(t_bunny_pixelarray *pix,
	       const t_bunny_position *pos,
	       double ratio,
	       int depth);
void			fill_it(t_bunny_pixelarray *pix, t_color *color);
t_bunny_response	key(t_bunny_event_state state,
		     t_bunny_keysym key, void *data);
int			main(int ac, char **av);
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
