/*
** my_params_in_list.c for my_params_in_list.c in /home/Rayan/Piscine_C_J11/ex_01
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue Oct 13 19:16:12 2015 AKKACHE Kaci
** Last update Tue Oct 13 19:26:32 2015 AKKACHE Kaci
*/

#include <stdlib.h>
#include "../include/mylist.h"

int     my_put_in_list(struct s_list **list, void *data)
{
  struct s_list *elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (1);
  elem->data = data;
  elem->next = *list;
  *list = elem;
  return (0);
}

t_list  *my_params_in_list(int ac, char ** av)
{
  struct s_list *list;
  int i;

  i = 0;
  list = NULL;
  while (i < ac)
    {
      my_put_in_list(&list, av[i]);
      i = i + 1;
    }
  return (list);
}
