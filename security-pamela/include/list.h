/*
** list.h for INLCUDE in /home/billel/encode/bilbil
** 
** Made by BIllel
** Login   <billel.mouhoub@epitech.eu>
** 
** Started on  Sat Nov 25 21:38:32 2017 BIllel
** Last update Sun Nov 26 04:50:03 2017 BIllel
*/

#ifndef LIST_H
# define LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

typedef struct	s_elem
{
  char		*path;
  int		size;
  char		*dir;
  char		type;
  struct s_elem	*next;
}		t_elem;

/* LIST_H_ */
t_elem	*add_elem(t_elem *list, char *path, int size, char *dir, char type);
void	free_list(t_elem *list);
void	view_list(t_elem *list);

#endif /* !LIST_H_ */
