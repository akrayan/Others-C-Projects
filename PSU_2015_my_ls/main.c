/*
** main.c for main.c in /home/Rayan/Systeme Unix/PSU_2015_my_ls
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Nov 29 19:14:39 2015 AKKACHE Kaci
** Last update Sun Nov 29 20:31:16 2015 AKKACHE Kaci
*/

#include <stdlib.h>

int	main (int ac, char **av)
{
  int	i;
  char	*str;

  if (ac == 1)
    my_ls(".");
  else if (ac > 1)
    {
      i = 1;
      while (av[i] != NULL)
	{
	  if (av[i][0] != '-')
	    str = av[i];
	  i = i + 1;
	}
      my_ls(str);
    }
  else
    my_putchar('\n');
}
