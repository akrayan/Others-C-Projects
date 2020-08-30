/*
** option2.c for  in /home/axel/rendu/PSU/PSU_2015_tetris
**
** Made by Axel Proust
** Login   <proust_c@epitech.net>
**
** Started on  Mon Mar  7 11:19:08 2016 Axel Proust
** Last update Sun Mar 20 19:58:00 2016 Axel Proust
*/

#include "../tetris.h"

int             check_help(char **av, t_opt *opt)
{
  int           i;

  i = -1;
  while (++i < tab_len(av))
    if (strcmp(av[i], "--help") == 0)
      {
	show_help(opt, av);
	exit (0);
      }
  return (0);
}


int		options(char *str, t_opt *opt, char **av)
{
  if (strcmp(str, "--help") == 0)
    {
      show_help(opt, av);
      exit (0);
    }
  else if (strcmp(str, "-d") == 0)
    {
      debug(opt);
      return (0);
    }
  else if ((strcmp(str, "-w") == 0) || (strcmp(str, "--without-next") == 0))
    {
      hide_next(opt);
      return (0);
    }
  return (-1);
}

int		show_help(t_opt *opt, char **av)
{
  printf("Usage: %s [options]\nOptions:\n", av[0]);
  printf("  --help\t\t Display this help\n");
  printf("  -l --level={num}\t Start Tetris at level num\n");
  printf("  -kl --key-left={K}\t Move tetrimino on LEFT with key K\n");
  printf("  -kr --key-right={K}\t Move tetrimino on RIGHT with key K\n");
  printf("  -kt --key-turn={K}\t Turn tetrimino with key K\n");
  printf("  -kd --key-drop={K}\t Set default DROP on key K\n");
  printf("  -kq --key-quit={K}\t Quit program when press key K\n");
  printf("  -kp --key-pause={K}\t Pause and restart game when press key K");
  printf("\n  --map-size={row,col}\t Set game size at row, col\n");
  printf("  -w --without-next\t Hide next tetrimino\n");
  printf("  -d --debug\t\t Debug mode\n");
}
