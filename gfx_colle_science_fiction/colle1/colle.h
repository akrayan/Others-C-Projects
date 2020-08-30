/*
** colle.h for colle.h in /home/Rayan/gfx_colle_science_fiction/colle1
**
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
**
** Started on  Wed May 18 18:20:46 2016 AKKACHE Kaci
** Last update Wed May 18 18:56:29 2016 AKKACHE Kaci
*/

#ifndef COLLE_H_

# define COLLE_H_

# include <lapin.h>
# include <time.h>
# include <unistd.h>

typedef struct	s_s
{
  t_bunny_position	pos;
  t_bunny_position	p1;
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*fond;
  t_bunny_pixelarray	*scot;
  t_bunny_music		*m;
  t_color		color;
  int			vrai;
}		t_s;

void			put_img(t_bunny_pixelarray *p, t_bunny_pixelarray *i,
				t_bunny_position pos);

#endif /* COLLE_H_ */
