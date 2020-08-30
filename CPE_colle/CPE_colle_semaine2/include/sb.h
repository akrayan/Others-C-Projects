/*
** sb.h for sb.h in /home/Rayan/Colle/CPE_colle_semaine2
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue May  3 18:32:10 2016 AKKACHE Kaci
** Last update Tue May  3 20:03:24 2016 AKKACHE Kaci
*/

#ifndef SB_H
 #define SB_H

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct	s_coord
{
  int		x;
  int		y;
}		t_coord;

typedef struct	s_list
{
  struct s_list	*next;
  struct s_list	*last;

  t_coord	c;
}		t_list;

char	**init_map(char **tab);
t_list	*add_elem(t_list *l, int x, int y);
t_list	*sup_elem(t_list *l);

#endif
