/*
** main.c for main in /home/assaba_m/rendu/Infographie/gfx_colle_fantasy1
** 
** Made by Moshe Assaban
** Login   <assaba_m@epitech.net>
** 
** Started on  Thu Jan  7 16:28:01 2016 Moshe Assaban
** Last update Thu Jan  7 17:09:51 2016 Moshe Assaban
*/

#include <lapin.h>
#include "my.h"

int			main(int ac, char **av)
{
  t_bunny_window        *win;
  t_bunny_pixelarray    *pix;
  t_bunny_position	pos;

  if (ac == 1)
    return (0);
  pix = bunny_load_pixelarray(av[1]);
  win = bunny_start(852, 859, false, "fantasy1");
  pos.x = 0;
  pos.y = 0;
  bunny_blit(&win->buffer, &pix->clipable, &pos);
  bunny_display(win);
  bunny_loop(win, 150, win);
  bunny_stop(win);
  return (0);
}
