/*
** main.c for  in /home/axel/rendu/PSU_2015_tetris
**
** Made by Axel Proust
** Login   <proust_c@epitech.net>
**
** Started on  Sun Mar 20 11:35:35 2016 Axel Proust
** Last update Tue Mar 22 01:34:45 2016 AKKACHE Kaci
*/

#include "tetris.h"
#include <sys/ioctl.h>
#include <curses.h>
//#include <term.h>
#include <string.h>
//#include <termios.h>

/*int		main(int ac, char **av, char **env)
{
  int		i;
  t_t		tab;
  t_te		te;
  t_opt		*opt;
  int		c;
  int		err;
  char		**tabb;

  if ((opt = malloc(sizeof(t_opt))) == NULL)
    return (-1);
  check_help(av, opt);
  tabb = copy_tableau(av);
  if (check_av(tabb) == -1)
    {
      show_help(opt, av);
      return (-1);
    }
  if (env == NULL)
    return (-1);
  if ((c = setupterm(NULL, 1, &err)) == ERR)
    return (-1);
  if (check_d(av) == -1)
    exit (0);
  set_opt(opt);
  i = 0;
  if (ac >= 2)
    {
      if (gestion_opt(ac, av,opt) == -1)
	{
	  show_help(opt, av);
	  return (0);
	}
    }
    }*/
