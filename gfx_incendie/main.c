/*
** main.c for main.c in /home/Rayan/Info/gfx_incendie
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sat Dec  5 14:39:16 2015 AKKACHE Kaci
** Last update Sun Dec  6 19:20:38 2015 AKKACHE Kaci
*/

#include "./include/my.h"
#include "./include/lapin.h"
#include "./include/lapin_enum.h"

int     main()
{
  t_bunny_window        *win;
  t_bunny_pixelarray    *pix;
  t_bunny_position      pos;

  pos.x = 0;
  pos.y = 0;
  win = bunny_start(1000, 900, false, "test");
  pix = bunny_new_pixelarray(1000, 900);
  my_background(pix,BLACK);
  plasma(pix);
  bunny_blit(&win->buffer, &pix->clipable, &pos);
  bunny_display(win);
  bunny_loop(win, 200, win);
  bunny_stop(win);
}
