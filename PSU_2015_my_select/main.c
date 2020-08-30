/*
** main.c for main.c in /home/Rayan/Systeme_Unix/PSU_2015_my_select
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Dec 13 17:15:59 2015 AKKACHE Kaci
** Last update Sun Dec 13 17:24:43 2015 AKKACHE Kaci
*/

#include <stdlib.h>
#include "my_select.h"

int	main(int ac, char **av)
{
  t_dbl	list;
  char	*s;

  if (ac > 1)
    {
      getlist(&list, av);
      s = my_select(&list, av);
      if (s != NULL)
	{
	  my_putstr(s);
	  my_putchar('\n');
	}
    }
}
