/*
** main.c for main.c in /home/Rayan/Prog Elem/CPE_2015_Pushswap
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Nov 22 14:52:51 2015 AKKACHE Kaci
** Last update Sun Nov 22 16:41:54 2015 AKKACHE Kaci
*/

#include <stdlib.h>
#include <stdio.h>
#include "./push_swap.h"

int	main(int ac, char **av)
{
  t_c	*ll;

  ll = malloc(sizeof(ll));
  if (ll == NULL)
    {
      my_putstr("Erreur malloc");
      return (0);
    }
  if (ac > 1)
    {
      ll->la = my_getlist(ll->la, av);
      ll->la = push_swap5(ll);
    }
  my_putchar('\n');
}
