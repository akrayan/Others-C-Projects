/*
** main.c for main.c in /home/Rayan/CPE_colle_semaine1
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue Apr 26 18:58:29 2016 AKKACHE Kaci
** Last update Tue Apr 26 22:00:58 2016 AKKACHE Kaci
*/

#include "./include/maze.h"

int	main(int ac, char **av)
{
  char	*s;

  if (ac > 1)
    {
      s = read_all(s, av[1]);
      my_putstr(s);
    }
  return (0);
}
