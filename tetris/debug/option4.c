/*
** option4.c for  in /home/axel/rendu/PSU/PSU_2015_tetris
**
** Made by Axel Proust
** Login   <proust_c@epitech.net>
**
** Started on  Tue Mar  8 13:40:51 2016 Axel Proust
** Last update Sun Mar 20 14:39:07 2016 Axel Proust
*/

#include "../tetris.h"
#include <curses.h>
#include <term.h>

int             start_level(t_opt *opt)
{
  static int    n;

  if (n != 0)
    return (-1);
  n++;
  opt->level = my_getnbr(opt->arg);
}

int             my_key_left(t_opt *opt)
{
  static int    n;

  if (n != 0)
    return (-1);
  n++;
  opt->left = my_strdup(opt->arg);
  return (0);
}

int             my_key_right(t_opt *opt)
{
  static int    n;

  if (n != 0)
    return (-1);
  n++;
  opt->right = my_strdup(opt->arg);
  return (0);
}

int             key_turn(t_opt *opt)
{
  static int    n;

  if (n != 0)
    return (-1);
  n++;
  opt->turn = my_strdup(opt->arg);
  return (0);
}

int             key_drop(t_opt *opt)
{
  static int    n;

  if (n != 0)
    return (-1);
  n++;
  opt->drop = my_strdup(opt->arg);
}

int		set_opt(t_opt *opt)
{
  opt->left = tigetstr("kcub1");
  opt->right = tigetstr("kcuf1");
  opt->turn = tigetstr("kcuu1");
  opt->drop = tigetstr("kcud1");
  opt->quit = my_strdup("q");
  opt->pause = my_strdup(" ");
  opt->map_w = 10;
  opt->map_h = 20;
  opt->level = 1;
  opt->next = my_strdup("Yes");
}
