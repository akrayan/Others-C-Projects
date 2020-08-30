/*
** my_show_wordtab.c for my_show_wordtab.c in /home/Rayan/Piscine_C_J08
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Thu Oct  8 18:01:12 2015 AKKACHE Kaci
** Last update Thu Oct  8 18:57:05 2015 AKKACHE Kaci
*/

#include <stdlib.h>

int	my_show_wordtab(char **tab);
{
  int i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i = i + 1;
    }
}
