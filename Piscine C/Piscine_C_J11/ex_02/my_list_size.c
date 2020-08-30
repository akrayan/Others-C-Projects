/*
** my_list_size.c for my_list_size.c in /home/Rayan/Piscine_C_J11
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue Oct 13 19:19:13 2015 AKKACHE Kaci
** Last update Tue Oct 13 19:19:25 2015 AKKACHE Kaci
*/

#include "../include/mylist.h"
#include <stdlib.h>

int     my_list_size(t_list *begin)
{
  int   i;

  i = 0;
  while (begin != NULL)
    {
      begin = begin->next;
      i = i + 1;
    }
  return(i);
}
