/*
** main.c for main.c in /home/assaba_m/rendu/Infographie/gfx_colle_fantasy5
** 
** Made by Moshe Assaban
** Login   <assaba_m@epitech.net>
** 
** Started on  Thu Jan  7 20:39:43 2016 Moshe Assaban
** Last update Thu Jan  7 21:17:41 2016 Moshe Assaban
*/

#include <lapin.h>
#include "my.h"

void	whirlpool(t_bunny_pixelarray *pix,
	       const t_bunny_position *pos,
	       double ratio,
	       int depth)
{
  t_bunny_position	new[3];
  t_bunny_position	tmp[2];
  t_color		color;

  color.full = YELLOW;
  if (depth > 0)
    {
      tmp[0] = pos[0];
      tmp[1] = pos[2];
      new[0].x = ((pos[1].x - pos[0].x) * ratio / 100) + pos[0].x;
      new[0].y = ((pos[1].y - pos[0].y) * ratio / 100) + pos[0].y;
      new[1].x = ((pos[2].x - pos[1].x) * ratio / 100) + pos[1].x;
      new[1].y = ((pos[2].y - pos[1].y) * ratio / 100) + pos[1].y;
      new[2].x = ((tmp[0].x - pos[2].x) * ratio / 100) + pos[2].x;
      new[2].y = ((tmp[0].y - pos[2].y) * ratio / 100) + pos[2].y;
      tekline(pix, (t_bunny_position *)&pos[0], &color);
      tekline(pix, (t_bunny_position *)&pos[1], &color);
      tekline(pix, &tmp[0], &color);
      whirlpool(pix, new, ratio, depth - 1);
    }
}

void			fill_it(t_bunny_pixelarray *pix, t_color *color)
{
  unsigned char		*pixel;
  int			i;

  i = 0;
  pixel = (unsigned char *)(pix->pixels);
  while (i < (pix->clipable.clip_width * pix->clipable.clip_height * 4))
    {
      pixel[i] = color->argb[0];
      pixel[i + 1] = color->argb[1];
      pixel[i + 2] = color->argb[2];
      pixel[i + 3] = color->argb[3];
      i = i + 4;
    }
}
t_bunny_response key(t_bunny_event_state state,
		     t_bunny_keysym key, void *data)
{
  (void)state;
  (void)data;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

void	triangle_coord(t_bunny_position *pos)
{
  pos[0].x = 600;
  pos[0].y = 700;
  pos[1].x = 300;
  pos[1].y = 700;
  pos[2].x = 450;
  pos[2].y = 333;
  pos[3].x = 0;
  pos[3].y = 0;
}

int	main(int ac, char **av)
{
  t_bunny_position      pos[4];
  t_bunny_window        *win;
  t_bunny_pixelarray	*pix;
  t_color		color;
  double		ratio;
  int			depth;

  if (ac == 1)
    return (0);
  ratio = my_getnbr(av[1]);
  depth = my_getnbr(av[2]);
  win = bunny_start(1000, 1000, false, "whirlpool");
  pix = bunny_new_pixelarray(1000, 1000);
  color.full = BLACK;
  fill_it(pix, &color);
  triangle_coord(pos);
  whirlpool(pix, (const t_bunny_position *)pos, ratio, depth);
  bunny_blit(&win->buffer, &pix->clipable, &pos[3]);
  bunny_display(win);
  bunny_set_key_response(key);
  bunny_loop(win, 150, win);
  bunny_stop(win);
  return (0);
}
