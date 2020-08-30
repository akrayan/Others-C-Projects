/*
** list.c for list in /home/billel/encode/bilbil/src
** 
** Made by BIllel
** Login   <billel.mouhoub@epitech.eu>
** 
** Started on  Sat Nov 25 21:36:59 2017 BIllel
** Last update Sun Nov 26 04:51:13 2017 BIllel
*/

#include "list.h"

t_elem	*add_elem(t_elem *list, char *path, int size, char *dir, char type)
{
  t_elem *new = malloc(sizeof(t_elem));
  t_elem *p;
  
  new->path = path;
  new->size = size;
  new->dir = strdup(dir);
  new->type = type;
  new->next = NULL;
  if (list == NULL)
    return (new);
  p = list;
  while (p->next != NULL)
    p = p->next;
  p->next = new;
  return (list);
}

void	free_list(t_elem *list)
{
  t_elem *p;

  while (list != NULL)
    {
      p = list;
      list = list->next;
      p->next = NULL;
      free(p->path);
      free(p->dir);
      free(p);
    }
}

void	view_list(t_elem *list)
{
  while (list != NULL)
    {
      printf("dir = %s - path = %s - size = %d\n", list->dir, list->path, list->size);
      list = list->next;
    }
}
